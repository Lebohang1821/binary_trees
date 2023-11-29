/* 102-binary_tree_is_complete.c */

#include "binary_trees.h"

/**
 * binary_tree_size - Measure the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
}

/**
 * binary_tree_is_complete - Check if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* Create a queue for level-order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
    size_t front = 0, rear = 0;
    int found_empty = 0;

    if (queue == NULL)
        return (0);

    /* Enqueue the root */
    queue[rear++] = (binary_tree_t *)tree;

    /* Continue traversal until the queue is empty */
    while (front < rear)
    {
        /* Dequeue a node */
        binary_tree_t *current = queue[front++];

        if (current == NULL)
        {
            found_empty = 1;
        }
        else
        {
            /* If an empty node was found, and a non-empty node is encountered afterward, not complete */
            if (found_empty)
            {
                free(queue);
                return (0);
            }

            /* Enqueue the left child */
            queue[rear++] = current->left;

            /* Enqueue the right child */
            queue[rear++] = current->right;
        }
    }

    /* Free the queue */
    free(queue);

    /* If all nodes are traversed without finding the second empty node, the tree is complete */
    return (1);
}

