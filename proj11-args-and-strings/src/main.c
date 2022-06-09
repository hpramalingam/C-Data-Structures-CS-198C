#include <stdio.h>

#include "args-strings.h"

int main(int argc, char **argv) {
  // Extract argument info with getopt
  int cflag = -1, wflag = -1, nflag = -1, lflag = -1, fl_nm_len = -1;
  FILE *outf = NULL;
  parse_args(argc, argv, &cflag, &wflag, &nflag, &lflag, &outf, &fl_nm_len);
  printf("cflag = %d  wflag = %d  nflag = %d  lflag = %d  fl_nm_len = %d\n",
         cflag, wflag, nflag, lflag, fl_nm_len);
  if (!outf) {
    printf("outf is NULL\n");
  } else if (outf == stdout) {
    printf("outf is stdout\n");
  } else {
    printf("outf is not stdout\n");
  }

  printf("count_words returned %d, should be 3.\n",
         count_words("A funky\tstring.\n"));
  printf("count_numbers returned %d, should be 3.\n",
         count_numbers("123then456,7890."));
  printf("count_words returned %d, should be 0.\n", count_words(NULL));
  printf("count_numbers returned %d, should be 0.\n", count_numbers(NULL));
  printf("count_words returned %d, should be 0.\n", count_words(""));
  printf("count_numbers returned %d, should be 0.\n", count_numbers(""));
}
