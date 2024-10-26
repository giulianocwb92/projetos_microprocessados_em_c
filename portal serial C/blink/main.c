#define F_CPU	16000000
#include <avr/io.h>
#include <util/delay.h>
#include "minha_lib.h"

void config_adc(){
	ADCSRA = 0x87;
}

unsigned int converte_adc(){
	//ADMUX = 0x44; referência 5V
	ADMUX = 0xC4;
	_delay_us(10);
	setbit(ADCSRA, 6);
	while(getbit(ADCSRA, 6)==1){}
	return ADC;
}

void config_1200_8_n_1(){
	UBRR0H = 0x3;
	UBRR0L = 0x40;
	UCSR0C = 0x06;
	UCSR0B = 0x18;
	UCSR0A = 0x20;
}

void tx(char c){
	while(getbit(UCSR0A, 5) == 0){
	}
	UDR0 = c;
}



int main(void){
	config_1200_8_n_1();
	config_adc();
	setbit(DDRB,5);
    while (1){
		unsigned int num_carrapichos = (converte_adc()*120)/1023;
		for(int x=0; x<num_carrapichos;x++){
			tx('*');
		}
		tx('\n');
//		setbit(PORTB,5);
//		tx((converte_adc()>>2));
//		_delay_ms(500);
//		clrbit(PORTB,5);
//		_delay_ms(500);
    }
}
