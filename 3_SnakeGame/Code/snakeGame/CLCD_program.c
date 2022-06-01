/****************************************************************
 Author     : 	Ahmed Mohsen	
 Layer      :   HAL                                                                              
 SWC        : 	charachter LCD		                                         
 Date       : 	24-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/

#include "CLCD_interface.h"


u8 CLCD_voidSendCommand(u8 Copy_u8Command)
{
	u8 Local_u8Error = OK;

#if 		CLCD_MODE == CLCD_MODE_8BIT
	/*1- Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*2- Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*3- Send the command to the LCD*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*4- Send the enable pulse to the LCD*/
	CLCD_u8SendPulse();

#elif		CLCD_MODE == CLCD_MODE_4BIT
	
	/* send high nibble */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command & 0xF0);
	
	/*1- Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*2- Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	CLCD_u8SendPulse();
	
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command << 4);
	
	CLCD_u8SendPulse();
#endif
	return Local_u8Error;
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
#if 		CLCD_MODE == CLCD_MODE_8BIT
	/*1- Set RS pin to high for Data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*2- Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*3- Send the Data to the LCD*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*4- Send the enable pulse to the LCD*/
	CLCD_u8SendPulse();
#elif			CLCD_MODE == CLCD_MODE_4BIT	

	/* send high nibble */
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data & 0xF0);
	
	/*1- Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*2- Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	CLCD_u8SendPulse();
	
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data << 4);
	
	CLCD_u8SendPulse();
	
#endif		
}

void CLCD_voidInit(void)
{
#if 		CLCD_MODE == CLCD_MODE_8BIT
	/* set data ports as outputs  */
	DIO_u8SetPortDirection(CLCD_DATA_PORT,DIO_u8PORT_OUTPUT);
	
	/* set control pins output */
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_OUTPUT);

	/*1- wait for more than 30 ms*/
	_delay_ms(40);

	/*2- Function set command: 2 lines, Font= 5x7*/
	CLCD_voidSendCommand(LCD_u8TwoLine);

	/*3- Display on off control: Display on, cursor off, blink cursor off*/
	CLCD_voidSendCommand(LCD_u8DisplayOnCursorOffBlinkOff);

	/*4- Display clear*/
	CLCD_voidSendCommand(LCD_u8ClearScreen);
	
	/* make right moving */
	CLCD_voidSendCommand(LCD_u8ShiftCursorRight);
	
#elif			CLCD_MODE == CLCD_MODE_4BIT
	/* set data ports as outputs  */
	DIO_u8SetPinDirection(CLCD_DATA_PORT,CLCD_DATA_PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT,CLCD_DATA_PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT,CLCD_DATA_PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT,CLCD_DATA_PIN3,DIO_u8PIN_OUTPUT);
	
	/* set control pins output */
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_OUTPUT);

	/*1- wait for more than 30 ms*/
	_delay_ms(40);

	/*2- Function set command: 2 lines, Font= 5x7*/
	CLCD_voidSendCommand(0x33);

	/*3- Display on off control: Display on, cursor off, blink cursor off*/
	CLCD_voidSendCommand(0x32);

	/*4- Display clear*/
	CLCD_voidSendCommand(0x28);
	CLCD_voidSendCommand(0x0E);
	CLCD_voidSendCommand(0x01);
	
	_delay_ms(3);
	/* make right moving */
	CLCD_voidSendCommand(0x06);
#endif	

}

void CLCD_voidSendString(const char* Copy_pchString)
{
	u8 Local_u8Counter=0;
	while(Copy_pchString[Local_u8Counter]!='\0')
	{
		CLCD_voidSendData(Copy_pchString[Local_u8Counter]);
		Local_u8Counter++;
	}
}

void CLCD_voidGotoXY(u8 Copy_u8Row, u8 Copy_u8Col)
{
	if(Copy_u8Row == 0)
	{
		CLCD_voidSendCommand(Copy_u8Col + 128);
	}
	else if(Copy_u8Row == 1)
	{
		CLCD_voidSendCommand(Copy_u8Col + 0x40 + 128);
	}
	_delay_ms(1);
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRamAddress,Local_u8Counter;

	/*1- calculate CGRAM address knowing that every pattern consumes 8 bytes*/
	Local_u8CGRamAddress = Copy_u8PatternNumber*8;

	/*2-Send SET CGRAM address command to LCD with setting bit6 ,clearing bit7*/
	CLCD_voidSendCommand(Local_u8CGRamAddress+64);

	/*3- write the pattern into CGRAM*/
	for(Local_u8Counter=0;Local_u8Counter<8;Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Counter]);
	}
	/*4- Back to the DDRAM to display the special pattern*/
	CLCD_voidGotoXY(Copy_u8XPos,Copy_u8YPos);

	/*5- Display the special pattern*/
	CLCD_voidSendData(Copy_u8PatternNumber);
}

u8 CLCD_u8SendPulse()
{
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	
	return OK;
}