#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!is_complete_tree(tree))
		return (0);

	return (validate_parent(tree->left) && validate_parent(tree->right));
}

/**
 * validate_parent - Checks if the parent node's value is
 *  greater than its children's values.
 *
 * @tree: A pointer to the node.
 *
 * Return: 1 if the parent node's value is greater, 0 otherwise.
 */
int validate_parent(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (validate_parent(tree->left) && validate_parent(tree->right));
}

/**
 * is_complete_tree - Calls the complete_tree_checker function.
 *
 * @tree: Tree root.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int is_complete_tree(const binary_tree_t *tree)
{
	size_t total_nodes;

	if (tree == NULL)
		return (0);

	total_nodes = tree_size(tree);

	return (complete_tree_checker(tree, 0, total_nodes));
}

/**
 * complete_tree_checker - Checks if the tree is complete.
 *
 * @tree: Pointer to the tree root.
 * @index: Node index.
 * @total_nodes: Total number of nodes.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int complete_tree_checker(const binary_tree_t *tree,
						  int index, int total_nodes)
{
	if (tree == NULL)
		return (1);

	if (index >= total_nodes)
		return (0);

	return (complete_tree_checker(tree->left, (2 * index) + 1, total_nodes) &&
			complete_tree_checker(tree->right, (2 * index) + 2, total_nodes));
}

/**
 * tree_size - Measures the size of a binary tree.
 *
 * @tree: Tree root.
 * Return: Size of the tree or 0 if the tree is NULL.
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_size(tree->left) + tree_size(tree->right) + 1);
}
