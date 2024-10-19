#define	F_CPU	16000000
#include <avr/io.h>
#include <util/delay.h>
#include "configuracao.h"

int main(void){
	//DDRB = 0x20;
	setbit(DDRB, 5);
    while (1){
		_delay_ms(1000);
		setbit(PORTB, 5); // Acende o Led
		clearbit(PORTB, 5);// Desliga o Led
		_delay_ms(1000);
    }
}

