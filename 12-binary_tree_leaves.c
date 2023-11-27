#include "binary_trees.h"

/**
 * binary_tree_leaves - It counts _leaves in binary my_tree
 * @my_tree: Pointer to root node of my_tree to count _leaves of
 *
 * Return: Num of _leaves in my_tree
 */
size_t binary_tree_leaves(const binary_tree_t *my_tree)
{
	size_t _leaves = 0;

	if (my_tree)
	{
		_leaves += (!my_tree->left && !my_tree->right) ? 1 : 0;
		_leaves += binary_tree_leaves(my_tree->left);
		_leaves += binary_tree_leaves(my_tree->right);
	}
	return (_leaves);
}
