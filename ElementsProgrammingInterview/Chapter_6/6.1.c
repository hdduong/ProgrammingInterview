#include <stdlib.h>
#include <stdio.h>


#define MAX_SIZE  20
void	
	swap2(int *a, int *b);

void dutch_national_flag(int* A, int sizeA, int index) {
	int indexValue = A[index];

	int smaller = 0;
	int larger = sizeA-1;
	int equal = 0;

	while(equal <= larger) {
		if (indexValue < A[equal])  {
			swap2(&A[equal], &A[larger--]);
			//larger--;
		}
		else if (indexValue > A[equal]) {
			swap2(&A[equal++], &A[smaller++]);
			//equal++;
		}
		else if (indexValue = A[equal] ) {
			//smaller++;
			equal++;
		}
	}
	//printf("%d\n", indexValue);

}


void swap(int **a, int **b) {
	int *tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}


void swap2(int *a, int *b) {
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;

	/************
	NOT WORK
	*************/
	//int *tmp;
	//tmp = a;
	//a = b;
	//b = tmp;

}

void main_1() {
	//------------------------------------------//
	// Array of pointers still works with swap.
	//-------------------------------------------//
	int *number_ptr;
	int number;
	int i  = 0;
	int index = 0;
	int inputChar;
	//int *A[MAX_SIZE];					// array of elements
	int B[MAX_SIZE];

	while ( (inputChar = getchar()) && (inputChar != '\n') ) { // enter = 10 \n. Get all input at one then process each

		if ((inputChar >= '0') && (inputChar <= '9')) {        // a number
			//number_ptr = (int*) malloc(sizeof(int));
			//*number_ptr =  inputChar - '0';
			//A[index] = number_ptr;

			number = inputChar - '0';
			B[index] = number;
			index++;
		}
	}
	
	
	//for (i= 0; i < index; i++) {
	//	printf("%d\n",*A[i]);
	//}

	//swap(&A[1], &A[2]);

	//for (i= 0; i < index; i++) {
	//	printf("%d\n",*A[i]);
	//}

	printf ("%s","Original: ");
	for (i= 0; i < index; i++) {
		printf("%d ",B[i]);
	}
	printf ("\n");
	//swap2(&B[1], &B[2]);

	dutch_national_flag(B,index,1);

	printf ("%s","After: ");
	for (i= 0; i < index; i++) {
		printf("%d ",B[i]);
	}
	printf ("\n");

	//for (i= 0; i < index; i++) {
	//	free(A[i]);
	//}

	
	printf("%s\n","End of test...");
}