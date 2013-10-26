#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main_20 () {
	char* main_str = "This is good";
	char* sub = "is";

	int main_str_length = strlen(main_str);
	int sub_length = strlen(sub);

	int i = 0;
	int j = 0;

	int start_sub = 0;

	while (main_str[i] != '\0') {
		if (sub[j] == '\0') break;

		if(main_str[i] == sub[j]) {
			i++; j++;
		}
		else {
			// Below algorithm is WRONG. 1st character does not match NOT mean next_sub length does not match
			//if (i + sub_length < main_str_length) {
			//	i += sub_length;
			//}
			i++;
			j = 0;
			start_sub = i;
		}
		
	}

	printf ("%d\n", start_sub);
}