/****************************************************************
 Author     : 	Ahmed Mohsen	
 Layer      :   HAL                                                                              
 SWC        : 	charachter LCD		                                         
 Date       : 	24-5-2022	                                         
 Version    :   1.00		                                         
****************************************************************/

#define CLCD_MODE_8BIT  0
#define CLCD_MODE_4BIT  1


/* LCD Commands */
#define LCD_u8ClearScreen                       0x01
#define LCD_u8ReturnHome                        0x02
#define LCD_u8TwoLine                           0x3C
#define LCD_u8DisplayOnCursorOnBlinkOn          0x0F
#define LCD_u8DisplayOnCursorOnBlinkOff         0x0E
#define LCD_u8DisplayOnCursorOffBlinkOff        0x0C
#define LCD_u8ShiftCursorRight			        0x06