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
				double tensao_a0 = calculo_tensao(reading_A0, 1.1);
				double temperatura = tensao_a0/0.01;
				char temperatura_str[10];
				dtostrf(temperatura, 6, 2, temperatura_str);
				string_transmit("Temperatura: ");
				string_transmit(temperatura_str);
				string_transmit(" graus.");
				break;
			case '2':
				set_conversor_A1();
				unsigned int reading_A1 = converte_adc();
				double tensao = calculo_tensao(reading_A1, 5.0);
				char tensao_str[10];
				dtostrf(tensao, 6, 2, tensao_str);
				string_transmit("Tensão: ");
				string_transmit(tensao_str);
				string_transmit( " V\n");
				break;
			default:
				string_transmit("opcao invalida\n");
				break;	
		}
    }
}

