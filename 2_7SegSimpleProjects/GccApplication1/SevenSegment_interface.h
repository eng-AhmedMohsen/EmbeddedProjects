/****************************************************************
 Author     : 	Ahmed Mohsen	                                     
 Layer      : 	HAL		                                         
 SWC        : 	Seven Segment				                                         
 Date       : 	24-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/
#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "SevenSegment_interface.h"
#include "SevenSegment_private.h"
#include "SevenSegment_config.h"


/****************************************************************
 name             : SevenSegment_u8Init	                 
 description      : init 7 Segments                  
 parameter 1      : Copy_u8Port:
                        DIO_u8PORTA ..etc
 parameter 2      : Copy_u8Type: SEVEN_SEGMENT_COMMON_ANODE SEVEN_SEGMENT_COMMON_CATHODE
 
 parameter 3      : Copy_u8InitNumber:
                        SEG_NUMBER_0
                        SEG_NUMBER_1
                        ..etc
 Return           : u8 indication for error		             
****************************************************************/
u8 SevenSegment_u8Init(u8 Copy_u8Port,u8 Copy_u8Type,u8 Copy_u8InitNumber);

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
u8 SevenSegment_u8DisplayNumber(u8 Copy_u8Port,u8 Copy_u8Type,u8 Copy_u8Number);

#endif /* SSD_INTERFACE_H_ */