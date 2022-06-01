/****************************************************************
 Author     : 	Ahmed Mohsen	                                     
 Layer      : 	HAL		                                         
 SWC        : 	Seven Segment				                                         
 Date       : 	24-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/

#include "SevenSegment_interface.h"

const u8 Local_u8Numbers[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0xFD,0x07,0x7F,0x6F};

/****************************************************************
 name             : SevenSegment_u8Init	                 
 description      : init 7 Segments                  
 parameter 1      : Copy_u8Port:
                        DIO_u8PORTA ..etc
 parameter 2      : Copy_u8Type: 
                        SEVEN_SEGMENT_COMMON_ANODE
                        SEVEN_SEGMENT_COMMON_CATHODE
 parameter 3      : Copy_u8InitNumber:
                        SEG_NUMBER_0
                        SEG_NUMBER_1
                        ..etc
 Return           : u8 indication for error		             
****************************************************************/
u8 SevenSegment_u8Init(u8 Copy_u8Port,u8 Copy_u8Type,u8 Copy_u8InitNumber)
{
	u8 Local_u8ErrorState = OK;

	/* init port as output */
	Local_u8ErrorState = DIO_u8SetPortDirection(Copy_u8Port,DIO_u8PORT_OUTPUT);

	if(Local_u8ErrorState == OK)
	{
		Local_u8ErrorState = SevenSegment_u8DisplayNumber(Copy_u8Port, Copy_u8Type, Copy_u8InitNumber);
	}
	else
	{
		/* error */
		Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

/****************************************************************
 name             : SevenSegment_u8DisplayNumber	                 
 description      : display number on 7-segments        
 parameter 1      : Copy_u8Port:
                        DIO_u8PORTA ..etc
 parameter 2      : Copy_u8Type: 
                        SEVEN_SEGMENT_COMMON_ANODE
                        SEVEN_SEGMENT_COMMON_CATHODE
 parameter 3      : Copy_u8Number:
                        SEG_NUMBER_0
                        SEG_NUMBER_1
                        ..etc
 Return           : u8 indication for error		             
****************************************************************/
u8 SevenSegment_u8DisplayNumber(u8 Copy_u8Port,u8 Copy_u8Type,u8 Copy_u8Number)
{
	u8 Local_u8ErrorState = OK;
	
	/* check if number > 9*/
	if(Copy_u8Number > 9)
	{
		/* return error */
		Local_u8ErrorState = NOK;
	}
	else
	{
		switch(Copy_u8Type)
		{
			case(SEVEN_SEGMENT_COMMON_CATHODE): DIO_u8SetPortValue(Copy_u8Port,Local_u8Numbers[Copy_u8Number]);  break;
			case(SEVEN_SEGMENT_COMMON_ANODE)  : DIO_u8SetPortValue(Copy_u8Port,~Local_u8Numbers[Copy_u8Number]); break;
			default							  : /* error */ Local_u8ErrorState = NOK;
		}
	}

	return Local_u8ErrorState;
}