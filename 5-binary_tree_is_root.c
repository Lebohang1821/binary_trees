#include "binary_trees.h"

/**
 * binary_tree_is_root - It checks if _node is root of binary tree
 * @_node: Pointer to _node to check.
 *
 * Return: If _node is root - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_root(const binary_tree_t *_node)
{
	if (_node == NULL || _node->parent != NULL)
		return (0);

	return (1);
}
