#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
* height - Measures a height of a binary tree.
* @tree: The pointer to the root node of the tree to measure the height.
*
* Return: If tree is NULL, your function must return 0, else return height.
*/
size_t height(const binary_tree_t *tree)
{
if (tree != NULL)
{
size_t l = 0, s = 0;

l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
s = tree->right ? 1 + binary_tree_height(tree->right) : 1;
return ((l > s) ? l : s);
}
return (0);
}

/**
* balance - Measures the balance factor of a binary tree.
* @tree: The pointer to the root node of the tree to measure the balance factor.
*
* Return: If tree NULL, return 0, else return balance factor.
*/
int balance(const binary_tree_t *tree)
{
return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
* avl_insert_recursive - Inserts a value into an AVL tree recursively.
* @tree: The double pointer to the root node of the AVL tree to insert into.
* @parent: A parent node of the current working node.
* @new: The double pointer to store the new node.
* @value: A value to insert into the AVL tree.
*
* Return: The pointer to the new root after insertion, or NULL on failure.
*/
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
avl_t **new, int value)
{
int bfactors;

if (*tree == NULL)
return (*new = binary_tree_node(parent, value));

if ((*tree)->n > value)
{
(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
if ((*tree)->left == NULL)
return (NULL);
}
else if ((*tree)->n < value)
{
(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
if ((*tree)->right == NULL)
return (NULL);
}
else
return (*tree);

bfactors = balance(*tree);
if (bfactors > 1 && (*tree)->left->n > value)
*tree = binary_tree_rotate_right(*tree);
else if (bfactors < -1 && (*tree)->right->n < value)
*tree = binary_tree_rotate_left(*tree);
else if (bfactors > 1 && (*tree)->left->n < value)
{
(*tree)->left = binary_tree_rotate_left((*tree)->left);
*tree = binary_tree_rotate_right(*tree);
}
else if (bfactors < -1 && (*tree)->right->n > value)
{
(*tree)->right = binary_tree_rotate_right((*tree)->right);
*tree = binary_tree_rotate_left(*tree);
}

return (*tree);
}

/**
* avl_insert - Inserts the value into an AVL tree.
* @tree: The double pointer to the root node of the AVL tree to insert into.
* @value: A value to insert into the AVL tree.
*
* Return: The pointer to the inserted node, or NULL on failure.
*/
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *news = NULL;

if (tree == NULL)
return (NULL);
if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}
avl_insert_recursive(tree, *tree, &news, value);
return (news);
}
