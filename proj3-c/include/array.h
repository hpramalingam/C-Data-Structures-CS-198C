#include <stdio.h>

#ifndef ARRAY_H
#define ARRAY_H

// fixed width for the 2D arrays
#define WIDTH 3

// goal: scales (the first N elements of) an array
// param N: number of elements to scale
// param arr: the array to scale
// param scale: the value to scale the array by
void scale(int N, int arr[], int scale);

// goal: flattens (the first N elements of) an array
// param N: number of elements to scale
// param arr: the array to flatten
// param flat: the array to store the flattened version of arr in
// assumptions:
//   arr has dimensions N by WIDTH, (arr[N][WIDTH])
//   flat has length N*WIDTH
void flatten(int N, int arr[][WIDTH], int flat[]);

#endif