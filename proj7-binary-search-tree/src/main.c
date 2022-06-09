#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

static struct bst_node *root = NULL;

int main(int argc, char **argv) {
  // There should be exactly one argument, the input file name
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input file name>\n", argv[0]);
    exit(1);
  }

  // Try to open the file
  FILE *in = fopen(argv[1], "r");
  if (!in) {
    fprintf(stderr, "Could not open %s for reading!\n", argv[1]);
    exit(1);
  }

  // Read and process each line of the file

  // [Note: while this is similar to some of the processing in the
  //  later wclite challenge, in that challenge strtok is NOT a
  //  good choice because of the way it modifies the string.]
  char *line = NULL;
  size_t lsize = 0;
  while (getline(&line, &lsize, in) != -1) {
    char *current = line;
    char *next;
    while ((next = strtok(current, " \t\n")) != NULL) {
      current = NULL;
      bst_add(&root, next);
    }
  }
  bst_print(root);
  fclose(in);
}
