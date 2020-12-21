/******************************************************************************
 * @file    	Main.c
 * @author  	Khanhpd
 * @version 	V1.0.0
 * @date    	15/01/2014
 * @brief   	
 ******************************************************************************/


/******************************************************************************
                                   INCLUDES					    			 
 ******************************************************************************/
#include "Main.h"
#include "stm32f10x.h"
#include "stm32f10x_adc.h"
#include <stdio.h>
#include "core_cm3.h"


/******************************************************************************
                                   GLOBAL VARIABLES					    			 
 ******************************************************************************/


/******************************************************************************
                                   GLOBAL FUNCTIONS					    			 
 ******************************************************************************/


/******************************************************************************
                                   DATA TYPE DEFINE					    			 
 ******************************************************************************/
#define ADC1_DR_Address    ((uint32_t)0x4001244C)

/******************************************************************************
                                   PRIVATE VARIABLES					    			 
 ******************************************************************************/
GPIO_InitTypeDef GPIO_InitStructure;
USART_InitTypeDef USART_InitStructure;
__IO uint16_t ADCConvertedValue;

/******************************************************************************
                                   LOCAL FUNCTIONS					    			 
 ******************************************************************************/
void Delay(__IO uint32_t nCount);
int fputc(int ch, FILE *f);
void UART_Configuration(void);
void ADC_Configuration(void);
void DMA_Configuration(void);

/*****************************************************************************/
/**
 * @brief	:  	Main function
 * @param	:  
 * @retval	:
 * @author	:	Khanhpd
 * @created	:	15/01/2014
 * @version	:
 * @reviewer:	
 */
int main() 
{ 
	float Temperature, ADC_Voltage;
	char c;
	
	UART_Configuration();
	ADC_Configuration();	
	DMA_Configuration();
	
	while(1)
	{
		Delay(10000000);
		
		ADC_Voltage = ADCConvertedValue * 3.3 / 4096;
		
		Temperature = (float)(1.43 - ADC_Voltage)/(4.3 / 1000) + 25.0;
		
		printf("\r\nTechEdu Center - ADC Value : %u, Temperature : %f",ADCConvertedValue,Temperature);					
		
	}
}	

/*****************************************************************************/
/**
 * @brief	:  	Delay function
 * @param	:  	Delay count
 * @retval	:	None
 * @author	:	Khanhpd
 * @created	:	15/01/2014
 * @version	:
 * @reviewer:	
 */
void UART_Configuration(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO | RCC_APB2Periph_USART1, ENABLE);

    /* Configure PA9 for USART Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure PA10 for USART Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
	
	/* USARTx configured as follow:
        - BaudRate = 9600 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  	*/
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	

	/* USART configuration */
	USART_Init(USART1, &USART_InitStructure);

	/* Enable USART */
	USART_Cmd(USART1, ENABLE);	
}
/*****************************************************************************/
/**
 * @brief	:  	Init DMA
 * @param	:  	Delay count
 * @retval	:	None
 * @author	:	Khanhpd
 * @created	:	15/01/2014
 * @version	:
 * @reviewer:	
 */	
void DMA_Configuration(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	
	/* DMA1 channel1 configuration ----------------------------------------------*/
	DMA_DeInit(DMA1_Channel1);
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)&ADCConvertedValue;
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = 1;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);

	/* Enable DMA1 channel1 */
	DMA_Cmd(DMA1_Channel1, ENABLE);
}
/*****************************************************************************/
/**
 * @brief	:  	Init ADC
 * @param	:  	Delay count
 * @retval	:	None
 * @author	:	Khanhpd
 * @created	:	15/01/2014
 * @version	:
 * @reviewer:	
 */	
void ADC_Configuration(void)
{
	ADC_InitTypeDef ADC_InitStructure;
	
	ADC_DeInit(ADC1);

    /* ADCCLK = PCLK2/4 */
    RCC_ADCCLKConfig(RCC_PCLK2_Div2);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_Init(ADC1, &ADC_InitStructure);
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_TempSensor, 1, ADC_SampleTime_41Cycles5);
	
	/* Enable ADC1 */
    ADC_Cmd(ADC1, ENABLE);
	
	/* Enable ADC1 DMA */
	ADC_DMACmd(ADC1, ENABLE);

    /* Enable ADC1 reset calibaration register */
    ADC_ResetCalibration(ADC1);

    /* Check the end of ADC1 reset calibration register */
    while(ADC_GetResetCalibrationStatus(ADC1));

    /* Start ADC1 calibaration */
    ADC_StartCalibration(ADC1);

    /* Check the end of ADC1 calibration */
    while(ADC_GetCalibrationStatus(ADC1));
	
	ADC_TempSensorVrefintCmd(ENABLE);

    /* Start ADC1 Software Conversion */
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);	
}

/*****************************************************************************/
/**
 * @brief	:  	Delay function
 * @param	:  	Delay count
 * @retval	:	None
 * @author	:	Khanhpd
 * @created	:	15/01/2014
 * @version	:
 * @reviewer:	
 */
void Delay(__IO uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

/*****************************************************************************/
/**
 * @brief	:  	Retargets the C library printf function to the USART.
 * @param	:  	Character to write
 * @retval	:	None
 * @author	:	Khanhpd
 * @created	:	15/01/2014
 * @version	:
 * @reviewer:	
 */
volatile int32_t ITM_RxBuffer;
int fgetc(FILE *f)
{
	return ITM_ReceiveChar();
}

int fputc(int ch, FILE *f)
{	
//	ITM_SendChar(ch);
//	
//	return(ch);
	
	USART_SendData(USART1, (uint8_t) ch);

	/* Loop until the end of transmission */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
	{}
		
	return(ch);
}

/********************************* END OF FILE *******************************/
