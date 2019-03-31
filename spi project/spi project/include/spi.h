/*
 * spi.h
 *
 * Created: 3/31/2019 5:43:50 PM
 *  Author: AVE-LAP-023
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "Types.h"

/***********************************************************************************************************************
 * Function name :- SPI_init
 * Function job :- initiate spi module
 * Function argument :- N/A
 * Function return :- N/A
 ***********************************************************************************************************************/
void SPI_init_M(void);
/***********************************************************************************************************************
 * Function name :- SPI_init
 * Function job :- initiate spi module
 * Function argument :- N/A
 * Function return :- N/A
 ***********************************************************************************************************************/
void SPI_init_S(void);
/***********************************************************************************************************************
 * Function name :- SPI_Recieve
 * Function job :- recieving data
 * Function argument :- N/A
 * Function return :- N/A
 ***********************************************************************************************************************/
uint8 SPI_Recieve(void);


#endif /* SPI_H_ */