/*
 * uart.h
 *
 * Created: 04.07.2026 00:37:38
 *  Author: rakel
 */ 


#ifndef UART_H
#define UART_H
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h> //задержки используются когда внутрений источник тактирования для UART т.к частота не стабильна

void uart_Init();
void uart_SendChar(char simbol);

uint8_t uart_SendCharHex(uint8_t value); 
void uart_SendHex8(uint8_t value);



#endif /* UART_H_ */