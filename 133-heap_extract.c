#include "binary_trees.h"

/**
 * heap_extract  - Extracts the root node of a Max Binary Heap.
 *
 * @root: A double pointer to the root node of the heap.
 *
 * Return: The value stored in the root node.
 */
int heap_extract(heap_t **root)
{
	int value;

	if (!*root)
		return (0);

	value = (*root)->n;

	if (!(*root)->left)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
		return (value);
	}

	recurse_extract_max_heap(*root);
	return (value);
}

/**
 * recurse_extract_max_heap - Recursively extracts the maximum from the heap.
 *
 * @tree: The pointer to the root of the tree.
 */
void recurse_extract_max_heap(heap_t *tree)
{
	heap_t *subtree_max, *right_max = NULL;

	if (!tree->left)
		return;

	subtree_max = find_max(tree->left);

	if (tree->right)
		right_max = find_max(tree->right);

	if (right_max && right_max->n > subtree_max->n)
		subtree_max = right_max;

	tree->n = subtree_max->n;

	if (!subtree_max->left)
	{
		if (subtree_max->parent && subtree_max->parent->left == subtree_max)
			subtree_max->parent->left = NULL;

		if (subtree_max->parent && subtree_max->parent->right == subtree_max)
			subtree_max->parent->right = NULL;

		free(subtree_max);
	}
	else
		recurse_extract_max_heap(subtree_max);
}

/**
 * find_max - Finds the maximum node in a tree.
 *
 * @tree: The pointer to the root of the tree.
 *
 * Return: The node with the maximum value.
 */
heap_t *find_max(heap_t *tree)
{
	heap_t *current_max, *left_max, *right_max;

	if (!tree->left)
		return (tree);

	left_max = find_max(tree->left);

	if (left_max->n > tree->n)
		current_max = left_max;
	else
		current_max = tree;

	if (tree->right)
	{
		right_max = find_max(tree->right);

		if (right_max->n > current_max->n)
			current_max = right_max;
		else
			current_max = tree;
	}

	return (current_max);
}
