#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //strlen. Notice string class is only in C++




//input: aaaabcccaa
//output: pointer to 4a1b3c2a 

char *encode(char *str) {
	int i = 0;
	int j = 0;
	int count = 0;
	int totalUsedDest = 0;
	char new_character = str[0];
	
	char *strCount = (char*) malloc(strlen(str));

	char *dest = (char*) malloc(strlen(str));

	while (str[i] != '\0') {
		if (new_character == str[i] ) {
			count ++;
		}

		else if (new_character != str[i]) {			// new character found
			//count > 10 > 100
			sprintf(strCount, "%d",count);			// write to buffer -->  convert integer to string: INTERESTING

			j = 0;
			while (strCount[j] != '\0') {
				dest[totalUsedDest++] = strCount[j++];
			}
			
			dest[totalUsedDest++] = new_character;

			new_character = str[i];
			count = 1;							// count current different character
		}

		i++;
	}
	sprintf(strCount, "%d",count);			// write to buffer -->  convert integer to string: INTERESTING
	j = 0;
	while (strCount[j] != '\0') {
		dest[totalUsedDest++] = strCount[j++];
	}
			
	dest[totalUsedDest++] = new_character;

	dest[totalUsedDest] = '\0';
	
	free(strCount);

	return dest;

}
	
//input:  4a1b3c2a 
//output: pointer to aaaabcccaa 
char* decode(char *str) {
	int i = 0;
	int j = 0;
	int count = 0;
	int totalDest = 0;								//number of charcters in destination
	char *strCount = (char*)malloc(strlen(str));
	char *dest = (char*)malloc(strlen(str));

	char *tmp_part = NULL;
	char *tmp_whole = NULL;

	while (str[i] != '\0') {
		if ((str[i] <='9') && (str[i] >= '0')) {
			strCount[j] = str[i];
			j++;
		}
		else {		//character								
			
			j = 0; //reset count for each character
			count += atoi(strCount);
			dest[totalDest] = '\0';
			totalDest += count;
			
			tmp_part = (char*)malloc(count + 1); // + 1 for \0

			while(j < count) {
				tmp_part[j] = str[i];
				j++;
			}
			tmp_part[j] = '\0';				// end of string
			count = 0;
			j = 0;							//reset count for each character
			
			//if (totalDest > strlen(str) ) {				
			//	tmp_whole = strdup(dest);
			//	free(dest);
			//	dest = (char*)malloc(totalDest);
			//	strcpy(dest,tmp_whole);
			//	free(tmp_whole);
			//}

			/*************************************************
				strcat automatically extend memory needed
			**************************************************/

			strcat(dest,tmp_part);

			free(tmp_part);
		}
		i++;

	}
	return dest;
}

void main_18 () {
	char *encodingString = "aaaaaabcccaa";
	char *encodingStringResult; 
	//char *decodingSring = "2e5f";
	char *decodingSringResult; 

	printf("%s\n",encodingString);

	encodingStringResult = encode(encodingString);
	printf("%s\n",encodingStringResult);

	//printf("%s\n",encodingStringResult);
	decodingSringResult = decode(encodingStringResult);
	printf("%s\n",decodingSringResult);
	
}