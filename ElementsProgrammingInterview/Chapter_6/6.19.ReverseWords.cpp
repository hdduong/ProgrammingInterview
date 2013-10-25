#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 1000


using namespace std;


// Alice likes Bob --> Bob likes Alice

char* reverseString(char* str) {
	
	int strLength = strlen(str);
	int i = strLength - 1;
	int j = 0;

	char *des = (char*) malloc(strLength);

	while (i >= 0) {
		des[j++] = str[i--];
	}

	des[j] = '\0';

	return des;

}


void reverseString2(char *str) {
	int strLength = strlen(str);
	int i = 0;
	char tmp;

	for (int i = 0; i <strLength /2; i++) {
		tmp = str[i];
		str[i] = str[strLength - 1 - i];
		str[strLength - 1 - i] = tmp;
	}

}

int countWords(char *str) {
	int count = 0;
	int i = 0;

	while(str[i] != '\0') {
		if (str[i] == ' ')
			count++;
		i++;
	}

	return count + 1;
}


void recordSpaces(char *str, int arr[]) {
	int i = 0;
	int count = 0;

	arr[count++] = 0;

	while(str[i] != '\0') {
		if (str[i] == ' ') {
			arr[count++] = i;
		}
		i++;
	}

	arr[count] = strlen(str);
}

void main_19() {
	
	//char *src = "Alice likes Bob";
	char *src = "Alice";

	

	char *des = NULL;
	char *des2 = NULL;

	int count = 0;
	int record_words[MAX_WORDS];
	int i = 0;
	int j = 0;

	char *tmp_word;
	char *tmp_reverse; 
	
	//char src[] = "Alice";
	//reverseString2(src);
	//printf("%s\n",src);

	/**********************************************
	char *str = "hello world";
is a pointer to a string literal, and can't be modified. String literals reside in read-only memory and attempting to modify them results in undefined behavior. In your case, a crash.

Since this is clearly an assignment, I won't suggest using std::string instead, since it's good to learn these things. Use:

char str[] = "hello world";
and it should work. In this case, str would be an automatic-storage (stack) variable.
	*********************************************/

	des = reverseString(src);
	printf("%s\n",des);

	count = countWords(des);
	printf("%d\n",count);

	recordSpaces(des,record_words);

	/********************************
		strcat with beauty append
	 ********************************/
	des2 = (char*) malloc(1);
	des2[0] = '\0';
	
	for (i = 0; i < count;i++) {
		//printf("%d ",record_words[i]);
		tmp_word = (char*) malloc(record_words[i+1] - record_words[i] + 1);
		int k = 0;
		
		for (j = record_words[i]; j < record_words[i + 1]; j++) {
			if (des[j] != ' ')
				tmp_word[k++] = des[j];
		}

		tmp_word[k] = '\0';
		
		tmp_reverse = reverseString(tmp_word);

		strcat(des2,tmp_reverse);
		if (i != count) {
			strcat(des2," ");
		}
	}

	printf("%s\n",des2);

}