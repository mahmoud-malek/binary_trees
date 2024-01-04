#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 *
 * Return: If tree is NULL, the function must return 0.
 * A NULL pointer is not a node.
 * A node is only counted if it has at least 1 child.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left != NULL || tree->right != NULL)
		return (binary_tree_nodes(tree->left) + 1 + binary_tree_nodes(tree->right));
	return (0);
}
