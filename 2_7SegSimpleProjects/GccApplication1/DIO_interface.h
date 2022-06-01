/****************************************************************
 Author     : 	Ahmed Mohsen	                                     
 Layer      : 	MCAL		                                         
 SWC        : 	DIO			                                         
 Date       : 	24-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*****************************************************************
                Includes
*****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_register.h"

/****************************************************************
 name             : DIO_u8SetPinDirection	                 
 description      : set pin direction	                     
 parameter 1      : Copy_u8Port -> port name		         
 parameter 2      :	Copy_u8Pin  -> pin number	             
 parameter 3      : Copy_u8Direction  -> input or output     
 Return           : u8 indication for error		             
****************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_u8Direction);

/****************************************************************
 name             : DIO_u8SetPortDirection	                 
 description      : set port direction	                    
 parameter 1      : Copy_u8Port -> port name (a,b,c,d)		 
 parameter 3      : Copy_u8Direction  -> input or output     
 Return           : u8 indication for error		             
****************************************************************/
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);


/****************************************************************
 name             : DIO_u8SetPinValue	                 
 description      : set pin value high or low	                     
 parameter 1      : Copy_u8Port -> port name		         
 parameter 2      :	Copy_u8Pin  -> pin number	             
 parameter 3      : Copy_u8Value  -> high or low     
 Return           : u8 indication for error		             
****************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_u8Value);


/****************************************************************
 name             : DIO_u8SetPortValue	                 
 description      : set port value 0xFF or 0x00                   
 parameter 1      : Copy_u8Port -> port name		         
 parameter 3      : Copy_u8Value  -> high or low     
 Return           : u8 indication for error		             
****************************************************************/
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);


/****************************************************************
 name             : DIO_u8GetPinValue	                 
 description      : get pin value high or low	                     
 parameter 1      : Copy_u8Port -> port name		         
 parameter 2      :	Copy_u8Pin  -> pin number	             
 parameter 3      : Copy_pu8Value  -> returned value     
 Return           : u8 indication for error		                
****************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin, u8* Copy_pu8Value);

/****************************************************************
 name             : DIO_u8GetPinValue	                 
 description      : get pin value high or low	                     
 parameter 1      : Copy_u8Port -> port name		         
 parameter 2      :	Copy_u8Pin  -> pin number	             
 Return           : u8 indication for error		                
*****************************************************************/
u8 DIO_u8TogPinValue(u8 Copy_u8Port,u8 Copy_u8Pin);
#endif
