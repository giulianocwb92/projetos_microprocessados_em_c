void tx(char c){
	while(getbit(UCSR0A,5)==0){}
	UDR0 = c;
}

char rx(){
	while(getbit(UCSR0A,7)==0){}
	return UDR0;
}

void string_transmit(const char* data){
	int x = 0;
	while (data[x] != '\0'){
		tx(data[x]);
		x++;
	}
}

void welcome_message(){
	char mensagem[40] = "Selecione uma opcao:\n";
	char opcao_1[40]  = "1 - Medir temperatura (LM35)\n";
	char opcao_2[40]  = "2 - Medir tensão (Potenciômetro)\n";
	string_transmit(mensagem);
	string_transmit(opcao_1);
	string_transmit(opcao_2);
}