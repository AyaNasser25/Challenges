/*
 * spi.c
 *
 * Created: 3/31/2019 5:39:16 PM
 *  Author: AVE-LAP-023
 */ 
#include <avr/io.h>
#include "../include/BiteWiseOperation.h"
#include "../include/spi.h"

/***********************************************************************************************************************
 * Function name :- SPI_init
 * Function job :- initiate spi module
 * Function argument :- N/A
 * Function return :- N/A
 ***********************************************************************************************************************/
void SPI_init_M(void)
{
	/* set MOSI as output pin */
	Set_Bit(DDRB,PB5);
	/* set MISO as input pin */
	Clear_Bit(DDRB,PB6);
	/* set SS output pin */
	Set_Bit(DDRB,PB4);
	
   /* enable spi module */
   Set_Bit(SPCR,SPE);
   /* enable master mode */
   Set_Bit(SPCR,MSTR);
   
}

/***********************************************************************************************************************
 * Function name :- SPI_init
 * Function job :- initiate spi module
 * Function argument :- N/A
 * Function return :- N/A
 ***********************************************************************************************************************/
void SPI_init_S(void)
{
   
   /* set MOSI as output pin */
   Set_Bit(DDRB,PB5);
   /* set MISO as input pin */
   Clear_Bit(DDRB,PB6);
   /* set SS input pin */
   Clear_Bit(DDRB,PB4);
   
   /* enable spi module */
   Set_Bit(SPCR,SPE);
  
}

/***********************************************************************************************************************
 * Function name :- SPI_Send
 * Function job :- sending data
 * Function argument :- N/A
 * Function return :- N/A
 ***********************************************************************************************************************/
void SPI_Send(uint8 data)
{

    /* send required data */
	SPDR = data ;
   
    /* wiath until send completed */
	while (Get_Bit(SPSR,SPIF))
	{
		
	}

 

}

/***********************************************************************************************************************
 * Function name :- SPI_Recieve
 * Function job :- recieving data
 * Function argument :- N/A
 * Function return :- N/A
 ***********************************************************************************************************************/
uint8 SPI_Recieve(void)
{
	
      /* wiath until recieving is completed */
      while (Get_Bit(SPSR,SPIF))
      {
	      
      }
	  return SPDR;
}

