#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
//DIO_voidSetPinDirection(PORTA , PIN0 , OUTPUT);
void DIO_voidSetPinDirection(u8 PortID , u8 PinID , u8 Direction)
{
	/*	Range check for Ports and Pins 			*/
	if( PortID < 4 && PinID < 8)
	{
		if(Direction == OUTPUT)
		{
			switch(PortID)
			{
				case PORTA : SET_BIT(DDRA_REG,PinID);	break;
				case PORTB : SET_BIT(DDRB_REG,PinID);	break;
				case PORTC : SET_BIT(DDRC_REG,PinID);	break;
				case PORTD : SET_BIT(DDRD_REG,PinID);	break;
			}
		}
		else if (Direction == INPUT)
		{
			switch(PortID)
			{
				case PORTA : CLR_BIT(DDRA_REG,PinID);	break;
				case PORTB : CLR_BIT(DDRB_REG,PinID);	break;
				case PORTC : CLR_BIT(DDRC_REG,PinID);	break;
				case PORTD : CLR_BIT(DDRD_REG,PinID);	break;
			}
			
		}else {/*do nothing*/}
	
		
	}else{/*do nothing*/}
}
void DIO_voidSetPinValue(u8 PortID , u8 PinID , u8 Value)
{
		/*	Range check for Ports and Pins 			*/
	if( PortID < 4 && PinID < 8)
	{
		if(Value == HIGH)
		{
			switch(PortID)
			{
				case PORTA : SET_BIT(PORTA_REG,PinID);	break;
				case PORTB : SET_BIT(PORTB_REG,PinID);	break;
				case PORTC : SET_BIT(PORTC_REG,PinID);	break;
				case PORTD : SET_BIT(PORTD_REG,PinID);	break;
			}
		}
		else if (Value == LOW)
		{
			switch(PortID)
			{
				case PORTA : CLR_BIT(PORTA_REG,PinID);	break;
				case PORTB : CLR_BIT(PORTB_REG,PinID);	break;
				case PORTC : CLR_BIT(PORTC_REG,PinID);	break;
				case PORTD : CLR_BIT(PORTD_REG,PinID);	break;
			}
			
		}else {/*do nothing*/}
	
		
	}else{/*do nothing*/}
}
u8	DIO_u8GetPinValue(u8 PortID , u8 PinID)
{
	u8	Local_u8Value = 0xFF;
	if(PortID < 4 && PinID < 8)
	{
		switch(PortID)
		{
			case PORTA: Local_u8Value = GET_BIT(PINA_REG ,PinID); break;
			case PORTB: Local_u8Value = GET_BIT(PINB_REG ,PinID); break;
			case PORTC: Local_u8Value = GET_BIT(PINC_REG ,PinID); break;
			case PORTD: Local_u8Value = GET_BIT(PIND_REG ,PinID); break;			
		}
	}
	return Local_u8Value;
}
/*DIO_voidSetPortDirection(PORTA , 0xFF);*/
void DIO_voidSetPortDirection(u8 PortID , u8 Direction)
{
	if(PortID <4 )
	{
		switch(PortID)
		{
			case PORTA : DDRA_REG = Direction ; break;
			case PORTB : DDRB_REG = Direction ; break;
			case PORTC : DDRC_REG = Direction ; break;
			case PORTD : DDRD_REG = Direction ; break;
		}
	}
	
}
void DIO_voidSetPortValue(u8 PortID ,  u8 Value)
{
		if(PortID <4 )
	{
		switch(PortID)
		{
			case PORTA : PORTA_REG = Value ; break;
			case PORTB : PORTB_REG = Value ; break;
			case PORTC : PORTC_REG = Value ; break;
			case PORTD : PORTD_REG = Value ; break;
		}
	}
}
