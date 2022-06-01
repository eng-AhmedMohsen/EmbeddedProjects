/*
 * code.c
 *
 * Created: 27-May-22 10:57:24 PM
 * Author : Ahmed
 */ 

#define F_CPU	8000000UL
#include "led_interface.h"
#include "util\delay.h"

/*
	all this projects use 8 led 
*/
void Led_voidShiftLeft();
void Led_voidShiftRight();
void Led_voidPingPong();
void Led_voidConverging();
void Led_voidDiverging();
void Led_voidDivergingConverging();
void Led_voidSnakeEffect();

int main(void)
{
	Led_voidSnakeEffect();
}

/*
	turn leds one after another with delay 250msec 
*/
void Led_voidShiftLeft()
{
	/* init Leds 0 -> 7 */
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		LED_u8Init(DIO_u8PORTA,Local_u8Counter,LED_STATE_OFF);
	}
	
	while (1)
	{
		u8 Local_u8Counter = 0;
		for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
		{
			LED_u8TurnOn(DIO_u8PORTA,Local_u8Counter);
			_delay_ms(250);
			LED_u8TurnOff(DIO_u8PORTA,Local_u8Counter);
		}
	}
}


/*
	turn leds one after another with delay 250msec 
*/
void Led_voidShiftRight()
{
	/* init Leds 0 -> 7 */
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		LED_u8Init(DIO_u8PORTA,Local_u8Counter,LED_STATE_OFF);
	}
	
	while (1)
	{
		/* use signed to prevent infinite loop */
		s8 Local_u8Counter = 0;
		for(Local_u8Counter = 7; Local_u8Counter >= 0; Local_u8Counter--)
		{
			LED_u8TurnOn(DIO_u8PORTA,Local_u8Counter);
			_delay_ms(250);
			LED_u8TurnOff(DIO_u8PORTA,Local_u8Counter);
		}
	}
}

void Led_voidPingPong()
{
	/* init Leds 0 -> 7 */
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		LED_u8Init(DIO_u8PORTA,Local_u8Counter,LED_STATE_OFF);
	}
	
	u8 Local_u8Flag = 0;
	while (1)
	{
		/* use signed to prevent infinite loop */
		s8 Local_u8CounterX = 0;
		s8 Local_u8CounterY = 7;
		
		if(Local_u8Flag == 0)
		{
			for(Local_u8CounterX = 0; Local_u8CounterX < 8; Local_u8CounterX++)
			{
			
				LED_u8TurnOn(DIO_u8PORTA,Local_u8CounterX);
				_delay_ms(250);
				LED_u8TurnOff(DIO_u8PORTA,Local_u8CounterX);
			}
			Local_u8Flag = 1;			
		}
		else
		{
			/* sub 2 steps to prevent merge two times of 2 For loop */
			for(Local_u8CounterY = 6; Local_u8CounterY > 0; Local_u8CounterY--)
			{
				LED_u8TurnOn(DIO_u8PORTA,Local_u8CounterY);
				_delay_ms(250);
				LED_u8TurnOff(DIO_u8PORTA,Local_u8CounterY);
			}
			Local_u8Flag = 0;			
		}

	}
}

void Led_voidConverging()
{
	/* init Leds 0 -> 7 */
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		LED_u8Init(DIO_u8PORTA,Local_u8Counter,LED_STATE_OFF);
	}
	
	u8 Local_u8Flag = 0;
	while (1)
	{
		/* use signed to prevent infinite loop */
		s8 Local_u8CounterX = 0;
		s8 Local_u8CounterY = 7;
		
		for(Local_u8CounterX = 0; Local_u8CounterX < 8; Local_u8CounterX++)
		{
			LED_u8TurnOn(DIO_u8PORTA,Local_u8CounterX);
			LED_u8TurnOn(DIO_u8PORTA,Local_u8CounterY);
			_delay_ms(250);
			Local_u8CounterY--;
		}
	}
}

void Led_voidDiverging()
{
	/* init Leds 0 -> 7 */
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		LED_u8Init(DIO_u8PORTA,Local_u8Counter,LED_STATE_OFF);
	}
	
	u8 Local_u8Flag = 0;
	while (1)
	{
		/* use signed to prevent infinite loop */
		s8 Local_u8CounterX = 3;
		s8 Local_u8CounterY = 4;
		
		/* to init functionality */
		DIO_u8SetPortValue(DIO_u8PORTA,0x00);
		_delay_ms(300);
		for(Local_u8CounterX = 3; Local_u8CounterX >= 0; Local_u8CounterX--)
		{
			LED_u8TurnOn(DIO_u8PORTA,Local_u8CounterX);
			LED_u8TurnOn(DIO_u8PORTA,Local_u8CounterY);
			_delay_ms(300);
			Local_u8CounterY++;
		}
	}
}


void Led_voidDivergingConverging()
{
	/* init Leds 0 -> 7 */
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		LED_u8Init(DIO_u8PORTA,Local_u8Counter,LED_STATE_OFF);
	}
	
	while (1)
	{
		/* use signed to prevent infinite loop */
		s8 Local_u8CounterX = 0;
		s8 Local_u8CounterY = 7;
		
		for(Local_u8CounterX = 0; Local_u8CounterX < 4; Local_u8CounterX++)
		{
			LED_u8TurnOn(DIO_u8PORTA,Local_u8CounterX);
			LED_u8TurnOn(DIO_u8PORTA,Local_u8CounterY);
			_delay_ms(250);
			Local_u8CounterY--;
		}
		
		Local_u8CounterY = 4;
		Local_u8CounterX = 3;
		for(Local_u8CounterX = 3; Local_u8CounterX >= 0; Local_u8CounterX--)
		{
			LED_u8TurnOff(DIO_u8PORTA,Local_u8CounterX);
			LED_u8TurnOff(DIO_u8PORTA,Local_u8CounterY);
			_delay_ms(250);
			Local_u8CounterY++;
		}
	}
}

void Led_voidSnakeEffect()
{
	/* init Leds 0 -> 7 */
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = 0; Local_u8Counter < 8; Local_u8Counter++)
	{
		LED_u8Init(DIO_u8PORTA,Local_u8Counter,LED_STATE_OFF);
	}
	
	while (1)
	{
		/* use signed to prevent infinite loop */
		s8 Local_u8CounterX = 0;
		s8 Local_u8CounterY = 7;
		
		for(Local_u8CounterX = 0; Local_u8CounterX < 8; Local_u8CounterX++)
		{
			LED_u8TurnOn(DIO_u8PORTA,Local_u8CounterX);
			_delay_ms(250);
		}
		
		for(Local_u8CounterY = 7; Local_u8CounterY >= 0; Local_u8CounterY--)
		{
			LED_u8TurnOff(DIO_u8PORTA,Local_u8CounterY);
			_delay_ms(250);
		}

	}
}