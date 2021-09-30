#ifndef		EXTI0_INTERFACE_H
#define		EXTI0_INTERFACE_H

#define		EXTI0_FALLING		1
#define		EXTI0_RISING		3
#define		EXTI0_IOC			5
#define		EXTI0_LOW			7

void EXTI0_voidInit(void);
void EXTI0_voidEnable(void);
void EXTI0_voidDisable(void);


#endif