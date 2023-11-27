#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/* Data structure for a binary tree node */
typedef struct binary_tree_s {
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/* Data structure for an even binary tree node */
typedef struct binary_tree_even_s {
    int n;
    struct binary_tree_even_s *parent;
    struct binary_tree_even_s *left;
    struct binary_tree_even_s *right;
} binary_tree_even_t;

/* Function prototypes for regular binary tree operations */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* Function prototypes for even binary tree operations */
binary_tree_even_t *binary_tree_even_node(binary_tree_even_t *parent, int value);
binary_tree_even_t *binary_tree_even_insert_left(binary_tree_even_t *parent, int value);

#endif /* BINARY_TREES_H */

