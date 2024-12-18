/*******************************************************************************
*	Author: Alif Hossain
*	Task:	Selection sort algorithm performance analysis
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 7

// this seed value is used so that the same random numbers are generated each time
// Note: all three algorithms work on the same data due to the seed, allowing efficient comparison
int seed_value = 10432;

// set a maximum for the random numbers
int maximum = 100000000;

/*****************************************************************************/
// Random array generator of size "size"
int* generate_random(int size)
{
	srand(seed_value);
	
	// make the array
	int* array = malloc(size * sizeof(int));
	int i;
	for (i = 0; i < size; i++)
	{
		array[i] = rand() % maximum;
	}

	return array;
}
/**************************************************************************/
// function for sorting the array of "size" using selection sort
void selection_sort(int* array, int size)
{
	int i,j;
	for (i = 0; i < size; i++)
	{
		// things holds the minimum value's index from i+1 till size.
		int min_index = i;
		for (j = i+1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		// swapping
		int temp = array[min_index];
		array[min_index] = array[i];
		array[i] = temp;
	}
}
/****************************************************************************/
// Calculating and printing time taken
int main()
{
	printf("SELECTION SORT\n\n");
	// array holds the 7 sizes of data
	// ranging from 100 to 100 million
	int sizes[SIZE] = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
	int i;

	// go through each data size
	for (i = 0; i < SIZE; i++)
	{
		//array creation
		int* array = generate_random(sizes[i]);
		
		//start the timing
		clock_t startTime = clock();
		//start sorting
		selection_sort(array, sizes[i]);
		clock_t endTime = clock();
		// number of seconds conversion
		double timeUsed = (double)(endTime - startTime)/CLOCKS_PER_SEC;
		
		printf("SIZE: %d, TIME TAKEN: %.3f SECONDS\n", sizes[i], timeUsed);
	}
	
	return 0;
}
