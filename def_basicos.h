#ifndef  _DEF_BASICOS_H
#define  _DEF_BASICOS_H

#define F_CPU 8000000UL  //define a frequencia do microcontrolador

#include <avr/io.h>      //definicao de componente especificado
#include <util/delay.h> //biblioteca para delay


//definições de macros para trabalhar com bits
#define set_bit(ADDRESS,BIT) (ADDRESS |= (1<<BIT))  //seta o bit da porta
#define clr_bit(ADDRESS,BIT) (ADDRESS &=~ (1<<BIT)) //zera o bit da porta
#define cpl_bit(ADDRESS,BIT) (ADDRESS ^= (1<<BIT))  //troca o estado logico do bit 
#define check_bit(ADDRESS,BIT) (ADDRESS & (1<<BIT)) //leitura porta (PINx,pxx)

#endif
