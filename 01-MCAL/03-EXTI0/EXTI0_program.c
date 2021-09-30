#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI0_interface.h"
#include "EXTI0_private"
#include "EXTI0_config.h"

void EXTI0_voidInit(void)
{
	#if		SENSE_MODE == EXTI0_FALLING
				CLR_BIT(MCUCR , 0);
				SET_BIT(MCUCR , 1);
	#elif	SENSE_MODE == EXTI0_RISING
				SET_BIT(MCUCR , 0);
				SET_BIT(MCUCR , 1);
	#elif	SENSE_MODE == EXTI0_IOC
				SET_BIT(MCUCR , 0);
				CLR_BIT(MCUCR , 1);
	#elif	SENSE_MODE == EXTI0_LOW
				CLR_BIT(MCUCR , 0);
				CLR_BIT(MCUCR , 1);
	#else
			#error("Wrong choice of Sense mode!")
	#endif
	/*			Disable of EXTI0		*/
	CLR_BIT(GICR , 6);
	/*			CLR EXTI0 Flag by S.W	*/
	CLR_BIT(GIFR , 6);
}

void EXTI0_voidSetSignalLatch(u8 Signal)
{
	if(Signal == EXTI0_FALLING)
	{
		CLR_BIT(MCUCR , 0);
		SET_BIT(MCUCR , 1);
	}
	else if(Signal == EXTI0_RISING)
	{
		SET_BIT(MCUCR , 0);
		SET_BIT(MCUCR , 1);
	}
	else if(Signal == EXTI0_IOC)
	{
		SET_BIT(MCUCR , 0);
		CLR_BIT(MCUCR , 1);
	}
	else(Signal == EXTI0_LOW)
	{
		CLR_BIT(MCUCR , 0);
		CLR_BIT(MCUCR , 1);
	}
}
void EXTI0_voidEnable(void)
{
	SET_BIT(GICR , 6);
}
void EXTI0_voidDisable(void)
{
	CLR_BIT(GICR , 6);
}

