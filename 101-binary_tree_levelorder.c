/* 101-binary_tree_levelorder.c */

#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    /* Create a queue for level-order traversal */
    binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
    size_t front = 0, rear = 0;

    if (queue == NULL)
        return;

    /* Enqueue the root */
    queue[rear++] = (binary_tree_t *)tree;

    /* Continue traversal until the queue is empty */
    while (front < rear)
    {
        /* Dequeue a node and perform the specified function */
        binary_tree_t *current = queue[front++];
        func(current->n);

        /* Enqueue the left child if exists */
        if (current->left != NULL)
            queue[rear++] = current->left;

        /* Enqueue the right child if exists */
        if (current->right != NULL)
            queue[rear++] = current->right;
    }

    /* Free the queue */
    free(queue);
}

