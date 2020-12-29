/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "SSD1289.h"
#include "XPT2046.h"

/** @addtogroup STM32F4_Discovery_Peripheral_Examples
  * @{
  */

/** @addtogroup SysTick_Example
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief   Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
        system_stm32f4xx.c file
     */     
       
  /* Initialize Leds mounted on STM32F4-Discovery board */
  STM_EVAL_LEDInit(LED4);
  STM_EVAL_LEDInit(LED3);
  STM_EVAL_LEDInit(LED5);
  STM_EVAL_LEDInit(LED6);

  /* Turn on LED4 and LED5 */
  STM_EVAL_LEDOn(LED4);
  STM_EVAL_LEDOn(LED5);

  /* Setup SysTick Timer for 1 msec interrupts.
     ------------------------------------------
    1. The SysTick_Config() function is a CMSIS function which configure:
       - The SysTick Reload register with value passed as function parameter.
       - Configure the SysTick IRQ priority to the lowest value (0x0F).
       - Reset the SysTick Counter register.
       - Configure the SysTick Counter clock source to be Core Clock Source (HCLK).
       - Enable the SysTick Interrupt.
       - Start the SysTick Counter.
    
    2. You can change the SysTick Clock source to be HCLK_Div8 by calling the
       SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8) just after the
       SysTick_Config() function call. The SysTick_CLKSourceConfig() is defined
       inside the misc.c file.

    3. You can change the SysTick IRQ priority by calling the
       NVIC_SetPriority(SysTick_IRQn,...) just after the SysTick_Config() function 
       call. The NVIC_SetPriority() is defined inside the core_cm4.h file.

    4. To adjust the SysTick time base, use the following formula:
                            
         Reload Value = SysTick Counter Clock (Hz) x  Desired Time base (s)
    
       - Reload Value is the parameter to be passed for SysTick_Config() function
       - Reload Value should not exceed 0xFFFFFF
   */
  if (SysTick_Config(SystemCoreClock / 1000))
  { 
    /* Capture error */ 
    while (1);
  }

  // enable RNG module
  RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG, ENABLE);
  RNG_Cmd(ENABLE);
	
  SSD1289_Init();
  XPT2046_Init();

  SSD1289_CleanTextFont(10, 10, "STM32F4-Discovery board", Green, SYSTEM_8x16);
  SSD1289_CleanTextFont(10, 30, "Running @ 168 MHz", Green, SYSTEM_8x16);
  SSD1289_CleanTextFont(10, 50, "SSD1289 320x240 GLCD", Green, SYSTEM_8x16);
  SSD1289_CleanTextFont(10, 70, "XPT2046 Touchscreen", Green, SYSTEM_8x16);
  SSD1289_CleanTextFont(10, 130, "Demo routine...", Green, FONT8x8);
  SSD1289_CleanTextFont(10, 210, "(C) 2013 Fabio Angeletti", Green, FONT6x8);

  SSD1289_Backlight(0);
  Delay(500);
  SSD1289_Backlight(1);
  
  Delay(5000);

  TouchPanel_Calibrate();

  SSD1289_Clear(Black);

  /* Infinite loop */
  while (1) 
  {
    uint16_t x_a, x_b, y_a, y_b, color;

    // ASCII ART
    SSD1289_CleanTextFont(0,0,  "                                   V8  ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,8,  "                                 LR 4Y ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,16, "                7GEMMMRI        M7   M ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,24, "             7MU7      7M      M     U ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,32, "           7M7 2C177G    M    D775   7 ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,40, "          XT Y7      6   M    G GY    7", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,48, "         M77U   01       M   M  Y1    7", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,56, "        M 37  47     L  Z  C X         ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,64, "       8 7  97      T   P  Z7        7 ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,72, "       Q 3 Z       R   M   NZ        9 ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,80, "      M 6 7      Y7   E   X M        9 ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,88, "      1 5 W  7T47   7I   B  M       G  ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,96, "     A  7 A        N  7 M   Q      I7  ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,104,"     E 7  G      G7 7  M    J     76   ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,112,"     K C  71  6X7  A 0U    77     P    ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,120,"     T 7    7    I1 M      S     M     ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,128,"        I      1R TM            M      ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,136,"         D777AF  M7            M 7     ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,144,"               M9             N  7C    ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,152,"  WT7M2    7DM9              A2   R    ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,160,"      DMMMZ7     7   7      7F     M   ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,168,"                M   7      7K       N  ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,176,"   7            G   G     7E     M  77 ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,184,"   D  7        V   B     58       M7 H ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,192,"   M C7        M  L    7G          Q87Y", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,200,"   M M    XV67 E  K   7             IEM", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,208,"   DM          9 M                   7M", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,216,"    E          13I                     ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,224,"               UM                      ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,232,"               M                       ", Red,FONT8x8);  
    SSD1289_CleanTextFont(0,240,"               7                       ", Red,FONT8x8);        
    
		Delay(250);
    while(XPT2046_Press());
    SSD1289_Clear(Black);
    Delay(250);

    /* SIMPLE LINES
    for(;;)
    {
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      x_a=RNG_GetRandomNumber()%320;
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      x_b=RNG_GetRandomNumber()%320; 
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      y_a=RNG_GetRandomNumber()%240; 
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      y_b=RNG_GetRandomNumber()%240; 
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      color=RNG_GetRandomNumber(); 
      SSD1289_DrawLine(x_a, y_a, x_b, y_b, color);
    }
    
    SSD1289_Clear(Black);
    */

    // CIRCLEs
    for(;;)
    {
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      x_a=RNG_GetRandomNumber()%320;
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      x_b=RNG_GetRandomNumber()%64; 
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      y_a=RNG_GetRandomNumber()%240;
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      color=RNG_GetRandomNumber(); 
      SSD1289_FillCircle(x_a, y_a, x_b, color);
      Delay(10);
      if(!XPT2046_Press())
        break;
    }

    SSD1289_Clear(Black);
    Delay(250);

    // RECTs
    for(;;)
    {
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      x_a=RNG_GetRandomNumber()%320;
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      x_b=RNG_GetRandomNumber()%128; 
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      y_a=RNG_GetRandomNumber()%240; 
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      y_b=RNG_GetRandomNumber()%128; 
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      color=RNG_GetRandomNumber(); 
      SSD1289_FillRect(x_a, y_a, x_b, y_b, color);
      Delay(10);
      if(!XPT2046_Press())
        break;
    }   

    SSD1289_Clear(Black); 
    Delay(250);

    // WORDs
    for(;;)
    {
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      x_a=RNG_GetRandomNumber()%320;
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      x_b=RNG_GetRandomNumber()%128; 
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      y_a=RNG_GetRandomNumber()%240; 
      while(RNG_GetFlagStatus(RNG_FLAG_DRDY)== RESET);
      color=RNG_GetRandomNumber(); 
      SSD1289_CleanTextFont(x_a, y_a, "Hello, World!", color, x_b%4);
      Delay(10);
      if(!XPT2046_Press())
        break;
    }  

    SSD1289_Clear(Black);  
    Delay(250);
		
  }
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
