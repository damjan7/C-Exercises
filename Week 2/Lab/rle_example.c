#include <stdio.h>

int main() {
	char input_string[] = "AAAAABBBBCCAAABDDDBDDCC";
	printf("%s\n", input_string);
	int i = 0;
	int counter = 1;
	while (input_string[i] != '\0') {
		if (input_string[i] == input_string[i+1]) {
			counter++;
		}
		else {
			printf("%c", input_string[i]);
			if (counter > 1) {
				printf("%d", counter);
			}
			counter = 1;
		}
		i++;
	}
	return 0;
}
