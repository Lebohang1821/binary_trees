#include "binary_trees.h"

/**
 * binary_tree_delete - It del binary tree
 * @tree: Pointer to root node of tree to delete.
 */
void binary_tree_delete(binary_tree_t *my_tree)
{
	if (my_tree != NULL)
	{
		binary_tree_delete(my_tree->left);
		binary_tree_delete(my_tree->right);
		free(my_tree);
	}
}
