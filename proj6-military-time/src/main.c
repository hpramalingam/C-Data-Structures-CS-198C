#include <string.h>
#include "military_time.h"

// helper for checking values of Times
int teq(struct Time* t, int h, int m, int s) {
  return get_hour(t) == h && get_min(t) == m && get_sec(t) == s;
}

// main function for non-test code
// This exists solely for the benefit of the students to test their own code
int main() {
  struct Time t1 = create_time(3, 14, 15);

  printf("Time 1 has time %i:%i:%i (should be 3:14:15) %s\n", get_hour(&t1),
         get_min(&t1), get_sec(&t1), teq(&t1, 3, 14, 15) ? "ok" : "INCORRECT");

  struct Time t2 = create_time(3, 14, 15);
  set_hour(&t2, 9);
  set_min(&t2, 26);
  set_sec(&t2, 53);

  printf("Time 2 has time %i:%i:%i (should be 9:26:53) %s\n", get_hour(&t2),
         get_min(&t2), get_sec(&t2), teq(&t2, 9, 26, 53) ? "ok" : "INCORRECT");

  struct Time dt = elapsed_time(&t1, &t2);
  printf("elapsed_time(&t1, &t2) is %i:%i:%i (should be 6:12:38) %s\n",
         get_hour(&dt), get_min(&dt), get_sec(&dt),
         teq(&dt, 6, 12, 38) ? "ok" : "INCORRECT");

  dt = elapsed_time(&t2, &t1);
  printf("elapsed_time(&t2, &t1) is %i:%i:%i (should be 17:47:22) %s\n",
         get_hour(&dt), get_min(&dt), get_sec(&dt),
         teq(&dt, 17, 47, 22) ? "ok" : "INCORRECT");

  char str[] = "0123456789";
  remove_substr(str, 4, 3);
  printf("str: %s (should be 0123789) %s\n", str,
         !strcmp(str, "0123789") ? "ok" : "INCORRECT");
  remove_substr(str + 1, -1, 2);
  printf("str: %s (should be 0123789) %s\n", str,
         !strcmp(str, "0123789") ? "ok" : "INCORRECT");
  remove_substr(str, 5, 3);
  printf("str: %s (should be 01237) %s\n", str,
         !strcmp(str, "01237") ? "ok" : "INCORRECT");
}
