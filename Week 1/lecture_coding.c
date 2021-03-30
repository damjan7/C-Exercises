#include <stdio.h>

void RevBubbleSort(char s[], int n){
	int i;
	int j;
	char t;
	for (i=1; i<n; ++i){
		for(j=n-1; j>i-1; --j){  ///I made the mistake for(j=i; j<n; ++1), but this doesn't really bubble the smallest el!! try it!!
			if (s[j] < s[j-1]){
				t = s[j];
				s[j] = s[j-1];
				s[j-1] = t;
			}
		}
	}
	
	for (i=0; i<n; ++i){
		printf("%c ", s[i]);
	}
}


void RevSelSort(char s[], int n){
	int i;
	int j;
	int k;
	char t;
	for(i=0; i<n; ++i){
		k = i;
		for(j=2; j<n-i; ++j){
			if (s[j] > s[k]){
				j = k;
			}
		}
		t = s[i];
		s[i] = s[k];
		s[k] = t;
	}
	for (i=0; i<n; ++i){
		printf("%c ", s[i]);
	}
}

int main(){
	char str1[] = "sorting";
	int i;
	for (i=0; i<7; ++i){
		printf("%c ", str1[i]);
	}
	printf("\n");
	RevBubbleSort(str1, 7);
	printf("\n");
	RevSelSort(str1, 7);	
	return 0;
}
