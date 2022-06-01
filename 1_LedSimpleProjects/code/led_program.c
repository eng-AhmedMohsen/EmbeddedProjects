/****************************************************************
 Author     : 	Ahmed Mohsen	                                     
 Layer      : 	HAL		                                         
 SWC        : 	LED			                                         
 Date       : 	24-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/

#include "led_interface.h"


/****************************************************************
 name             : LED_u8Init	                 
 description      : init led with default state                     
 parameter 1      : Copy_u8Port -> DIO_u8PORTA ..	         
 parameter 2      :	Copy_u8Pin  -> DIO_u8PIN1 ..	             
 parameter 3      : Copy_u8InitState  -> LED_STATE_ON .. LED_STATE_OFF
 Return           : u8 indication for error		             
****************************************************************/
u8 LED_u8Init(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8InitState)
{
	u8 Local_u8ErrorState = OK;
	
	/* in 2 modes sink or source the pin will be output */
	DIO_u8SetPinDirection(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_OUTPUT);
	
	switch(Copy_u8InitState)
	{
		case (LED_STATE_ON)	: Local_u8ErrorState = LED_u8TurnOn(Copy_u8Port, Copy_u8Pin); 	break;
		case (LED_STATE_OFF): Local_u8ErrorState = LED_u8TurnOff(Copy_u8Port, Copy_u8Pin); 	break;
		default				: Local_u8ErrorState = NOK;  											break;			
	}
	return Local_u8ErrorState;
}

/****************************************************************
 name             : LED_u8TurnOn	                 
 description      : turn led on 	                     
 parameter 1      : Copy_u8Port -> port name		         
 parameter 2      :	Copy_u8Pin  -> pin number	                
 Return           : u8 indication for error		             
****************************************************************/
u8 LED_u8TurnOn(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState = OK;
#if		LED_CONNECTION == LED_SOURCE_CONNECTION
	Local_u8ErrorState = DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);

#elif	LED_CONNECTION == LED_SINK_CONNECTION
	Local_u8ErrorState = DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);

#endif

	return Local_u8ErrorState;	
}

/****************************************************************
 name             : LED_u8TurnOff	                 
 description      : turn led off                     
 parameter 1      : Copy_u8Port -> port name		         
 parameter 2      :	Copy_u8Pin  -> pin number	             
 Return           : u8 indication for error		             
****************************************************************/
u8 LED_u8TurnOff(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState = OK;
#if		LED_CONNECTION == LED_SOURCE_CONNECTION
	Local_u8ErrorState = DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_LOW);

#elif	LED_CONNECTION == LED_SINK_CONNECTION
	Local_u8ErrorState = DIO_u8SetPinValue(Copy_u8Port,Copy_u8Pin,DIO_u8PIN_HIGH);

#endif

	return Local_u8ErrorState;
}

/****************************************************************
 name             : LED_u8Toggle	                 
 description      : toggle pin state	                     
 parameter 1      : Copy_u8Port -> port name		         
 parameter 2      :	Copy_u8Pin  -> pin number	                 
 Return           : u8 indication for error		             
****************************************************************/
u8 LED_u8Toggle(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	u8 Local_u8ErrorState = OK;

	Local_u8ErrorState = DIO_u8TogPinValue(Copy_u8Port,Copy_u8Pin);

	return Local_u8ErrorState;	
}