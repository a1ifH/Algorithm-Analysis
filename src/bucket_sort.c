/********************************************************************************
*   Author: Alif Hossain
*   Task: Bucket sort algorithm performance analysis
**********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 7

// this seed value is used so that the same numbers are generated each time
// Note: all three algorithm work on the same data, allowing efficient comparison
int seed_value = 10432;

// set a maximum for the random numbers
int maximum = 1000000;

/*********************************************************************************/
// Random array generator of size "size"
int* generate_random(int size)
{
  srand(seed_value);

  // creating the array.
  int* array = malloc(size * sizeof(int));
  int i;
  for (i = 0; i < size; i++)
  {
    array[i] = rand() % maximum;
  }

  return array;
}

/*****************************************************************************/
// function for sorting the array using bucket sort (bucket sort algorithm)
void bucketSort(int* array, int n)
{  
  int max = 0;
    int i, j;

    for (i = 0; i < n; i++)
    {
      if (array[i] >= max)
        max = array[i];
    }
    max++;

    int count[max]; 
    for (i = 0; i < max; i++)
        count[i] = 0;
 
    for (i = 0; i < n; i++)
        (count[array[i]])++;
 
    for (i = 0, j = 0; i < max; i++)  
        for(; count[i] > 0; (count[i])--)
            array[j++] = i;
}

/*****************************************************************************/
// Calculating and printing time taken
int main()
{
  printf("BUCKET SORT\n\n");

  // array holds the 5 sizes of data
  // ranging from 100 to 100 million
  int sizes[SIZE] = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
  int i, j;
  
  // go through each data size
  for (i = 0; i <SIZE; i++)
  {
    // array creation
    int* array = generate_random(sizes[i]);
    // start timing
    clock_t startTime = clock();
    // start sorting
    bucketSort(array, sizes[i]);
    // end timing
    clock_t endTime = clock();

    // number of seconds conversion
    double timeUsed = (double)(endTime - startTime)/CLOCKS_PER_SEC;

    // displaying
    printf("SIZE: %d, TIME TAKEN: %.3f SECONDS\n", sizes[i], timeUsed);
  }

  return 0;
}
