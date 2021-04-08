#include <stdio.h>

int main(){
	double d = 24.25;
	int i = 19;
	char ch[] = "poppie";
	
	double *p_d = &d;
	int *p_i = &i;
	char *p_ch = &ch;
	
	printf("%d\n", i); //value of int i
	printf("%p\n", &i); //address of int i
	printf("%p\n\n", &*p_i); //these and one above return the same
	//this makes sense because *p_i returns the value of i
	// and & then returns its address :) :) :) :) :) 
	printf("%p\n", &p_i);
	printf("%p\n", p_i);
	printf("%p\n\n", *p_i);
	
	printf("%lu\n", sizeof(i));
	printf("%lu\n", sizeof(p_i)); //size of integer pointer is 8 bytes
	printf("%lu\n", sizeof(ch));

	//char
	printf("char: \n");
	printf("%p \n", p_ch);
	printf("%p\n\n", &ch);
	
	//testing
	printf("integer array testing...\n");
	int arr[] = {1,2,3};
	int *ptr = arr;
	printf("%p\n", ptr);
	printf("%d\n", *(ptr+2) );

	
	return 0;
}
