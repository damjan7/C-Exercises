void printRev(char str[], int len){
	char *ptr = str;
	for (int i=len; i>=0; --i){
		printf("%c", *(ptr+i));
	}
}

int main(){
	char str[] = "hello";
	int cnt = 0;
	char *ptr = str;
	while(*ptr != '\0'){
		++cnt;
		printf("%c", *(ptr));
		ptr = ptr + 1;
	}
	printf("%d", cnt);
	
	printRev(str, 5);
	
	return 0;
}
