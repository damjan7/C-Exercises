#include <stdio.h>

int iterativeFirstUpper(char str[]){
	int i = 0;
	while(str[i] != '\0'){
		if (str[i] >= 'A' && str[i] <= 'Z'){
		return i;
		}
		++i;
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
	int a = iterativeFirstUpper("hjkl Hnj nJNJAMAs");
	printf("%d\n", a);
	
	int b = recursiveFirstUpper("hjkl Hnj nJNJAMAs", 0);
	printf("%d", b);
	
	//char newstr[] = "Hello";
	//printf("%s", newstr);

	return 0;
}
