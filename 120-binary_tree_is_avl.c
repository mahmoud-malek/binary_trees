#include "binary_trees.h"

int is_avl_helper(const binary_tree_t *tree, int min_val, int max_val);
size_t tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min_val: The minimum value allowed for nodes in the subtree.
 * @max_val: The maximum value allowed for nodes in the subtree.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int is_avl_helper(const binary_tree_t *tree, int min_val, int max_val)
{
	size_t left_height, right_height, height_diff;

	if (tree != NULL)
	{
		if (tree->n < min_val || tree->n > max_val)
			return (0);

		left_height = tree_height(tree->left);
		right_height = tree_height(tree->right);
		height_diff = (left_height > right_height) ? (left_height - right_height)
												   : (right_height - left_height);

		if (height_diff > 1)
			return (0);

		return (is_avl_helper(tree->left, min_val, tree->n - 1) &&
				is_avl_helper(tree->right, tree->n + 1, max_val));
	}
	return (1);
}

/**
 * tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, the function returns 0, else returns the height.
 */
size_t tree_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_height = 0, right_height = 0;

		left_height = (tree->left != NULL) ? 1 + tree_height(tree->left) : 1;
		right_height = (tree->right != NULL) ? 1 + tree_height(tree->right) : 1;

		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}
