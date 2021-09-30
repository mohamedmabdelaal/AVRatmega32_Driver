#include "STD_TYPES.h"
#include "GET_MATH.h"
#include "KEYPAD_interface.h"
#include "DIO_interface.h"
#include <util/delay.h>


const u8 KPD_Au8SwitchVal[4][4]=
{
	{'4','8','0','*'},
		{'3','7','.','+'},
			{'2','6','=','-'},
				{'1','5','9','%'}
};
/*			HW connection
c4 to B0 		r1 to B4
c3 to B1		r2 to B5
c2 to B2		r3 to B6
c1 to B3		r4 to B7      */

u8	 	KEYPAD_u8GetPressedKey()
{
	/* 0xFF There is no pressed Key*/
	u8 Local_u8PressedKey = 0xFF;
	/* Initialize colums all high */
	DIO_voidSetPortValue(KPD_PORT,0xFF);
	/* for to senr sequence*/
	for(u8 Col =0; Col<4;Col++)
	{/* Active colum*/
		DIO_voidSetPinValue(KPD_PORT,Col,LOW);
		/*Active colum*/
		for (u8 Row =4;Row<8;Row++)
		{
			/*Chek if Any Switch is pressed*/
			if(DIO_u8GetPinValue(KPD_PORT,ROW)==0)
			{
				/* Debouncing*/
				_delay_ms(10);
				/*Switch Value*/
				Local_u8PressedKey= KPD_Au8SwitchVal[Col][Row-4];
			}
		}
		/*deactive colum*/
		DIO_voidSetPinValue(KPD_PORT,Col,HIGH);
	}
	
	return Local_u8PressedKey;
}
