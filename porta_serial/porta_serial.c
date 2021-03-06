/*
 *porta_serial.c
 *
 * Created: 25/04/2020 13:48:49
 * Author : Silas
 */ 
#include "porta_serial.h"


//********************************************************************************
// Inicializa a USART - 9600,n,8,1 a 8000000MHz
//********************************************************************************
void init_usart(void){

     UCSRB = 0x00;                                              //desabilita TX, RX para setar baud rate
     UCSRA = 0x00;                                              //limpa flag TXC, seleciona veloc. normal e desab. Multi-Proc. Com.
     UCSRC = ((1<<URSEL) |  (1<<UCSZ1) | (1<<UCSZ0));           //modo assincrono, 8 bits, sem paridade e 1 stop bit
     UBRRH = 0x00;                                            //seta baud rate a 9600 bps (8000000MHz) e U2X=0 (veloc. normal)
     UBRRL = 0x33;                                              //valor 51 decimal, conforme tabela no datasheet
     UCSRB = ((1<<RXCIE) | (1<<RXEN) | (1<<TXEN));              //transmiss�o e recep��o habilitados, int de recep��o habilitada
}
//********************************************************************************
// Envia um byte atrav�s da USART
//********************************************************************************
void uart_envia(unsigned char caracter){
	
     while (! (UCSRA & (1<<UDRE)));                   //verifica se est� desocupado, sen�o espera
     UDR = caracter;                                 //transmite caracter
}
//********************************************************************************
// Envia um string atraves da USART
//********************************************************************************
void uart_enviastring(char texto[]){
	
	 int tamanho =strlen(texto);
	 for (int cont =0 ;cont <= tamanho;cont++)
	 
	 {
		 uart_envia(texto[cont]);
	 }
	
}
//********************************************************************************
// Recebe um dado quando vector de interrup��o UART_RX_vect � disparado
//********************************************************************************
void uart_recebe(void){ 
    unsigned char c;
    c = UDR;                                //le byte
    if (CLR_BIT(UCSRA, RXC)){              //finalizou recep��o
        rec_u = c;                         //guarda na vari�vel global, declarada anteriormente
        uart_envia(c);                     //envia eco do caracter recebido
    }
}


//********************************************************************************
// Interrup��o UART - RX
//********************************************************************************
ISR(USART_RXC_vect){
       uart_recebe();                        //recebe dado da UART do microcontrolador
}



