#include <stdio.h>
#include <stdlib.h>

/************************************
Rotate right array with k
1 2 3 4 (rotate k = 1) -> 4 1 2 3 
*************************************/

void swap3(int *a, int *b) {
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}


int gcd(int a, int b) {
	if (b == 0)
		return a;
	else return gcd(b, a%b);
}

// size of array
// k: rotate k steps right
void rotateArray(int a[], int size, int k) {
	
	int steps = gcd(size,k);
	int loop = 0;
	int new_position = 0;
	int number_elements_each_step = (size / steps); // 12 / 3

	for (loop = 0; loop < steps; loop++) {

		//int i = size - loop - 1; // bigger go left (reverse of geek) here rotate right, geek rotate left
		//int j = i;
		/*****
			below code not work because of lacking temp variable
		*****/
		//while( (j - number_elements_each_step) >= 0) {
		//	swap3(&a[j], &a[j - number_elements_each_step]);	
		//	j = j - number_elements_each_step;
		//}


		/*********
			working code
		*********/
		int i = loop;
		int j = 0;
		int tmp = a[i];

		while( j < number_elements_each_step) {
			/*if ( (k == 1)  || (k == (size - 1)) ) {
				swap3(&tmp, &a[(i + j*number_elements_each_step) % (size - 1)]);
			}
			else */
				swap3(&tmp, &a[(i + j*k) % size]);	
			//j = j - number_elements_each_step;
			j ++;
		}
		a[i] = tmp;
	}
}

void main_14() {
	//int iGcd = gcd(9,3);
	//int arr[] = {1, 2, 3 ,4 ,5,6, 7, 8, 9, 10, 11, 12 };
	int arr[] = {1 , 2 ,3 ,4};
	int arrSize = 4; 
	int i = 0;

	//rotateArray(arr,4,2);
	
	//rotateArray(arr,4,3);

	rotateArray(arr,4,1);

	for (i = 0; i< arrSize; i ++ ) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

