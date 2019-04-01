/*
 * BiteWiseOperation.h
 *
 * Created: 2/13/2019 11:17:00 AM
 *  Author: AVE-LAP-023
 */ 
#define F_CPU 16000000


#ifndef BITEWISEOPERATION_H_
#define BITEWISEOPERATION_H_
/* macro that write one(set) to specified bit in a register */
#define  Set_Bit(Register,Bit) (Register |= (1<<Bit))
/* macro that write zero (clear) to specified bit in a register */
#define  Clear_Bit(Register,Bit) (Register &= (~(1<<Bit)))
/* macro that toggle  specified bit in a register */
#define  Togle_Bit(Register,Bit) (Register ^= (1<<Bit))
/* macro that read  specified bit in a register */
#define  Get_Bit(Register,Bit) (Register & (1<<Bit))






#endif /* BITEWISEOPERATION_H_ */