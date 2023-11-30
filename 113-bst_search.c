#include "binary_trees.h"

/**
* bst_search - searches for a value in the binary search tree
* @tree: pointer to the root node of a BST to search
* @value: value to search in a tree
*
* Return: pointer to a node containing the value equal to value, or NULL
*/
bst_t *bst_search(const bst_t *tree, int value)
{
bst_t *tmps;

tmps = (bst_t *)tree;
while (tmps)
{
if (tmps->n == value)
return (tmps);
if (tmps->n < value)
tmps = tmps->right;
else
tmps = tmps->left;
}
return (NULL);
}
