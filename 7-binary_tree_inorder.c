#include "binary_trees.h"

/**
 * binary_tree_inorder - It go through binary tree using in-order traversal
 * @my_tree: Pointer to root node of my_tree to traverse.
 * @_func: Pointer to function to call for each node.
 */
void binary_tree_inorder(const binary_tree_t *my_tree, void (*_func)(int))
{
	if (my_tree && _func)
	{
		binary_tree_inorder(my_tree->left, _func);
		_func(my_tree->n);
		binary_tree_inorder(my_tree->right, _func);
	}
}
