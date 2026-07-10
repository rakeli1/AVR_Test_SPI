/*
 * Test_SPI.c
 *
 * Created: 08.07.2026 22:12:26
 * Author : rakel
 */ 
#define F_CPU 8000000UL
#include "uart.h"
#include "spi.h"
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    uart_Init();        // Initialisation UART
	spi_MasterInit();   // Initialisation SPI in MASTER MODE
	SS_LOW();
	spi_MasterTransmit(0x8B);
	uint8_t bmeValue = spi_MasterTransmit(0x00);
	SS_HIGH();
    

    while (1) 
    {
		uart_SendHex8(bmeValue);
		uart_SendChar(' ');
		_delay_ms(500);
    }
}

