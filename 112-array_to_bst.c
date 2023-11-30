#include "binary_trees.h"

/**
* array_to_bst - builds the Binary Search Tree from an array
* @array: pointer to a first element of the array to be converted
* @size: number of element in a array
*
* Description: If a value of a array already exists, this value is ignored
*
* Return: pointer to a root node of the created BST, or NULL on failure
*/
bst_t *array_to_bst(int *array, size_t size)
{
bst_t *root = NULL;
size_t z;

for (z = 0; z < size; z++)
{
bst_insert(&root, array[z]);
}
return (root);
}
