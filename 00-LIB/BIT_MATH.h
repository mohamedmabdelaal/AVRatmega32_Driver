/*
Created by: Eng. Mohamed Monder
Ver:		1
									*/
#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(VAR,BIT) (VAR) |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT) (VAR) &= ~(1 << (BIT))
#define TOG_BIT(VAR,BIT) (VAR) ^=  (1 << (BIT))
#define GET_BIT(VAR,BIT) (((VAR) >> (BIT)) & 0x01)


#endif