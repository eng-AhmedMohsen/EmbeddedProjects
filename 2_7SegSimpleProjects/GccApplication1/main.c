/*
 * GccApplication1.c
 *
 * Created: 28-May-22 4:17:13 PM
 * Author : Ahmed
 */ 

#define F_CPU	8000000UL
#include "SevenSegment_interface.h"
#include "led_interface.h"
#include "util/delay.h"

int main(void)
{
    SevenSegment_u8Init(DIO_u8PORTA,SEVEN_SEGMENT_COMMON_CATHODE,SEG_NUMBER_0);
	SevenSegment_u8Init(DIO_u8PORTB,SEVEN_SEGMENT_COMMON_CATHODE,SEG_NUMBER_0);
	
	LED_u8Init(DIO_u8PORTC,DIO_u8PIN0,LED_STATE_OFF);
	LED_u8Init(DIO_u8PORTC,DIO_u8PIN1,LED_STATE_OFF);
	LED_u8Init(DIO_u8PORTC,DIO_u8PIN2,LED_STATE_OFF);
	
	u8 Local_u8Counter = 0;
	u8 Local_u8Flag = 0;
    while (1) 
    {
		LED_u8TurnOn(DIO_u8PORTC,DIO_u8PIN2);
		LED_u8TurnOff(DIO_u8PORTC,DIO_u8PIN0);
		
		for (Local_u8Counter = 0; Local_u8Counter <= 15; Local_u8Counter++)
		{
			SevenSegment_u8DisplayNumber(DIO_u8PORTA,SEVEN_SEGMENT_COMMON_CATHODE,Local_u8Counter % 10);
			SevenSegment_u8DisplayNumber(DIO_u8PORTB,SEVEN_SEGMENT_COMMON_CATHODE,Local_u8Counter / 10);
			_delay_ms(500);
		}
		
		LED_u8TurnOff(DIO_u8PORTC,DIO_u8PIN2);
		LED_u8TurnOn(DIO_u8PORTC,DIO_u8PIN1);
		for (Local_u8Counter = 0; Local_u8Counter <= 5; Local_u8Counter++)
		{
			SevenSegment_u8DisplayNumber(DIO_u8PORTA,SEVEN_SEGMENT_COMMON_CATHODE,Local_u8Counter % 10);
			SevenSegment_u8DisplayNumber(DIO_u8PORTB,SEVEN_SEGMENT_COMMON_CATHODE,Local_u8Counter / 10);
			_delay_ms(500);
		}
		

		LED_u8TurnOn(DIO_u8PORTC,DIO_u8PIN0);
		LED_u8TurnOff(DIO_u8PORTC,DIO_u8PIN1);
		for (Local_u8Counter = 0; Local_u8Counter <= 15; Local_u8Counter++)
		{
			SevenSegment_u8DisplayNumber(DIO_u8PORTA,SEVEN_SEGMENT_COMMON_CATHODE,Local_u8Counter % 10);
			SevenSegment_u8DisplayNumber(DIO_u8PORTB,SEVEN_SEGMENT_COMMON_CATHODE,Local_u8Counter / 10);
			_delay_ms(500);
		}
		
    }
}

