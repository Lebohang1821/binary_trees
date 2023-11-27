#include "binary_trees.h"

/**
 * binary_tree_nodes - It ounts _nodes with at least 1 child in binary my_tree
 * @my_tree: Pointer to root node of my_tree to count num of _nodes
 *
 * Return: If my_tree is NULL, function must return 0, else return node count
 */
size_t binary_tree_nodes(const binary_tree_t *my_tree)
{
	size_t _nodes = 0;

	if (my_tree)
	{
		_nodes += (my_tree->left || my_tree->right) ? 1 : 0;
		_nodes += binary_tree_nodes(my_tree->left);
		_nodes += binary_tree_nodes(my_tree->right);
	}
	return (_nodes);
}
