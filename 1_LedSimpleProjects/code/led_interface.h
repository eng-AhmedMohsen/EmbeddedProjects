/****************************************************************
 Author     : 	Ahmed Mohsen	                                     
 Layer      : 	HAL		                                         
 SWC        : 	LED			                                         
 Date       : 	24-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/
#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "led_interface.h"
#include "led_private.h"
#include "led_config.h"


/****************************************************************
 name             : LED_u8Init	                 
 description      : init led with defualt state                     
 parameter 1      : Copy_u8Port -> DIO_u8PORTA ..	         
 parameter 2      :	Copy_u8Pin  -> DIO_u8PIN1 ..	             
 parameter 3      : Copy_u8InitState  -> LED_STATE_ON .. LED_STATE_OFF
 Return           : u8 indication for error		             
****************************************************************/
u8 LED_u8Init(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8InitState);

/****************************************************************
 name             : LED_u8TurnOn	                 
 description      : turn led on 	                     
 parameter 1      : Copy_u8Port -> port name		         
 parameter 2      :	Copy_u8Pin  -> pin number	                
 Return           : u8 indication for error		             
****************************************************************/
u8 LED_u8TurnOn(u8 Copy_u8Port, u8 Copy_u8Pin);

/****************************************************************
 name             : LED_u8TurnOff	                 
 description      : turn led off                     
 parameter 1      : Copy_u8Port -> port name		         
 parameter 2      :	Copy_u8Pin  -> pin number	             
 Return           : u8 indication for error		             
****************************************************************/
u8 LED_u8TurnOff(u8 Copy_u8Port, u8 Copy_u8Pin);

/****************************************************************
 name             : LED_u8Toggle	                 
 description      : toggle pin state	                     
 parameter 1      : Copy_u8Port -> port name		         
 parameter 2      :	Copy_u8Pin  -> pin number	                 
 Return           : u8 indication for error		             
****************************************************************/
u8 LED_u8Toggle(u8 Copy_u8Port, u8 Copy_u8Pin);

#endif /* KEYPAD_H_ */