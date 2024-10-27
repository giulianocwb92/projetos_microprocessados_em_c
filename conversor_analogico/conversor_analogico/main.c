#define F_CPU	16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

// Header files para organização do código.
#include "bit_a_bit.h"
#include "serial.h"
#include "string_transmit.h"
#include "conversor.h"

int main(void)
{
	config_57600_8_n_1();
	config_ADCSRA();
    while (1){
		welcome_message();
		char opcao = rx();
		switch(opcao){
			case '1':
				set_conversor_A0();
				unsigned int reading_A0 = converte_adc();
				//string_transmit("opcao 1\n");
				break;
			case '2':
				set_conversor_A1();
				unsigned int reading_A1 = converte_adc();
				float tensao = calculo_tensao(reading_A1);
				string_transmit("Tensão: ");
				char tensao_str[10];
				dtostrf(tensao, 6, 2, tensao_str);
				string_transmit(tensao_str);
				tx(' ');
				tx('V');
				tx('\n');
				//string_transmit("opcao 2\n");
				break;
			default:
				string_transmit("opcao invalida\n");
				break;	
		}
    }
}

