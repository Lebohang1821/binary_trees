/* 16-binary_tree_is_perfect.c */

#include "binary_trees.h"

/* Function prototypes */
size_t binary_tree_height(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree, size_t height, size_t *level);

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height, level = 0;

    if (tree == NULL)
        return (0);

    height = binary_tree_height(tree);

    return is_perfect_recursive(tree, height, &level);
}

/**
 * binary_tree_height - Calculate the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_perfect_recursive - Helper function for recursive checking of perfect tree
 * @tree: Pointer to the current node
 * @height: Height of the tree
 * @level: Current level in the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t height, size_t *level)
{
    if (tree == NULL)
        return (1);

    if (tree->left == NULL && tree->right == NULL)
    {
        if (*level == 0)
        {
            *level = height;
            return (1);
        }

        return (*level == height);
    }

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (is_perfect_recursive(tree->left, height, level) &&
            is_perfect_recursive(tree->right, height, level));
}

