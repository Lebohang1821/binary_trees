#include "binary_trees.h"

/**
 * binary_tree_uncle - It finds uncle of a my_node
 *                     in a binary tree
 * @my_node: Pointer to my_node to find uncle of
 *
 * Return: If my_node is NULL or has no uncle, NULL
 *         Otherwise, a pointer to the uncle my_node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *my_node)
{
	if (my_node == NULL ||
	    my_node->parent == NULL ||
	    my_node->parent->parent == NULL)
		return (NULL);
	if (my_node->parent->parent->left == my_node->parent)
		return (my_node->parent->parent->right);
	return (my_node->parent->parent->left);
}
