#include "event.h"

// Creates a Event struct given the hour, minute, and second, and event id
//   param hour: int representing the hour 0-23
//   param min: int representing the minute 0-59
//   param sec: int representing the second 0-59
//   param event_id: int representing the event id >= 0
//   return: a Event struct with event id and its time
// TODO: complete the function
struct Event create_new_event(int hour, int min, int sec, int event_id) {
  struct Event ret;
  ret.st.hour = hour;
  ret.st.min = min;
  ret.st.sec = sec;
  ret.event_id = event_id; 
  return ret;
}

// Gets the hour from a Time struct
//   param t: struct representing a time
//   return: an int representing the hour of time t
// TODO: complete the function
int get_hour(struct Time t) {
  return t.hour;
}

// Gets the minute from a Time struct
//   param t: struct representing a time
//   return: an int representing the minute of time t
// TODO: complete the function
int get_min(struct Time t) {
  return t.min;
}

// Gets the second from a Time struct
//   param t: struct representing a time
//   return: an int representing the second of time t
// TODO: complete the function
int get_sec(struct Time t) {
  return t.sec;
}

// Gets the event id from a Event struct
//   param e: struct representing a event
//   return: an int representing the id of event e
// TODO: complete the function
int get_event_id(struct Event e) {
  return e.event_id;
}

// Gets the time from a Event struct
//   param e: struct representing a event
//   return: a Time struct representing the time of event e
// TODO: complete the function
struct Time get_event_time(struct Event e) {
  struct Time ret = e.st;
  return ret;
}


// Get clock hours from total seconds
//   param total: A total number of seconds
//   return: The number of whole hours included in total
static int totalToHours(int total) {
  if (total < 0) {
    printf("totalToHours given a negative argument\n");
    return 0;
  }
  return total / (60 * 60);
}

// Get clock minutes from total seconds
//   param total: A total number of seconds
//   return: The number of whole minutes in total, after
//           deducting the whole hours
static int totalToMinutes(int total) {
  if (total < 0) {
    printf("totalToMinutes given a negative argument\n");
    return 0;
  }
  return (total - totalToHours(total) * (60 * 60)) / 60;
}

// Get clock second from total seconds
//   param total: A total number of seconds
//   return: The number of seconds left from total after
//           deducting the whole minutes
static int totalToSeconds(int total) {
  if (total < 0) {
    printf("totalToSeconds given a negative argument\n");
    return 0;
  }
  return total % 60;
}

// Get total seconds given clock hours, minutes, and seconds
//  param hours: A number of hours (non-negative)
//  param minutes: 0 through 59
//  param seconds: 0 through 59
//  return: Total number of seconds in the time
static int totalFromHMS(int hours, int minutes, int seconds) {
  if (hours < 0) {
    printf("totalFromHMS given negative hours\n");
    return 0;
  }
  if (minutes < 0 || minutes >= 60) {
    printf("totalFromHMS given minutes out of range\n");
    return 0;
  }
  if (seconds < 0 || seconds >= 60) {
    printf("totalFromHMS given seconds out of range\n");
    return 0;
  }
  return (hours * (60 * 60)) + (minutes * 60) + seconds;
}

// Creates a Time struct representing the time difference between two events of
// today
//   param e1: Event struct representing the first event
//   param e2: Event struct representing the second event
//   return: Time struct representing time between e1 and e2
// TODO: complete the function
struct Time elapsed_time(struct Event e1, struct Event e2) {
  // You can use totalFromHMS to get the total seconds in the times,
  // compute the absolute value of the difference, and then use
  // totalToHours, totalToMinutes, and totalToSeconds to get the
  // values to put into the result Time
  struct Time ret;
  int totalSecs = abs(totalFromHMS(e1.st.hour,e1.st.min,e1.st.sec)-totalFromHMS(e2.st.hour,e2.st.min,e2.st.sec));
  ret.hour = totalToHours(totalSecs);
  ret.min = totalToMinutes(totalSecs);
  ret.sec = totalToSeconds(totalSecs);
  return ret;
}
