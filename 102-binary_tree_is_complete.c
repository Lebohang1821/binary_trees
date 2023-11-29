/* 102-binary_tree_is_complete.c */

#include "binary_trees.h"

/**
 * struct levelorder_queue_s - Custom queue node for level-order traversal
 * @node: Binary tree node
 * @next: Pointer to the next node in the queue
 */
typedef struct levelorder_queue_s
{
    binary_tree_t *node;
    struct levelorder_queue_s *next;
} levelorder_queue_t;

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t **head, levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
    levelorder_queue_t *new;

    new = malloc(sizeof(levelorder_queue_t));
    if (new == NULL)
        return (NULL);

    new->node = node;
    new->next = NULL;

    return (new);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
    levelorder_queue_t *tmp;

    while (head != NULL)
    {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}

/**
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 *
 * Description: Exits with a status code of 1 upon malloc failure.
 */
void push(binary_tree_t *node, levelorder_queue_t **head, levelorder_queue_t **tail)
{
    levelorder_queue_t *new;

    new = create_node(node);
    if (new == NULL)
    {
        free_queue(*head);
        exit(1);
    }
    if (*tail != NULL)
        (*tail)->next = new;
    *tail = new;
    if (*head == NULL)
        *head = new;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
    levelorder_queue_t *tmp;

    tmp = (*head)->next;
    free(*head);
    *head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 *
 * Description: Exits with a status code of 1 upon malloc failure.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    levelorder_queue_t *head = NULL, *tail = NULL;
    unsigned char flag = 0;

    if (tree == NULL)
        return (0);

    push((binary_tree_t *)tree, &head, &tail);

    while (head != NULL)
    {
        binary_tree_t *current = head->node;

        if (current->left != NULL)
        {
            if (flag == 1)
            {
                free_queue(head);
                return (0);
            }
            push(current->left, &head, &tail);
        }
        else
            flag = 1;

        if (current->right != NULL)
        {
            if (flag == 1)
            {
                free_queue(head);
                return (0);
            }
            push(current->right, &head, &tail);
        }
        else
            flag = 1;

        pop(&head);
    }

    return (1);
}

