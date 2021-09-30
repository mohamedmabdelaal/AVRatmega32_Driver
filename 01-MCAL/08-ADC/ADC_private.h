#ifndef		_ADC_PRIVATE_H
#define		_ADC_PRIVATE_H

#define		ADMUX		*((volatile u8 *)0x27)
#define		ADCSRA		*((volatile u8 *)0x26)
#define		ADCL		*((volatile u8 *)0x24)
#define		ADCH		*((volatile u8 *)0x25)
#define		SFIOR		*((volatile u8 *)0x50)
#define		ADC			*((volatile u8 *)0x24)

#define		ADC_CHANNEL_MASK	0b11100000



#endif