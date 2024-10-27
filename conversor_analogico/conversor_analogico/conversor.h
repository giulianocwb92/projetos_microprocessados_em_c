void config_ADCSRA(){
	ADCSRA = 0x87;
}

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

float calculo_tensao(unsigned int a){
	float V_i = ((float)a * 5.0)/1023.0;
	return V_i;
}