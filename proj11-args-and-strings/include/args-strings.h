#ifndef ARGS_STRINGS_H
#define ARGS_STRINGS_H
#include <stdio.h>

void reset_getopt();

void parse_args(int argc, char *argv[], int *cflag, int *wflag, int *nflag,
                int *lflag, FILE **outfile, int *name_len);

int count_words(const char *s);
int count_numbers(const char *s);
#endif  // ARGS_STRINGS_H
