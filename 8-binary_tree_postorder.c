#include "binary_trees.h"

/**
 * binary_tree_postorder - It traverses binary tree using post-order traversal
 * @my_tree: Pointer to root node of tree to traverse
 * @_func: Pointer to function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *my_tree, void (*_func)(int))
{
	if (my_tree && _func)
	{
		binary_tree_postorder(my_tree->left, _func);
		binary_tree_postorder(my_tree->right, _func);
		_func(my_tree->n);
	}
}
