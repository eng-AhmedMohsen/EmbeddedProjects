/*
 * snakeGame.c
 *
 * Created: 29-May-22 4:29:58 AM
 * Author : Ahmed
 */ 

#include "snakeGame.h"

u8 Local_u8SnakeHead[] = {
	0B00000,
	0B00100,
	0B00010,
	0B11111,
	0B00010,
	0B00100,
	0B00000,
	0B00000
	};
	
u8 Local_u8SnakeFood[] = 
{
	0B10001,
	0B01110,
	0B01010,
	0B01110,
	0B01010,
	0B01110,
	0B10001,
	0B00000	
};
int main(void)
{
	/* Game Init */
	snakeGame_voidInit();
	
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_INPUT);
	
	CLCD_voidWriteSpecialCharacter(Local_u8SnakeHead,0,0,0);
	// CLCD_voidWriteSpecialCharacter(Local_u8SnakeFood,1,0,6);
	//CLCD_voidSendCommand(0x1C);
	u8 Local_u8Val;
	
    while (1) 
    {
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN7,&Local_u8Val);
		if(Local_u8Val == DIO_u8PIN_LOW)
		{
			/* move down */
		}
		for(int i = 0; i < 20; i++)
		{
			CLCD_voidSendCommand(0x01);
			CLCD_voidGotoXY(0,i);
			CLCD_voidSendData(0);
			
			_delay_ms(500);
		}	
		
		// CLCD_voidSendCommand(0x1C);
		// _delay_ms(500);
		
		
		
		/* Display Game */
		//snakeGame_ScreenDisplay();
		
		/* Check Direction Change */
		//snakeGame_DirectionChange();
		
		/* check if Snake eat */
		//if(snakeGame_IsSnakeGetFood())
		//{
		//	snakeGame_SnakeGrow();
		//	snakeGame_RandomFood();
		//	snakeGame_UpdateDisplay();
		//}
		
		
		
		/**/
		
    }
}

