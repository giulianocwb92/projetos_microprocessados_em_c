void string_transmit(char* data){
	int x = 0;
	while (data[x] != '\0'){
		tx(data[x]);
		x++;
	}
}
