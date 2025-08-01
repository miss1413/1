#include "stm32f10x.h"
#include "Delay.h"
#include "light.h"
#include "Key.h"
#include "LED.h"
#include "OLED.h"
#include "PWM.h"
#include "PWM1.h"
#include "PWM2.h"


uint8_t KeyNum;
uint8_t count=0;
int main(void)
{
//	light();
    Key_Init();
//	LED_Init();
	  OLED_Init();
	  PWM_Init();
    PWM1_Init();
//	PWM2_Init();
	
	
	
	//œ‘ æ
	
	OLED_ShowString(1, 1, "Freq:00000Hz");
	OLED_ShowString(2, 1, "Duty:00%");
	OLED_ShowString(3, 1, "Freq:00000Hz");
	OLED_ShowString(4, 1, "Duty:00%");
//  OLED_ShowString(5, 1, "Freq:00000Hz");
//	OLED_ShowString(6, 1, "Duty:00%");
	
	
	

	while(1)
	{
//		lightkz();
		KeyNum = Key_GetNum();
		if (KeyNum == 1)
		{
			count +=1;
		}
		if (KeyNum == 2)
		{
			count -=1;
		}
		PWM_SetCompare(count);
		PWM_SetPrescaler(72*count-1);
		PWM1_SetCompare(count);
		PWM1_SetPrescaler(72*count-1);
//	  PWM2_SetCompare1(count);
//		PWM2_SetPrescaler(72*count-1);
		
		//≤∂ªÒ
		
		OLED_ShowNum(1, 6, 1000/(count-1), 5);
		OLED_ShowNum(2, 6, count, 2);
		OLED_ShowNum(3, 6, 1000/(count-1), 5);
		OLED_ShowNum(4, 6, count, 2);
//		OLED_ShowNum(5, 6, , 5);
//		OLED_ShowNum(6, 6, count, 2);
	}
}
