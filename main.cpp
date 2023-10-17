#include "servo.h"

int main(void)
{
	
	HAL_Init();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_TIM4_CLK_ENABLE();
		// PB11
		pinStruct_t servoPin = {GPIOB, GPIO_PIN_8};
		static Servo servo(servoPin,TIM4,GPIO_AF2_TIM4,TIM_CHANNEL_3);
	
	while(1){
		// turn servo: middle-left-middle-right
		servo.TurnShaft(SERVO_MIDDLEPOSITION);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_LEFTPOSITION);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_MIDDLEPOSITION);
		HAL_Delay(1000);
		servo.TurnShaft(SERVO_RIGHTPOSITION);
		HAL_Delay(1000);
	}
}	

extern "C" void SysTick_Handler(void){
	HAL_IncTick();
}
