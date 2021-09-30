/*
Created by: Eng. Mohamed Monder
Ver:		1
									*/
#ifndef _LCD_INTERFACE_H
#define _LCD_INTERFACE_H

void	LCD_voidInit(void);
void    LCD_voidGotoXY(u8 Copy_u8LimeID, u8 Copy_u8charNM);
void LCD_voidWriteString(u8 * pu8StringCopy);
void LCD_voidWriteNum( u32 pu32NumCopy);
void	LCD_voidSendCMD(u8 Copy_u8CMD);
void	LCD_voidWriteChar(u8 Copy_u8Char);
void LCD_voidWriteint(u16 Copy_u16int);
#endif
