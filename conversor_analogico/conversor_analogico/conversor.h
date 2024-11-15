#ifndef CONVERSOR_H_
#define CONVERSOR_H_

void config_ADCSRA();
void set_conversor_A0();
void set_conversor_A1();
unsigned int converte_adc();
float calculo_tensao(unsigned int a, float b);

#endif