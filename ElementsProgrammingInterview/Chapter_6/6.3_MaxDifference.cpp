#include <stdlib.h>
#include <stdio.h>


// naive way
// O(n^2) time complexity
void maxDiff_1(int arr[], int arr_size,int *min_index, int *max_index) {
	int max_diff = 0;


	for (int i = 0; i < arr_size - 1; i++) {
		for (int j = i+ 1; j < arr_size; j++) {
			if ( (arr[i] < arr[j]) && ( (arr[j] - arr[i]) > max_diff) ) {
				max_diff = arr[j] - arr[i];
				*min_index = i;
				*max_index = j;
			}

		} // end for j
	} // end for i
}


//

void maxDiff_2(int arr[], int arr_size, int *min_index, int *max_index) {
	int min_index_so_far = 0;
	int max_value_so_far = 0;

	int index = 1;

	*min_index = 0;
	*max_index = 0;

	while (index < arr_size) {
		if ( (arr[index] > arr[min_index_so_far]) &&
			 (arr[index] > arr[*min_index]) && 
			 ((arr[index] - arr[min_index_so_far]) > max_value_so_far ) )
		{
			//min_index_so_far = index;
			max_value_so_far = arr[index] - arr[min_index_so_far];
			*min_index = min_index_so_far;
			*max_index = index;
		}
		else if (arr[index] < arr[min_index_so_far] ) {
			min_index_so_far = index;
		}

		index ++;
	}
	
}


void main_1() {
	int min_index = 0;
	int max_index = 0;
	int max_diff = 0;

	int arrayA[] = {10, 12, 14, 8, 5, 16 };
	
	// maxDiff_1(arrayA, 6, &min_index, &max_index);
	maxDiff_2 (arrayA, 6, &min_index, &max_index);
	
	max_diff = arrayA[max_index] - arrayA[min_index];

	printf("%d, %d, %d \n", min_index, max_index, max_diff);


}