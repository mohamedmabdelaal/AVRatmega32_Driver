#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "LCD_interface.h"

#include <util/delay.h>
#include <math.h>




void	LCD_voidInit(void)
{
	/*		DATA port OUTPUT	*/
	DIO_voidSetPortDirection(LCD_DATA_PORT , 0xFF);

	/*		CONTROL port OUTPUT	*/
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , LCD_RS,OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , LCD_RW,OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT , LCD_EN,OUTPUT);
	_delay_ms(35);
	/*	Function set 2-Lines Display and 5*7 Font		*/
	LCD_voidSendCMD(0x38);
	_delay_ms(1);
	/*	Display on/off Control Display ON Cursor OFF	*/
	LCD_voidSendCMD(0x0C);
	_delay_ms(1);	
	/*	Clear	Display									*/
	LCD_voidSendCMD(0x01);
	_delay_ms(2);	
	/*	Entery Mode		Position auto increment			*/
	LCD_voidSendCMD(0x06);	
}
void    LCD_voidGotoXY(u8 Copy_u8LimeID, u8 Copy_u8charNM)
{
	switch (Copy_u8LimeID)
	{
	case 1: LCD_voidSendCMD(0x80+Copy_u8charNM); break;
	case 2: LCD_voidSendCMD(0xC0+Copy_u8charNM); break;
	}
}
void LCD_voidWriteString(u8 * pu8StringCopy)
{
	u8 Loc_u8Counter = 0 ;

	while(pu8StringCopy[Loc_u8Counter] !='\0')
	{
		LCD_voidWriteChar(pu8StringCopy[Loc_u8Counter]);
		Loc_u8Counter++;
	}

}
/*  Write number u32	*/
void LCD_voidWriteNum( u32 pu32NumCopy)
{
	u8 Loc_u8Counter = 0 ;
	u32 Loc_Uu32Num=pu32NumCopy;
	/*	Count number of digits	*/
	do
	{
		Loc_u8Counter++;
		Loc_Uu32Num=Loc_Uu32Num/10;
	}while (Loc_Uu32Num!=0);
	/*	Create array to put in it every digit of number	*/
	u32 * Loc_u32array;
	while (Loc_u8Counter!=0)
	{
		/* Create power 10^(Loc_u8Counter-1) to use to seprate evry digit	*/
		u32 Loc_u32power=1;
		for (u8 i =0 ; i<Loc_u8Counter-1;i++)
		{
			Loc_u32power=Loc_u32power*10;
		}
		/*	Seprate the digit number Loc_u8Counter of pu32NumCopy	*/
		Loc_u32array[Loc_u8Counter-1]= pu32NumCopy/Loc_u32power;
		/*	Display the digit number Loc_u8Counter of pu32NumCopy in LCD	*/
		LCD_voidWriteChar(Loc_u32array[Loc_u8Counter-1]+'0');
		/*	remove the digit that display from pu32NumCopy	*/
		pu32NumCopy=pu32NumCopy-(Loc_u32array[Loc_u8Counter-1]*Loc_u32power);
		Loc_u8Counter--;
	}
}
void	LCD_voidSendCMD(u8 Copy_u8CMD)
{
	/*		1-	RS = 0		Send CMD	*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_RS , LOW);
	/*		2-	RW = 0		Write CMD	*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_RW , LOW);
	/*		3-	DATA PORT = CMD			*/
	DIO_voidSetPortValue(LCD_DATA_PORT , Copy_u8CMD);
	/*		4-	Enable Laching			*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_EN , HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_EN , LOW);	
	_delay_ms(2);

}

void	LCD_voidWriteChar(u8 Copy_u8Char)
{
	/*		1-	RS = 1		Write DATA	*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_RS , HIGH);
	/*		2-	RW = 0		Write DATA	*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_RW , LOW);
	/*		3-	DATA PORT = CMD			*/
	DIO_voidSetPortValue(LCD_DATA_PORT , Copy_u8Char);
	/*		4-	Enable Laching			*/
	DIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_EN , HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT , LCD_EN , LOW);	
	_delay_ms(2);

}
void LCD_voidWriteint(u16 Copy_u16int)
{
	/**************************Start Function********************************/

	/*                        Variable initialization                            */
	u16 Local_u16operation;
	u8 Local_u8num[10], Local_u8NumberLeangh=0,Local_u8CurrentLocation,Local_u8RemainingLocation;
	/*===========================================================================*/

	/****************************************End This Part******************************************/

				/*2-Store Each Part of Integer Number In Array*/
	do{
		/*Get The Units(0-9) of Integar number And soter it in 'Local_u16operation'Variable*/
		Local_u16operation = Copy_u16int%10;
		/*Subtract the Integar Number with The Units Number Form Previous Step*/
		Copy_u16int -=Local_u16operation;
		/*Divite The Integar Number By 10 to Shift the Tens Number to Units Location */
		Copy_u16int /=10;
		/*Store The units Number in array*/
		Local_u8num[Local_u8NumberLeangh]=Local_u16operation;
		/*Increment The 'Local_u8NumberLeangh'Variable to Get The leangh of Integar Number*/
		Local_u8NumberLeangh++;
		/*Check if the Integar number equal Zero*/
	}while(Copy_u16int!=0);
	/****************************************End This Part******************************************/

				/*3-Write The Integar Number In LCD*/

	/*Check The Remining Location In LCD Greter or equal The Leanth of Integar Number*/
	if(Local_u8RemainingLocation>=Local_u8NumberLeangh)
	{
		/*Write The Integar In LCD*/
		for (u8 i=1;i<=Local_u8NumberLeangh;i++)
		{
			/*We Add 48 to The Integar Number to convert it from Integar form to Caharater Form */
			LCD_voidWriteChar(Local_u8num[Local_u8NumberLeangh-i]+48);
		}

	}
	/*Check The Remining Location In LCD Less Than The Leanth of Integar Number*/
	else if(Local_u8RemainingLocation<Local_u8NumberLeangh)
	{
		/*Check if The DDRAM at The Last Location In Line 1*/
		if(Local_u8CurrentLocation<=0x0F)
		{
			/*Write symbol '>>' At The Last Location In Line 1 */
			LCD_voidWriteChar(0x3E);
			/*Move To The The First Location in Line 2*/
			LCD_voidGotoXY(2,0);
			/*Write The Integar In LCD*/
			for (u8 i=1;i<=Local_u8NumberLeangh;i++)
			{
				/*We Add 48 to The Integar Number to convert it from Integar form to Caharater Form */
				LCD_voidWriteChar(Local_u8num[Local_u8NumberLeangh-i]+48);
			}
		}
		/*Check if The DDRAM at The Last Location In Line 2*/
		else if (Local_u8CurrentLocation<=0x4F)
		{
			/*Write symbol '>>' At The Last Location In Line 1 */
			LCD_voidWriteChar(0x3E);
			/*Delay for 500 msec*/
			_delay_ms(500);
			/*Clear Dispaly and Go to the First Location In Line 1*/
			/*Write The Integar In LCD*/
			for (u8 i=1;i<=Local_u8NumberLeangh;i++)
			{
				/*We Add 48 to The Integar Number to convert it from Integar form to Caharater Form */
				LCD_voidWriteChar(Local_u8num[Local_u8NumberLeangh-i]+48);
			}
		}
	}
	/****************************************End This Part******************************************/

				/**************************End Function********************************/
}
