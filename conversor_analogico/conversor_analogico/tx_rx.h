void tx(char c){
	while(getbit(UCSR0A,5)==0){}
	UDR0 = c;
}

char rx(){
	while(getbit(UCSR0A,7)==0){}
	return UDR0;
}