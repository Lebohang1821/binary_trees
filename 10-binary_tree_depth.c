#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of the nodes in a binary tree.
 * @tree: The pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, your function must return 0, return the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
