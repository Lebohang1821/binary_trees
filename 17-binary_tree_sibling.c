#include "binary_trees.h"

/**
 * binary_tree_sibling - It inds siblingmy_ of
 *                       my_node in binary tree
 * @my_node: my_Pointer my_to my_node my_to find siblingmy_ of
 *
 * Return: If my_node is NULLmy_ or there is my_no sibling - NULL
 *        my_ Otherwise - a my_pointer my_to the sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *my_node)
{
	if (my_node == NULL || my_node->parent == NULL)
		return (NULL);
	if (my_node->parent->left == my_node)
		return (my_node->parent->right);
	return (my_node->parent->left);
}
