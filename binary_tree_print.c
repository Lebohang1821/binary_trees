#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_tree - Recursively stores each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer to store the printed tree
 *
 * Return: Length of printed tree after processing
 */
static int print_tree(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char b[6];  /* Buffer to store node value as a string */
    int width, left, right, is_left, i;

    if (!tree)
        return (0);

    is_left = (tree->parent && tree->parent->left == tree);
    width = sprintf(b, "(%03d)", tree->n);
    left = print_tree(tree->left, offset, depth + 1, s);
    right = print_tree(tree->right, offset + left + width, depth + 1, s);

    /* Fill the buffer with node values at their respective positions */
    for (i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left)
    {
        /* Draw connecting line for left child */
        for (i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }
    else if (depth && !is_left)
    {
        /* Draw connecting line for right child */
        for (i = 0; i < left + width; i++)
            s[depth - 1][offset - width / 2 + i] = '-';
        s[depth - 1][offset + left + width / 2] = '.';
    }

    return (left + width + right);
}

/**
 * tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measure the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t tree_height(const binary_tree_t *tree)
{
    size_t height_l, height_r;

    height_l = tree && tree->left ? 1 + tree_height(tree->left) : 0;
    height_r = tree && tree->right ? 1 + tree_height(tree->right) : 0;

    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    char **s;
    size_t height, i, j;

    if (!tree)
        return;

    height = tree_height(tree);
    s = malloc(sizeof(*s) * (height + 1));

    if (!s)
        return;

    for (i = 0; i < height + 1; i++)
    {
        s[i] = malloc(sizeof(**s) * 255);

        if (!s[i])
            return;

        memset(s[i], ' ', 254);
    }

    print_tree(tree, 0, 0, s);

    for (i = 0; i < height + 1; i++)
    {
        for (j = 254; j > 1; --j)
        {
            if (s[i][j] != ' ')
                break;

            s[i][j] = '\0';
        }

        printf("%s\n", s[i]);
        free(s[i]);
    }

    free(s);
}

