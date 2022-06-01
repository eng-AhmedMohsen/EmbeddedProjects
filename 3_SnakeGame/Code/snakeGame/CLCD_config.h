/****************************************************************
 Author     : 	Ahmed Mohsen	
 Layer      :   HAL                                                                              
 SWC        : 	charachter LCD		                                         
 Date       : 	24-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/

#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/* 
CLCD_DATA_PORT 8 pins Data 
*/
#define CLCD_DATA_PORT			DIO_u8PORTC

/*
	CLCD_DATA_PORT 4 pins Data
		Select pins if Will Work with 4bit mode high bit always
*/
#define CLCD_DATA_PIN0			DIO_u8PIN4
#define CLCD_DATA_PIN1			DIO_u8PIN5
#define CLCD_DATA_PIN2			DIO_u8PIN6
#define CLCD_DATA_PIN3			DIO_u8PIN7


#define CLCD_CTRL_PORT			DIO_u8PORTD

#define CLCD_RS_PIN				DIO_u8PIN2
#define CLCD_RW_PIN				DIO_u8PIN1
#define CLCD_E_PIN				DIO_u8PIN0

/* 
can work in 2 modes 8bit or 4bit mode: 
    CLCD_MODE_8BIT
    CLCD_MODE_4BIT 
*/
#define CLCD_MODE   CLCD_MODE_8BIT

#endif
