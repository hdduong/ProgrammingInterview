#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void printCharacter(char *src, int start_at) {
	
	//int i = 0;
	//char tmp_src[MAX_CHARACTER];

	if (src[start_at] == '\0') {
		//return '\0';
		printf("%s\n",src);
	}

	//strncpy(tmp_src,(src + 1), strlen(src) - 1);

	switch (src[start_at] ) {
	case '2':
		src[start_at] = 'A';
		printCharacter(src,start_at+1);
		src[start_at] = '2';

		src[start_at] = 'B';
		printCharacter(src,start_at+1);
		src[start_at] = '2';

		src[start_at] = 'C';
		printCharacter(src,start_at+1);
		src[start_at] = '2';
		break;
	case '7':

		break;
	}
}

void main_22 () {
	char src[] = "22";

	printCharacter(src,0);

}
