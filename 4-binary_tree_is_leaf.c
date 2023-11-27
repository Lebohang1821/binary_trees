#include "binary_trees.h"

/**
 * binary_tree_is_leaf - It checks if _node is leaf of binary tree
 * @_node: Pointer to _node to check
 *
 * Return: If _node is leaf - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_leaf(const binary_tree_t *_node)
{
	if (_node == NULL || _node->left != NULL || _node->right != NULL)
		return (0);

	return (1);
}
