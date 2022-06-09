#include "gpa.h"

// A struct defined in this main.c file.
struct person the_person;

// A main function with a simple test.
// Correct output will display Alice.
int main() {
  struct person Alice = {"Alice Smith", 23, 3.5D};
  struct person Bob = {"Bob Jones", 22, 3.3D};
  the_person = (struct person){"Somebody Else", 100, 0.1D};
  struct person friends[] = {Alice, Bob};
  find_the_person(friends, 2);
  printf("find_the_person found: '%s', %d, %f\n", the_person.name,
         the_person.age, the_person.GPA);
  return 0;
}
