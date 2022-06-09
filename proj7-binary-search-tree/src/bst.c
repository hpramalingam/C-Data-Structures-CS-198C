#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

// As needed, get new nodes from this array.

struct bst_node the_nodes[NUM_NODES];

// Track the number allocated so you know the next entry of
// the_nodes that is available, and can check for trying to
// allocate more than NUM_NODES nodes.

int num_allocated = 0;


void bst_add(struct bst_node **proot, char *str) {
  // Fill this function in
  // Don't forget, proot is a _pointer to_ the pointer to the BST root.
  // This is so that when a new subtree is needed, you can set *proot.
  // Modifying a caller's variable in this way is something not available
  // in Java and many other languages, but is a useful technique in C.
  // Note that, to access the count field, for example, you need
  // to write (*proot)->count, etc.
  if (*proot == NULL) {
    // Insert code here to allocate a new bst_node struct from the array.
    // If no more space is available, you should print "Out of space!\n"
    // and call exit(1);  If you _can_ get a node, fill in its fields and
    // set root (what proot points to!) to point to it.  Don't forget to
    // copy str using strdup().
    //
    // Note that you will need to assign to *proot the _address_ of the
    // array element you are allocating, and fill in that element.  You
    // should NEVER return or store the address of a local variable!

    if (num_allocated >= NUM_NODES){
      printf("Out of space!\n");
      exit(1);
    }

    the_nodes[num_allocated].count++;
    the_nodes[num_allocated].string = strdup(str);
    *proot = &the_nodes[num_allocated];
    num_allocated++; 

  } else {
    int cmp = strcmp(str, (*proot)->string);
    if (cmp == 0) {
      // Insert code here to increment to count of the bst_node that root
      // points to (root is what proot points to!).  One line of code will
      // suffice.
      (*proot)->count++; 
    } else if (cmp < 0) {
      // Insert code here to call bst_add on the 'left' field of the
      // bst_node that root points to.  (Recall, root is what proot
      // points to!)  To do this, you need need to get the _address_
      // of the 'left' field of the struct.  Again, one line of code
      // will suffice.
      bst_add(&(*proot)->left,str);
    } else {
      // Insert code here to call bst_add on the 'right' field of the
      // bst_node that root points to, analogously to the previous case.
      bst_add(&(*proot)->right,str);
    }
  }
}

void bst_print(struct bst_node *root) {
  // Fill this function in.
  // Here the argument is just a pointer to a bst_node.  It may be
  // NULL, in which case just return.  This makes it easy to code
  // the recurion!  For printing a node's 'string' and 'count' fields,
  // use the format string "%-30s: %3d\n".
  // You are to do an *in-order* traversal of the tree.  This means to
  // call bst_print on the left subtree, then print the current node's
  // contents, then call bst_print on the right subtree.  However, before
  // any of that, check whether root is NULL.  If it is, you are at an
  // empty subtree, so there is nothing to print - just return.
  if (root == NULL) {
    return; 
  }

  bst_print(root->left);
  printf("%-30s: %3d\n", root->string, root->count);
  bst_print(root->right); 
}

// Used in the tests to reset the bst, don't mess with this
//   (Well, feel free to, but it will break the tests, which you probably don't
//   want to do.)
void bst_reset() {
  num_allocated = 0;
  for (int i = 0; i < NUM_NODES; i++) {
    the_nodes[i].string = NULL;
    the_nodes[i].left = NULL;
    the_nodes[i].right = NULL;
    the_nodes[i].count = 0;
  }
}
