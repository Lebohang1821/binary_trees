#include "binary_trees.h"

/**
 * binary_trees_ancestor - It looks a lowest common ancestor of two nodes
 * @first: Pointer to first node
 * @second: Pointer to second node
 * Return: If no common ancestors return NULL, else return common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *second,
		const binary_tree_t *first)
{
	binary_tree_t *moms, *pops;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	moms = first->parent, pops = second->parent;
	if (first == pops || !moms || (!moms->parent && pops))
		return (binary_trees_ancestor(first, pops));
	else if (moms == second || !pops || (!pops->parent && moms))
		return (binary_trees_ancestor(moms, second));
	return (binary_trees_ancestor(moms, pops));
}
