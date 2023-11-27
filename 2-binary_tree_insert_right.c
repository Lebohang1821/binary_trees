#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_insert_right - It inserts node as right-child
 *                            of another in binary tree.
 * @parent: Pointer to node to insert right-child in.
 * @value: Value to store in new_node.
 *
 * Return: If parent is NULL or error occurs - NULL.
 *         Otherwise - pointer to new_node.
 *
 * Description: If parent already has right-child, new_node
 *              takes its place and old right-child is set as
 *              right-child of new_node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;

	return (new_node);
}
