#include <stdio.h>

#ifndef MILITARY_TIME_H
#define MILITARY_TIME_H

// Struct representing military time
// TODO: complete the struct
struct Time {
  int hour;
  int min;
  int sec;
};

// goal: creates a Time struct given the hour, minute, and second
// param hour: int representing the hour 0-23
// param min: int representing the minute 0-59
// param sec: int representing the second 0-59
// assumptions:
//   the inputs are that of a valid military time.
// return: a Time struct for the time representing the same time as the integers
struct Time create_time(int hour, int min, int sec);

// goal: gets the hour from a Time struct
// param t: struct representing a time
// return: an int representing the hour of time t
int get_hour(struct Time *t);

// goal: gets the minute from a Time struct
// param t: struct representing a time
// return: an int representing the minute of time t
int get_min(struct Time *t);

// goal: gets the second from a Time struct
// param t: struct representing a time
// return: an int representing the second of time t
int get_sec(struct Time *t);

// goal: sets the hour to a Time struct
// param t: pointer that point to a struct representing a time
void set_hour(struct Time *t, int hour);

// goal: sets the minute to a Time struct
// param t: pointer that point to a struct representing a time
void set_min(struct Time *t, int min);

// goal: sets the second to a Time struct
// param t: pointer that point to a struct representing a time
void set_sec(struct Time *t, int sec);

// goal: Creates a Time struct representing the difference between two times (t2
// - t1) param t1: pointer that point to a Time struct representing the
// beginning of interval param t2: pointer that point to a Time struct
// representing the end of interval return: Time struct representing time
// between t1 and t2
struct Time elapsed_time(struct Time *t1, struct Time *t2);

// goal: remove a substring of str beginning at index idx and having length len
// param str: the string being altered
// param idx: the starting index of the removed chunk
// param len: the number of characters to remove (length of substring being
// removed) assumptions:
//   0 <= idx
//   str is a valid string that terminates properly
void remove_substr(char str[], int idx, int len);

#endif
