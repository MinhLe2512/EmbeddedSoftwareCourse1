/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdlib.h>
#include <stdio.h>
#include "stats.h"
#include <string.h>

/* Size of the Data Set */
#define SIZE (40)

void swap(int* a, int* b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

int partition(int* array, int low, int high) {
	int pivot = array[high];
	
	int l = low - 1;
	for (int i = low; i < high; i++) {
		if (array[i] < pivot) {
			l++;
			swap(&array[i], &array[l]);
		}

	}
	swap(&array[l + 1], &array[high]);
	return l + 1;
}

void quickSort(int* array, int low, int high) {
	if (low < high) {
		int pivot = partition(array, low, high);
		quickSort(array, low, pivot - 1);
		quickSort(array, pivot + 1, high);
	}
}

void print_statistics(int* array, int len) {
	printf ("Find mean: ");
	printf("%f", find_mean(array, len));
	printf ("\n");
	
	printf ("Find median: ");
	printf("%d", find_median(array, len));
	printf ("\n");
	
	printf ("Find min: ");
	printf("%d", find_minimum(array, len));
	printf ("\n");
	
	printf ("Find max: ");
	printf("%d", find_maximum(array, len));
	printf ("\n");
}
void print_array(int* array, int len) {
	for (int index = 0; index < len; index++) { 
		printf("%d", array[index]);
		printf(" ");
	}
}
double find_mean(int* array, int len) {
	int median = 0;
	for (int index = 0; index < len; index++) { 
		median += array[index];
	}
	
	return (double)median / (double)len;
}
int find_median(int* array, int len) {
	int *copyArr = malloc(len * sizeof(int));
	memcpy(copyArr, array, len * sizeof(int));
	
	quickSort(copyArr, 0, len - 1);
	
	// for (int i = 0; i < len; i++) {
		// printf("%d", copyArr[i]);
		// printf(" ");
	// }
	
	int median = copyArr[(len - 1) / 2];
	free(copyArr);
	return median;
}
int find_maximum(int* array, int len) {
	int *copyArr = malloc(len * sizeof(int));
	memcpy(copyArr, array, len * sizeof(int));
	
	quickSort(copyArr, 0, len - 1);
	
	int max = copyArr[len - 1];
	free(copyArr);
	return max;
}
int find_minimum(int* array, int len) {
	int *copyArr = malloc(len * sizeof(int));
	memcpy(copyArr, array, len * sizeof(int));
	
	quickSort(copyArr, 0, len - 1);
	
	int min = copyArr[0];
	free(copyArr);
	return min;
}
void sort_array(int* array, int len) {
	quickSort(array, 0, len - 1);
}

void main() {

  unsigned int test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */


/* Add other Implementation File Code Here */
	print_array(test, SIZE);
	printf ("\n");
	
	print_statistics(test, SIZE);
	
	// print_array(test, SIZE);
	// printf ("\n");
}
