#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree
 *  using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * Description: If tree or func is NULL, do nothing. In this traversal method,
 * the root node is visited last, hence the name. First we traverse the left
 * subtree, then the right subtree and finally the root node.
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *stack[1000];
	int output[1000];
	const binary_tree_t *current;
	int top = -1, idx = 0;

	if (tree == NULL || func == NULL)
		return;

	stack[++top] = tree;

	while (top != -1)
	{
		current = stack[top--];
		output[idx++] = current->n;

		if (current->left != NULL)
			stack[++top] = current->left;

		if (current->right != NULL)
			stack[++top] = current->right;
	}

	while (idx > 0)
		func(output[--idx]);
}
