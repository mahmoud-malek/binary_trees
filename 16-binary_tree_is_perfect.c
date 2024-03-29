#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: If tree is NULL, your function must return 0. The height of a
 * binary tree is the maximum number of edges from the root to
 *  the farthest leaf node.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree != NULL)
	{
		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);

		return ((left_height > right_height ? left_height : right_height) + 1);
	}

	else
		return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0.
 * A binary tree is perfect if all its levels are completely filled.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		if (!tree->left && !tree->right)
			return (1);

		if (tree->left && tree->right)
			return (binary_tree_is_perfect(tree->left) &&
			 binary_tree_is_perfect(tree->right));
	}

	return (0);
}
