#include "binary_trees.h"

/**
 * binary_tree_depth - It measures depth of node in binary my_tree
 * @my_tree: Pointer to node to measure depth
 *
 * Return: If my_tree is NULL, your function must return 0, else return depth
 */
size_t binary_tree_depth(const binary_tree_t *my_tree)
{
	return ((my_tree && my_tree->parent) ? 1 + binary_tree_depth(my_tree->parent) : 0);
}
