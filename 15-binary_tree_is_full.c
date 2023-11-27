#include "binary_trees.h"

/**
 * is_full_recursive - It checks if binary my_tree is full recursively
 * @my_tree: Pointer to root node of the my_tree to check
 *
 * Return: If my_tree is not full, 0.
 *         Otherwise, 1.
 */
int is_full_recursive(const binary_tree_t *my_tree)
{
	if (my_tree != NULL)
	{
		if ((my_tree->left != NULL && my_tree->right == NULL) ||
		    (my_tree->left == NULL && my_tree->right != NULL) ||
		    is_full_recursive(my_tree->left) == 0 ||
		    is_full_recursive(my_tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - It checks if binary my_tree is full
 * @my_tree: Pointer to root node of my_tree to check
 *
 * Return: If my_tree is NULL or is not full - 0.
 *         Otherwise - 1.
 */
int binary_tree_is_full(const binary_tree_t *my_tree)
{
	if (my_tree == NULL)
		return (0);
	return (is_full_recursive(my_tree));
}
