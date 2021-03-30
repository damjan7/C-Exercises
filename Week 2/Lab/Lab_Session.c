#include <stdio.h>

int main(){
	char s[] = "AAAABBBBCCCAAAEEEEDDAAEEEEEEEE";
	int i = 0;
	int counter = 1;
	while(s[i] != '\0'){
		if (s[i] == s[i+1]){
			counter++; 
		}
		else{
			printf("%c%d", s[i], counter);
			counter = 1;
		}
		i++;
	}
	
	
	return 0;
}
