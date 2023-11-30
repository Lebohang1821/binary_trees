#include "binary_trees.h"

/**
* bst_insert - inserts the value in a Binary Search Tree
* @tree: Double pointer to the root node of the BST to insert the value
* @value: Value to store in the node to be inserted
*
* Description: If the address stored in treea is NULL, the created node must
* Become the root node. If a value is already present in the tree, it must
* Be ignored
*
* Return: The pointer to the created node, or NULL on failure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *tmps;

if (tree)
{
if (*tree == NULL)
{
*tree = (bst_t *)binary_tree_node(NULL, value);
return (*tree);
}
tmps = *tree;
while (tmps)
{
if (tmps->n == value)
break;
if (tmps->n > value)
{
if (!tmps->left)
{
tmps->left = (bst_t *)binary_tree_node(tmps, value);
return (tmps->left);
}
tmps = tmps->left;
}
else if (tmps->n < value)
{
if (!tmps->right)
{
tmps->right = (bst_t *)binary_tree_node(tmps, value);
return (tmps->right);
}
tmps = tmps->right;
}
}
}
return (NULL);
}
