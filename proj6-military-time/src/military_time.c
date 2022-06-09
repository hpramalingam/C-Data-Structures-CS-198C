#include "military_time.h"
#include <string.h>
// goal: creates a Time struct given the hour, minute, and second
// param hour: int representing the hour 0-23
// param min: int representing the minute 0-59
// param sec: int representing the second 0-59
// assumptions:
//   the inputs are that of a valid military time.
// return: a Time struct for the time representing the same time as the integers
//
// TODO: complete the function
struct Time create_time(int hour, int min, int sec) {
  struct Time ret;
  ret.hour = hour;
  ret.min = min;
  ret.sec = sec; 
  return ret;
}

// goal: gets the hour from a Time struct
// param t: pointer that point to a struct representing a time
// return: an int representing the hour of time t
//
// TODO: complete the function
int get_hour(struct Time *t) {
  return (*t).hour; 
}

// goal: gets the minute from a Time struct
// param t: pointer that point to a struct representing a time
// return: an int representing the minute of time t
//
// TODO: complete the function
int get_min(struct Time *t) {
  return (*t).min;
}

// goal: gets the second from a Time struct
// param t: pointer that point to a struct representing a time
// return: an int representing the second of time t
//
// TODO: complete the function
int get_sec(struct Time *t) {
  return (*t).sec;
}

// goal: sets the hour to a Time struct
// param t: pointer that point to a struct representing a time
//
// TODO: complete the function
void set_hour(struct Time *t, int hour) {
  (*t).hour = hour; 
}

// goal: sets the minute to a Time struct
// param t: pointer that point to a struct representing a time
//
// TODO: complete the function
void set_min(struct Time *t, int min) {
  (*t).min = min; 
}

// goal: sets the second to a Time struct
// param t: pointer that point to a struct representing a time
//
// TODO: complete the function
void set_sec(struct Time *t, int sec) {
  (*t).sec = sec; 
}


// Get hours/minutes/second from total seconds
//   param total: A total number of seconds
//   param: Address of an int to receive the hours
//   param: Address of an int to receive the minutes
//   param: Address of an int to receive the seconds
static void totalToHMS(int total, int *hours, int *minutes, int *seconds) {
  if (total < 0) {
    printf("totalToHours given a negative argument\n");
    return;
  }
  *hours = total / (60 * 60);
  total -= (*hours) * (60 * 60);
  *minutes = total / 60;
  *seconds = total % 60;
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

// goal: Creates a Time struct representing the difference between two times (t2
// - t1) param t1: pointer that point to a Time struct representing the
// beginning of interval param t2: pointer that point to a Time struct
// representing the end of interval return: Time struct representing time
// between t1 and t2
//
// TODO: complete the function
struct Time elapsed_time(struct Time *t1, struct Time *t2) {
  struct Time dt;
  int *pOne = &dt.hour;
  int *pTwo = &dt.min;
  int *pThree = &dt.sec;
  int totalSecs = totalFromHMS((*t2).hour,(*t2).min,(*t2).sec)-totalFromHMS((*t1).hour,(*t1).min,(*t1).sec);
  if (totalSecs < 0) {
    totalSecs += 86400; 
  }
  totalToHMS(totalSecs, pOne, pTwo, pThree);
  return dt;
}

// goal: remove a substring of str beginning at index idx and having length len
// param str: the string being altered
// param idx: the starting index of the removed chunk
// param len: the number of characters to remove (length of substring being
// removed) assumptions:
//   str is a valid string that terminates properly
//
// TODO: complete the function
void remove_substr(char str[], int idx, int len) {
  if (idx >= strlen(str)) {
    return; 
  }
  int index = idx;
  for(int i = idx+len; i < strlen(str); i++) {
    str[index] = str[i];
    index++; 
  }
  str[index] ='\0'; 
}
