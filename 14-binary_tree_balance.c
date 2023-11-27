#include "binary_trees.h"

/**
 * binary_tree_balance - It measures balance factor of binary tree
 * @my_tree: Pointer to root node of my_tree to measure balance factor
 *
 * Return: If tree is NULL, return 0, else return balance factor
 */
int binary_tree_balance(const binary_tree_t *my_tree)
{
	if (my_tree)
		return (binary_tree_height(my_tree->left) - binary_tree_height(my_tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures height of binary my_tree
 * @my_tree: Pointer to root node of my_tree to measure height
 *
 * Return: If my_tree is NULL, your function must return 0, else return height
 */
size_t binary_tree_height(const binary_tree_t *my_tree)
{
	if (my_tree)
	{
		size_t left = 0, right = 0;

		left = my_tree->left ? 1 + binary_tree_height(my_tree->left) : 1;
		right = my_tree->right ? 1 + binary_tree_height(my_tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}
