/*
 * spi.h
 *
 * Created: 09.07.2026 11:10:37
 *  Author: rakel
 */ 


#ifndef SPI_H_
#define SPI_H_
#define F_CPU 8000000UL
#include <stdint.h>
#define MISO PB4
#define MOSI PB3
#define SS   PB2
#define SCK  PB5

void spi_MasterInit();
void spi_SlaveInit();
uint8_t spi_MasterTransmit(uint8_t data);
uint8_t spi_SlaveTransmit(uint8_t data);
void SS_LOW();
void SS_HIGH();




#endif /* SPI_H_ */