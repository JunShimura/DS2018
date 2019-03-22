/* code: ch08-bst-30o.c   (v1.18.00) */
#include <stdio.h>
#include <stdlib.h>

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
void shuffle (int *v, int n) {
  int i, j, t;
  for (i = 0; i < n; i++) {
    j = rand () % n;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
  }
}

/* ------------------------------------------ */
void rand_nd (int *v, int n) {
  int i;

  for (i = 0; i < n; i++) {
    v[i] = i;
  }
  shuffle (v, n);
}

/* ------------------------------------------ */
void tree_display (NODE_TYPE * node, int level) {
  int i;

  if (node != NULL) {
    tree_display (node->right, level + 1);

    printf ("\n");
    for (i = 0; i < level; i++) {
      printf ("_");
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
  int i, n;
  int *v;

  root = NULL;
  v = NULL;
  n = 30;

  srand (1);

  v = malloc (sizeof (int) * n);

  rand_nd (v, n);

  qsort (v, n, sizeof (int), int_compare);

  for (i = 0; i < n; i++) {
    root = tree_insert (root, v[i]);
  }

  tree_display (root, 0);
  printf ("\n\n");

  free (v);
  return 0;
}
