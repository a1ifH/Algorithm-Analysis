/*************************************************************************
*	Author: Alif Hossain
*	Task: 	Heap sort algorithm performance analysis
**************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 7

// this seed value is used so that same random numbers are generated each time
// Note: all three algorithms work on hte same data due to the see, allowing efficient comparison
int seed_value = 10432;
int maximum = 100000000;

/***************************************************************/
// Random array generator of size "size"
int* generate_random(int size)
{
	srand(seed_value);

	// creating the array.
	int* array = malloc(size * sizeof(int));
	int i;
	// initializing it with random numbers.
	for (i = 0; i < size; i++)
	{
		array[i] = rand() % maximum;
	}
	
	return array;
}
/***************************************************************/
// This function checks the heap's property
void heap_tester(int* arr, int n, int i)
{
	int largest = i;
	// left & right
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	// check if left is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;
	// check if right is larger than root
	if (r < n && arr[r] > arr[largest])
		largest = r;
	
	// if root isnt largest then change is required.
	if (largest != i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;

		// recursive call
		heap_tester(arr, n, largest);
	}
}

void heap_sort(int* arr, int n)
{
	int i;
	// creating the heap
	for (i = n / 2 - 1; i >= 0; i--)
		heap_tester(arr, n, i);
	// extracting the max (sorting)
	for (i = n - 1; i > 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		
		heap_tester(arr, i, 0);
	}
}

/*************************************************************/
// Calculating and displaying the time taken
int main()
{
	printf("HEAP SORT\n\n");
	// array holds the 7 data sizes
  	// ranging from 100 to 100 million
	int sizes[SIZE] = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
	int i, j;
	
	// iterating through each size
	for (i = 0; i <SIZE; i++)
	{
		// array creation
		int* array = generate_random(sizes[i]);
		// start time
		clock_t startTime = clock();
		// start sorting
		heap_sort(array, sizes[i]);
		// stop time
		clock_t endTime = clock();

		// converting to get number of seconds
		double timeUsed = (double)(endTime - startTime)/CLOCKS_PER_SEC;

		// displaying
		printf("SIZE: %d, TIME TAKEN: %.3f SECONDS\n", sizes[i], timeUsed);
	}

	return 0;
}
