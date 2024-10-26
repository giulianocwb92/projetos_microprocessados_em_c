void set_conversor_A0(){
	ADMUX = 0xC0;
}

void set_conversor_A1(){
	ADMUX = 0x41;
}

unsigned int converte_adc(){
	_delay_us(10);
	setbit(ADCSRA, 6);
	while(getbit(ADCSRA, 6)==1){}
	return ADC;
}
