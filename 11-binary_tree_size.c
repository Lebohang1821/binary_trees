#include "binary_trees.h"

/**
 * binary_tree_size - It checks size of binary my_tree
 * @my_tree: Pointer to root node of my_tree to measure the s of
 *
 * Return: S of my_tree
 */
size_t binary_tree_size(const binary_tree_t *my_tree)
{
	size_t s = 0;

	if (my_tree)
	{
		s += 1;
		s += binary_tree_size(my_tree->left);
		s += binary_tree_size(my_tree->right);
	}
	return (s);
}
