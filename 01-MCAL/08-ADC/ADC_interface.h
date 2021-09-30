#ifndef		_ADC_INTERFACE_H
#define		_ADC_INTERFACE_H

#define		ADC_u8_CHANNEL_0	0
#define		ADC_u8_CHANNEL_1		1
#define		ADC_u8_CHANNEL_2		2
#define		ADC_u8_CHANNEL_3		3
#define		ADC_u8_CHANNEL_4		4
#define		ADC_u8_CHANNEL_5		5
#define		ADC_u8_CHANNEL_6		6
#define		ADC_u8_CHANNEL_7		7

void		ADC_voidInit(void);
void		ADC_voidEnable(void);
void		ADC_voidDisable(void);
void		ADC_voidEnableInterrupt(void);
void		ADC_voidDisableInterrupt(void);
u16			ADC_u16GetDigitalValue(u8 Copy_u8ChannelNb);
#endif