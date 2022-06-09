#ifndef BST_H
#define BST_H

struct bst_node {
  char *string;
  struct bst_node *left;
  struct bst_node *right;
  int count;
};

#define NUM_NODES 1000

void bst_add(struct bst_node **proot, char *str);
void bst_print(struct bst_node *root);
void bst_reset();

#endif
