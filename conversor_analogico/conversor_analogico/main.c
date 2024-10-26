#define F_CPU	16000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "bit_a_bit.h"
#include "serial.h"
#include "tx_rx.h"
#include "string_transmit.h"

int main(void)
{
	config_57600_8_n_1();
	config_ADCSRA();
    char mensagem[40] = "Selecione uma opcao:\n";
	char opcao_1[40]  = "1 - Medir temperatura (LM35)\n";
	char opcao_2[40]  = "2 - Medir tensão (Potenciômetro)\n";
    while (1){
		string_transmit(mensagem);
		string_transmit(opcao_1);
		string_transmit(opcao_2);
		char opcao = rx();
    }
}

