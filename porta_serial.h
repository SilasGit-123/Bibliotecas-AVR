/*
 * porta_serial.h
 *
 * Created: 25/04/2020 13:48:49
 * Author : Silas
 */

#ifndef PORTA_SERIAL_H
#define PORTA_SERIAL_H

 #include <avr/io.h>
 #include <avr/interrupt.h>

 char rec_u;                        //variavel global

 #define  CLR_BIT(address, bit)          (address&=~(1<<bit)) //zera bit
 
 //inicia a porta serial
 void init_usart(void);
 void uart_envia(unsigned char caracter);
 void uart_enviastring(char texto[]);
 void uart_recebe(void);
 ISR(USART_RXC_vect);

#endif