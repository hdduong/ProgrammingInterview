#include <stdio.h>
#include <stdlib.h>

#define N 4

void printColumnLR(int A[][N], int row, int left_column, int right_column) { // incldue start and end column
	int i = left_column;

	while (i <= right_column) {
		printf ("%d ", A[row][i]);
		i++;
	}
}

void printColumnRL(int A[][N], int row, int right_column, int left_column) { // incldue start and end column
	int i = right_column;

	while (i >= left_column) {
		printf ("%d ", A[row][i]);
		i--;
	}
}



void printRowDown(int A[][N], int column, int start_row, int end_row) { // incldue start and end row
	int i = start_row;

	while (i  <= end_row) {
		printf ("%d ", A[i][column]);
		i++;
	}
}


void printRowUp(int A[][N], int column, int bottom_row, int top_row) { // incldue start and end row
	int i = bottom_row;

	while (i  >= top_row) {
		printf ("%d ", A[i][column]);
		i--;
	}
}

void main_15() {
	//int A[N][N] = { {1,2,3},{4,5,6},{7,8,9} };

	int A[N][N] = { {1,2,3, 4},{5,6,7, 8},{9, 10, 11, 12},{13, 14, 15, 16} };

	int i, j = 0;
	
	int start_row = 0; 
	int end_row = N - 1;
	int start_column = 0;
	int end_column = N - 1; // number of elements in each column/row


	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}

	printf("\n");


	while (1) {
		//
		printColumnLR(A,start_row,start_column,end_column);
		start_row++;
		if (start_row > end_row) break;

		printRowDown(A,end_column,start_row,end_row);
		end_column--;
		if (start_column > end_column) break;

		printColumnRL(A,end_row,end_column, start_column);
		end_row--;
		if (start_row > end_row) break;

		printRowUp(A,start_column,end_row,start_row);
		start_column++;
		if (start_column > end_column) break;
	}

	printf("\n");
}