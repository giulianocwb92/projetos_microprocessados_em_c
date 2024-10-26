void welcome_message(){
	char mensagem[40] = "Selecione uma opcao:\n";
	char opcao_1[40]  = "1 - Medir temperatura (LM35)\n";
	char opcao_2[40]  = "2 - Medir tensão (Potenciômetro)\n";
	string_transmit(mensagem);
	string_transmit(opcao_1);
	string_transmit(opcao_2);
}