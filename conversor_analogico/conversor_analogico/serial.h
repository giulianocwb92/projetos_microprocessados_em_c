void config_57600_8_n_1(){
	UBRR0H = 0x00;
	UBRR0L = 0x22;
	UCSR0C = 0x06;
	UCSR0B = 0x18;
	UCSR0A = 0x22;
}

void config_ADCSRA(){
	ADCSRA = 0x87;
}