#include "binary_trees.h"

/**
 * binary_tree_height - It measures height of binary my_tree
 * @my_tree: Pointer to root node of tree to measure height
 *
 * Return: If my_tree is NULL, your function must return 0, else return height
 */
size_t binary_tree_height(const binary_tree_t *my_tree)
{
	if (my_tree)
	{
		size_t l = 0, i = 0;

		l = my_tree->left ? 1 + binary_tree_height(my_tree->left) : 0;
		i = my_tree->right ? 1 + binary_tree_height(my_tree->right) : 0;
		return ((l > i) ? l : i);
	}
	return (0);
}
