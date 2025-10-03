#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include <stdbool.h>
#include "sort_helper.h"

// provided code 

// =============== Helper Functions ===============
// Name:    compare
// Desc:    A compare function which returns
//          a value (positive,negative, or 0)
//          to show if the result is >,<, or =.
//
// Input:   a and b here are generic types,
//          that is why they are 'void'
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/*** code for selection sort ****/

// Returns the minimum integer from a range in an array
// Input: array - An array of integers
//        start - Where to start looking in an array
//        stop - End of where to search. Typically the 'size' of the array.
// Output: The index in an array of the minimum value between a range [start,stop]
int findMinimum(int *array, int start, int stop)
{
    //set min value to value at start 
    int min = array[start];
    //set index of min value to start
    int indexOfMin = start;
    //loop 
    for (int i = start + 1; i < stop; i++){
        //if current is smaller than min, set min to current val
        if (array[i] < min){
            min = array[i];
            indexOfMin = i;
        }
    }
    return indexOfMin; // modify to return the index of the min value
}


// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  -  'print' tells it to print out after each interation
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void selectionSortIntegers(int *array, unsigned int size, int print)
{
    // todo: implement selection sort

    //edge case
    if (size == 0 || array == NULL) return;
    //loop through array
    for (int i = 0; i < size - 1; i++){
        //find index of min of all values after i 
        int indexOfMin = findMinimum(array, i, size);
        //swap min with value at index i
        int temp = array[indexOfMin];
        array[indexOfMin] = array[i];
        array[i] = temp;
        if (print) printIntArray(array, size);
    }
}

/***  Code for Insertion Sort ***/

// =============== Sort Function ===============
// Provided below is a sort function. I have also
// provided a template for how to document functions
// to help organize your code.
// Name: sort
// Input(s):
//  - 'array' is a pointer to an integer address.
//     This is the start of some 'contiguous block of memory' that we will sort.
//  - 'size' tells us how big the array of data is we are sorting.
//  - 'print' tells it to print out after each iteration 
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void insertionSortIntegers(int *array, unsigned int size, int print)
{
    // TODO: Implement insertion sort
    //edge case
    if (size == 0 || array == NULL) return;

    for (int i = 1; i < size; i++){
        //save current value, as we might override it
        int placeholder = array[i];
        //initiate j to i - 1
        int j = i - 1;
        //if array[j] is greater than array[i], loop to the left
        //until we find where to insert i 
        while (j >= 0 && array[j] > placeholder){
            //shift right
            array[j + 1] = array[j];
            //decrease j
            j--;
        } 
        //insert i once there are no greater values that come before 
        array[j + 1] = placeholder;
        if (print) printIntArray(array, size);
      
    }
}

/** Code for Bubble Sort (from Lab -if not compiling, comment out the internals, but leave the function definition) ***/

// =============== Sort Function ===============
// Name: bubblesort
// Desc: O(n^2) comparison sort
// param(1): 'array' is a pointer to an integer address.
//           This is the start of some 'contiguous block of memory'
//           that we will sort.
// param(2)  'size' tells us how big the array of
//           data is we are sorting.
// param(3) 'print' tells it to print out after each iteration.
// Output:   No value is returned, but 'array' should
//           be modified to store a sorted array of size.
void bubbleSortIntegers(int *array, unsigned int size, int print)
{
    // code generated from lab
    //edge case
    if (size == 0 || array == NULL) return;

    //loop
	for (int i = 0; i < size; i ++){
		//loop in order to perform swaps 
		//check if there have been any swaps
		bool noSwaps = true;
		for (int j = 0; j < size - i - 1; j++){
			//compare j with j+1, and swap if j is larger value
			//use compare helper function
			int result = compare(&array[j], &array[j + 1]);
			//if result, is more than 0, that means array[j] > array[j + 1]
			if (result > 0){
				swap(&array[j], &array[j + 1]);
				//if there was a swap, set noSwaps to false
				noSwaps = false;
			}
		
		}
		if (print) printIntArray(array, size);
		//if noSwaps is true, then we got through inner loop without any swaps
		//therefore array is already sorted
		if (noSwaps) break;
		
	}

}

// ** You will work on merge sort during the lab on Module 06 ** //

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int temp[], int l, int m, int r)
{
    
    if (arr == NULL || temp == NULL)
    {
        exit(1);
    }
    
	//edge case
    if (l > m || m + 1 > r)
        return;


    int i = l;
    int j = m + 1;
    int k = l;

    //place values in order into temp from lowest to highest
    while (i <= m && j <= r){
		//compare value on left side of array and value on right, 
		//and place in temp while incrementing necessary pointer and k 
        if (arr[i] <= arr[j]){
            temp[k] = arr[i] ;
            i++;
        }else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    //put in remaining values into temp. If right array is bigger, 
    //there will be values remaining in right,
    //or vice versa
    while (i <= m){
        temp[k] = arr[i];  
        i++; 
        k++;
    }

    while (j <= r){
        temp[k] = arr[j];  
        j++; 
        k++;
    }

    //copy values back into arr
    for (int i = l; i <= r; i++){
        arr[i] = temp[i];
    }


}

// To be built during week 6 lab
// Name: mergeSort
// Input(s):
//          (1) 'arr' is a pointer to an integer address.
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'temp' is a pointer to an integer address.
//          	This helps temporarily store the sorted subarray.
//          (3) 'l' and 'r' are integers, which are the first index and the last index of 'arr' respectively.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void merge_sort(int arr[], int temp[], int l, int r)
{
	//check if array is empty
    if (l >= r) return;

	//find mid
    int mid = (r - l) / 2 + l; 

	//sort each half
    merge_sort(arr, temp, l, mid);
    merge_sort(arr, temp, mid + 1 , r);
	
	//merge the sorted halves
    merge(arr, temp, l, mid, r);

    
}

// lab build, merge sort

void mergeSortIntegers(int *array, unsigned int size, int print)
{ // print is ignored for this one
    if (array == NULL)
    {
        exit(1);
    }
    if (size <= 1)
        return;

    int *temp = (int *)malloc(sizeof(int) * size);
    merge_sort(array, temp, 0, size - 1);
    if (print) printIntArray(array, size);
    free(temp);
}



void quickSortIntegers(int* array, unsigned int size, int print) 
{   // print is ignored as qsort doesn't use it
    qsort(array, size, sizeof(int), compare);
}

#endif