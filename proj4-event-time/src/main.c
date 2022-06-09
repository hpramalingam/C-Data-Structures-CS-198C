#include "event.h"

// helper for checking values of Times
int teq(struct Time t, int h, int m, int s) {
  return get_hour(t) == h && get_min(t) == m && get_sec(t) == s;
}

// helper for checking values of Events
int eeq(struct Event e, int i, int h, int m, int s) {
  return get_event_id(e) == i && teq(get_event_time(e), h, m, s);
}

// main function for non-test code
// This exists solely for the benefit of the students to test their own code
int main() {
  struct Event e1 = create_new_event(3, 14, 15, 1);
  struct Time t1 = get_event_time(e1);

  printf(
      "Event %i (should be Event 1) has time %i:%i:%i (should be 3:14:15) %s\n",
      get_event_id(e1), get_hour(t1), get_min(t1), get_sec(t1),
      eeq(e1, 1, 3, 14, 15) ? "ok" : "INCORRECT");

  struct Event e2 = create_new_event(9, 26, 53, 2);
  struct Time t2 = get_event_time(e2);

  printf(
      "Event %i (should be Event 2) has time %i:%i:%i (should be 9:26:53) %s\n",
      get_event_id(e2), get_hour(t2), get_min(t2), get_sec(t2),
      eeq(e2, 2, 9, 26, 53) ? "ok" : "INCORRECT");

  struct Time dt = elapsed_time(e1, e2);
  printf("elapsed_time(e1, e2) is %i:%i:%i (should be 6:12:38) %s\n",
         get_hour(dt), get_min(dt), get_sec(dt),
         teq(dt, 6, 12, 38) ? "ok" : "INCORRECT");

  dt = elapsed_time(e2, e1);
  printf("elapsed_time(e2, e1) is %i:%i:%i (should be 6:12:38) %s\n",
         get_hour(dt), get_min(dt), get_sec(dt),
         teq(dt, 6, 12, 38) ? "ok" : "INCORRECT");
}
