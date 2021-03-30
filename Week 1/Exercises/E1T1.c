#include <stdio.h>

int LengthStr(char s[1000]){
	int i;
	for (i=0; s[i] != '\0'; ++i){
		/* I think this is equivalent to "while" we're not at s[i] = '\0' */
	}
	return i;
}

void ReverseString(char s[1000]){
	int sLength;
	sLength = LengthStr(s);
	int i;
	char newStr[sLength];
	for (i = 0; i < sLength; ++i){
		newStr[i] = s[sLength-i-1];
	}
	printf(newStr);  
}

void main(){
	ReverseString("abc");
}
