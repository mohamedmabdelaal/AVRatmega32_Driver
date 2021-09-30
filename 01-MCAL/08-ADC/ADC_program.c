#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"

void		ADC_voidInit(void)
{
	CLR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	
	CLR_BIT(ADMUX,5);
	
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,0);
	
	CLR_BIT(ADCSRA,7);
	
	CLR_BIT(ADCSRA,3);
	
	SET_BIT(ADCSRA,4);
}
void		ADC_voidEnable(void)
{
	SET_BIT(ADCSRA,7);
}
void		ADC_voidDisable(void)
{
	CLR_BIT(ADCSRA,7);
}
void		ADC_voidEnableInterrupt(void)
{
	SET_BIT(ADCSRA,3);
}
void		ADC_voidDisableInterrupt(void)
{
	CLR_BIT(ADCSRA,3);
	
	SET_BIT(ADCSRA,4);
}
u16			ADC_u16GetDigitalValue(u8 Copy_u8ChannelNb)
{
		ADMUX&= ADC_CHANNEL_MASK;
		ADMUX|=Copy_u8ChannelNb;
		SET_BIT(ADCSRA,6);
		while(GET_BIT(ADCSRA,4)==0);
		SET_BIT(ADCSRA,4);
		return ADC;
}