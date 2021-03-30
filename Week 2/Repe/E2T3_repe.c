#include <stdio.h>

int findStrLength(char str[]){
	int counter=0;
	while (str[counter] != '\0'){
		++counter;
	}
	return counter;
}

int iterativeFirstUpper(char str[]){
	int strlen = findStrLength(str);
	for(int i=0; i<strlen; ++i){
		if (str[i] >= 'A' && str[i] <= 'Z'){
			return i;
		}
	}
	return -1;
}

int recursiveFirstUpper(char str[], int pos){
	if (str[pos] == '\0'){
		return -1;
	}
	if (str[pos] >= 'A' && str[pos] <= 'Z'){
			return pos;
	}
	return recursiveFirstUpper(str, pos+1);
}

int main(){
	char test_str[1000] = "hello wOrld";
	int iter_idx = iterativeFirstUpper(test_str);
	int rec_idx = recursiveFirstUpper(test_str, 0);
	printf("Iterative Solution: %d\n", iter_idx);
	printf("Iterative Solution: %d\n", rec_idx);
	
	return 69;
}
