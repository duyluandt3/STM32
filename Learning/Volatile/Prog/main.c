
#define RAM_ADDRESS 0x20000000

volatile int u32CheckingVolatile = 0U;
int Dem = 0;

int main(void)
{
    while(1)
		{
		    u32CheckingVolatile = *(int *)RAM_ADDRESS;
		    Dem++;
		    if(u32CheckingVolatile != 0)
				{
				    break;
				}
		}
	  Dem = 100;
    return 0;
}