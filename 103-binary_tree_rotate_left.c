#include "binary_trees.h"

/**
* binary_tree_rotate_left - Left-rotates the binary tree.
* @tree: A pointer to a root node of the tree to rotate.
*
* Return: The pointer to the new root node after rotation.
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
binary_tree_t *pivot, *tmps;

if (tree == NULL || tree->right == NULL)
return (NULL);

pivot = tree->right;
tmps = pivot->left;
pivot->left = tree;
tree->right = tmps;
if (tmps != NULL)
tmps->parent = tree;
tmps = tree->parent;
tree->parent = pivot;
pivot->parent = tmps;
if (tmps != NULL)
{
if (tmps->left == tree)
tmps->left = pivot;
else
tmps->right = pivot;
}

return (pivot);
}
