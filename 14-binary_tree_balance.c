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
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * the balance factor
 *
 * Return: If tree is NULL, return 0.
 * The balance factor is the difference between the heights of
 *  the left and right subtrees.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left) -
			binary_tree_height(tree->right));
}
