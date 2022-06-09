#include "math.h"

// main function for non-test code
// This exists solely for the benefit of the students to test their own code
int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Wrong number of arguments, should be:\n");
    printf("./math_app [input file] [output file]\n");
    exit(EXIT_FAILURE);
  }

  solve(argv[1], argv[2]);
}
