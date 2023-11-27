#include "binary_trees.h"

/**
 * binary_tree_preorder - It go through binary tree using pre-order traversal
 * @my_tree: Pointer to root node of my_tree to traverse
 * @_func: Pointer to function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *my_tree, void (*_func)(int))
{
	if (my_tree && _func)
	{
		_func(my_tree->n);
		binary_tree_preorder(my_tree->left, _func);
		binary_tree_preorder(my_tree->right, _func);
	}
}
