#ifndef		EXTI0_PRIVATE_H
#define		EXTI0_PRIVATE_H

#define		MCUCR			*((volatile u8 *) 0x55)
#define		MCUCSR			*((volatile u8 *) 0x54)
#define		GICR			*((volatile u8 *) 0x5B)
#define		GIFR			*((volatile u8 *) 0x5A)


void __vector_1(void) __attribute__((signal , used));

#endif