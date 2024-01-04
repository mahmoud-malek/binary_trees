#include "binary_trees.h"
#include <stdbool.h>
#include <limits.h>

/**
 * is_bst_util - Helper function to check if a tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: The minimum value allowed for the current node
 * @max: The maximum value allowed for the current node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_util(tree->left, min, tree->n - 1) &&
			is_bst_util(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{

	int min = INT_MIN;
	int max = INT_MAX;

	if (tree == NULL)
		return (0);

	return (is_bst_util(tree, min, max));
}
