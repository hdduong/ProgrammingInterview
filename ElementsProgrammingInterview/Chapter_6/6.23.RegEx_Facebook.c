#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**************
You have to write a function checkRegex() which takes two strings as input, one string represents a regex expression and other is an input string to match with the regex expression passed as the other parameter. Return true if it matches, else false.

Regex may contain characters ‘a-z’, ‘.’ and ‘*’ where ‘.’ matches any character and ‘*’ means 0 or more occurrences of the previous character preceding it.

Examples:

1) a*b matches b,ab,aab

2) a.b matches aab, abb, acb,…, azb

3) .* matches all the valid strings formed by using the lowercase letters
**************/

int checkReg_23(char* reg, char* main) {
	
	int i = 0;
	int j = 0;

	int lenReg = strlen(reg);
	int lenMain = strlen(main); 

	char prev_reg;

	while (main[i] != '\0') {
		
		if ( (reg[j] != '*') && (reg[j] != '.') ) {
			if (reg[j] == main[i]) {
				i++; j++;
				if (reg[j] == '\0') {
					break;
				}
			}
			else if (reg[j] != main[i]) {
							
				if ( ((j + 1) <= lenReg) && (reg[j + 1] != '*')  ) {   // aab   and		aaab
					i++; j=0;
				}
				else if ( ((j + 1) <= lenReg) && (reg[j + 1] == '*')  ) {  // a*b	and		b
					j++;
				}
				else if ( (j+1) > lenReg) {   
					/*if (main[i + 1] != '\0') {
						return 0;
					}*/
					//else 
					if (main[i + 1] == '\0') { // ba* and b   // ba* and bb		1
						return 1; 
					}
				}
			}

		}

		if (reg[j] == '.') {	// a.b and aab	|| a. and ab
			i++; j++;
		}

		if (reg[j] == '*') {
			if (j == 0) { return 1;} // 1st character so should match everything

			prev_reg = reg[j-1];

			while(main[i] == prev_reg) {
				i++;
			}
			
			if (main[i] != prev_reg) {			// go out of *
				j++;
			}
		}
	} //end while

	if (reg[j] == '\0')
		return 1;

	// a* and {}; ba* {} ; bc*a* and b
	if (main[i] == '\0') {
		while (reg[j] != '\0') {
			if (reg[j] != '*') {
				if ( ( (j + 1) <= lenReg) && (reg[j + 1] != '*') ) {
					return 0;	
				}
				else if ( ( (j + 1) <= lenReg) && (reg[j + 1] == '*') ) {
					j += 2;
				}
			}
		}
		return 1;
	}
	return 0; // 1 mean true
}

void main () {
	
	char mainStr [] = "b";
	char reg [] = "bc*a*";

	int result;

	result = checkReg_23(reg, mainStr);

	printf("%d\n",result);
}