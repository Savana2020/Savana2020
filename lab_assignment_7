#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int arr[][2], int n);
void reset(int arr[][2], int n, int v);
void selectionSort(int arr[][2], int n);

int main(void) {
	int array1[9][2] = { {97,0}, {16,0}, {45,0}, {63,0}, {13,0}, {22,0}, {7,0}, {58,0}, {72,0} };
	int array2[9][2] = { {90,0}, {80,0}, {70,0}, {60,0}, {50,0}, {40,0}, {30,0}, {20,0}, {10,0} };
	int n = 9; //size of arrays

	printf("%s", "Bubble Sort array1:\n");
	bubbleSort(array1, n);
	printf("%s", "Bubble Sort array2:\n");
	bubbleSort(array2, n);

	//reset array values
	reset(array1, n, 1);
	reset(array2, n, 2);

	printArray(array1, n);
	printf("%s", "Selection Sort array1:\n");
	selectionSort(array1, n);
	printf("%s", "Selection Sort array2:\n");
	selectionSort(array2, n);
}

// A function to implement bubble sort
void bubbleSort(int arr[][2], int n)
{
	int i, j, temp, tmpC, count;
	count = 0;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j][0] > arr[j + 1][0]) {
				//then swap
				temp = arr[j][0];
				tmpC = arr[j][1];
				arr[j][0] = arr[j + 1][0];
				arr[j][1] = arr[j + 1][1];
				arr[j + 1][0] = temp;
				arr[j + 1][1] = tmpC;
				arr[j][1] = arr[j][1] + 1;
				arr[j + 1][1] = arr[j + 1][1] + 1;
				count++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d: swapped %d times\n", arr[i][0], arr[i][1]);
	}
	printf("total swaps: %d\n\n", count);
}

void reset(int arr[][2], int n, int v) {
	int a1[][2] = { {97, 0}, { 16,0 }, { 45,0 }, { 63,0 }, { 13,0 }, { 22,0 }, { 7,0 }, { 58,0 }, { 72,0 } };
	int a2[][2] = { {90, 0}, { 80,0 }, { 70,0 }, { 60,0 }, { 50,0 }, { 40,0 }, { 30,0 }, { 20,0 }, { 10,0 } };
	if (v == 1) {
		for (int i = 0; i < n; i++) {
			arr[i][0] = a1[i][0];
			arr[i][1] = a1[i][1];
		}
	}
	else if (v == 2) {
		for (int i = 0; i < n; i++) {
			arr[i][0] = a2[i][0];
			arr[i][1] = a2[i][1];
		}
	}
	
}

void selectionSort(int arr[][2], int n)
{
	int i, j, min_idx, temp, tmpC, count;
	count = 0;
	// One by one move boundary of unsorted subarray
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j][0] < arr[min_idx][0])
				min_idx = j;
		// Swap the found minimum element with the first element
		if (i != min_idx) {
			temp = arr[i][0];
			tmpC = arr[i][1];
			arr[i][0] = arr[min_idx][0];
			arr[i][1] = arr[min_idx][1];
			arr[min_idx][0] = temp;
			arr[min_idx][1] = tmpC;
			arr[i][1] = arr[i][1] + 1;
			arr[min_idx][1] = arr[min_idx][1] + 1;
			count++;
		}
		
	}

	for (i = 0; i < n; i++) {
		printf("%d: swapped %d times\n", arr[i][0], arr[i][1]);
	}
	printf("total swaps: %d\n\n", count);
}
