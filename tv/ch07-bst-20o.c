/* code: ch07-bst-20o.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

#define MAX  20

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
typedef struct Node NODE_TYPE;

/* ------------------------------------------ */
int int_compare (const void *va, const void *vb) {
  int a, b;
  a = *(int *) va;
  b = *(int *) vb;
  if (a < b) {
    return (-1);
  }
  else if (a > b) {
    return (1);
  }
  else {
    return (0);
  }
}


/* ------------------------------------------ */
void tree_display (NODE_TYPE * node, int level) {
  int i;

  if (node != NULL) {
    tree_display (node->right, level + 1);
    printf ("\n");
    for (i = 0; i < level; i++) {
      printf ("__");
    }
    printf ("%d", node->data);
    tree_display (node->left, level + 1);
  }
}

/* ------------------------------------------ */
NODE_TYPE *tree_insert (NODE_TYPE * node, int data) {
  if (node == NULL) {
    if (NULL == (node = malloc (sizeof (NODE_TYPE)))) {
      printf ("\nERROR: Can not allocate memory");
      exit (-1);
    }
    node->left = NULL;
    node->right = NULL;
    node->data = data;
  }
  else {
    if (data < node->data) {
      node->left = tree_insert (node->left, data);
    }
    else if (data > node->data) {
      node->right = tree_insert (node->right, data);
    }
  }
  return node;
}

/* ------------------------------------------ */
int main () {
  NODE_TYPE *root;
  int i;
  int data[MAX];
  root = NULL;

  for (i = 0; i < MAX; i++) {
    data[i] = rand () % (MAX * 10);
  }

  qsort (data, MAX, sizeof (int), int_compare);


  for (i = 0; i < MAX; i++) {
    printf ("%2d ", data[i]);
    root = tree_insert (root, data[i]);
  }

  printf ("\n\n*** binary search tree ***");
  tree_display (root, 0);
  printf ("\n");

  return 0;
}
