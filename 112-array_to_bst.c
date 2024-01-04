#include "binary_trees.h"

/**
 * newNode - Builds a Binary Search Tree (BST) from an array
 * @value: Pointer to the first element of the array to be converted
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *newNode(int value)
{
	bst_t *node = (bst_t *)malloc(sizeof(bst_t));

	node->n = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * array_to_bst - Builds a Binary Search Tree (BST) from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;

	if (size == 0)
		return (NULL);

	root = newNode(array[0]);
	for (size_t i = 1; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
