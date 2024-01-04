#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 *
 * Return: Pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *current;

	if (tree == NULL)
		return (NULL);

	current = tree;

	while (current != NULL)
	{
		if (value == current->n)
			return ((bst_t *)current);

		if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	return (NULL);
}
