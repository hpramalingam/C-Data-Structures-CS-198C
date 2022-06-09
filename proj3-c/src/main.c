#include "array.h"

// main function for non-test code
// This exists solely for the benefit of the students to test their own code
int main() {
  int a1_io[] = {1, 2, 4, 8};    // input (and output in spirit)
  int a1_soln[] = {2, 4, 8, 8};  // solution

  scale(3, a1_io, 2);  // should only affect first 3 entries
  for (int i = 0; i < 4; i++) {
    printf("a1_io[%i] = %i (should be %i) %s\n", i, a1_io[i], a1_soln[i],
           a1_io[i] == a1_soln[i] ? "ok" : "INCORRECT");
  }
  printf("\n");

  int a2_in[][WIDTH] = {
      {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};  // input
  // partial initialisation should result in all 0s
  //   (see C99 standard sections 6.7.8.21 and 6.7.8.10)
  int a2_out[2 * WIDTH + 1] = {0};        // output-to-be
  int a2_soln[] = {1, 2, 3, 4, 5, 6, 0};  // solution

  flatten(2, a2_in, a2_out);  // should only affect first 6 entries of a2_out
  for (int i = 0; i < 7; i++) {
    printf("a2_out[%i] = %i (should be %i) %s\n", i, a2_out[i], a2_soln[i],
           a2_out[i] == a2_soln[i] ? "ok" : "INCORRECT");
  }
}
