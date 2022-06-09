#include "array.h"

// goal: scales (the first N elements of) an array
// param N: number of elements to scale
// param arr: the array to scale
// param scale: the value to scale the array by
//
// TODO: Complete the function
void scale(int N, int arr[], int scale) {
  for (int i = 0; i < N; i++) {
    int stor = arr[i]*scale;
    arr[i] = stor;
  }
}

// goal: flattens (the first N rows of) an array
// param N: number of elements to scale
// param arr: the array to flatten
// param flat: the array to store the flattened version of arr in
// assumptions:
//   arr has dimensions N by WIDTH, (arr[N][WIDTH])
//   flat has length N*WIDTH
// example:
//   inputs:
//     N = 4
//     arr = [[ 1,  2,  3],
//            [ 4,  5,  6],
//            [ 7,  8,  9],
//            [10, 11, 12]]
//     flat = ??? (not relevant)
//   outcomes:
//     flat = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
//
// TODO: Complete the function
void flatten(int N, int arr[][WIDTH], int flat[]) {
  for (int i = 0; i < N; i++) {
    for (int j =0; j < WIDTH; j++) {
      flat[i*WIDTH + j] = arr[i][j];
      
    }
  }
  
}
