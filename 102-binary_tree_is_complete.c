#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0.
 * In a complete binary tree every level, except possibly the last,
 * is completely filled, and all nodes in the last level
 *  are as far left as possible.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int node_count = binary_tree_size(tree);

	return (is_complete(tree, 0, node_count));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * @index: index
 * @node_count: node count
 * Return: If tree is NULL, your function must return 0.
 * In a complete binary tree every level, except possibly the last,
 * is completely filled, and all nodes in the last level
 *  are as far left as possible.
 */

int is_complete(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
			is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_size - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0.
 * In a complete binary tree every level, except possibly the last,
 * is completely filled, and all nodes in the last level
 *  are as far left as possible.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}
