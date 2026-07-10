/*
 * spi.c
 *
 * Created: 09.07.2026 11:11:31
 *  Author: rakel
 */ 

#include "spi.h"
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

void spi_MasterInit()
{
	/*1*/  // конфигурируем порты MISO-вход(MISO в POTB подтягиваем к питанию); MOSI-выход; SS-выход; SCK-выход;
	/*2*/  // выставляем в регистре SPRC бит SPE - "1"; MSTR-"1"; (битами SPR1,SPR0,SPI2X)- частоту шины SPI(смотреть в таблице даташита)
	
	/*1*/ DDRB |= (1 << MOSI) | (1 << SS) | (1 << SCK); // порты PB3,PB2,PB5 устанавливаем на выход
	      DDRB &= ~(1 << MISO);                          //порт PB4 устанавливаем на вход
		  PORTB |= (1 << MISO);                          // внутренняя подтяжка порта PB4 к "+" питания
		  
    /*2*/ SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0); //частота шины выставлена в данном случае(8000000 / 16)->комбинация-(SPI2X=0;SPSR1=0;SPSR0=1)
}


void spi_SlaveInit()
{
	
}

uint8_t spi_MasterTransmit(uint8_t data)
{   
	SPDR = data;
	while(!(SPSR &(1 << SPIF)));
	return SPDR;
}

uint8_t spi_SlaveTransmit(uint8_t data)
{
	return SPDR;
}

void SS_LOW()
{
	PORTB &= ~(1 << SS);
}
 
void SS_HIGH()
{
	PORTB |= (1 << SS);
}
