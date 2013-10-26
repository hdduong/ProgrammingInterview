#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void replaceString(char *src) {
	int i = 0;
	int j = 0;
	int k = 0;
	int src_length = strlen(src);

	while(src[i] != '\0') {
		if (src[i] == 'a') {
			j = strlen(src);

			src[j+1] = '\0';
			while ( j > i) {
				//src[j] = src[j];
				k = j;
				//j--;
				src[k] = src[--j];
				k = j;
			}
			src[j] = '\0';

			src[i++] = 'd';
			src[i] = 'd';
		}
		i++;
	}
}

void removeString(char* src) {
	// Remove b on string once. Only allow one iteration

	int i = 0;
	int j = 0;

	while (src[i] != '\0') {
		if (src[i] != 'b') {
			src[j++] = src[i++];
		}
		else if (src[i] == 'b') { 
			i++;
		}
	}
	src[j] = '\0';
}

void main() {
	char src[] = "aabcdd";

	replaceString(src);

	removeString(src);

	printf("%s\n",src);

	
	printf("%d\n",strlen(src));


}