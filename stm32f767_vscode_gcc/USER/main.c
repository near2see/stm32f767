#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "tftlcd.h"
#include "sdram.h"
#include "ltdc.h"


void Delay(__IO uint32_t nCount);
void Delay(__IO uint32_t nCount)
{
while(nCount--){}
}

int main(void)
{
	Cache_Enable();                 				//打开L1-Cache
	HAL_Init();				        				//初始化HAL库
	Stm32_Clock_Init(432,25,2,9);   				//设置时钟,216Mhz
	delay_init(216);                //延时初始化
	uart_init(115200);
  	SDRAM_Init();                   //初始化SDRAM
  	TFTLCD_Init();                  //LCD初始化
	LCD_Clear(GREEN);
	
	POINT_COLOR=RED;
	LCD_ShowString(10,40,260,32,32,"hello"); 	
	LCD_ShowString(10,80,240,24,24,"VSCode + GNU test");

	LTDC_Fill(200,200,300,300,BLUE);
	while(1)
	{
	printf("hello\r\n");
	delay_ms(100);
	}
}
