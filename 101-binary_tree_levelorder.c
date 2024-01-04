#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: Level-order traversal visits nodes level by level,
 *               from left to right.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Create a queue for level-order traversal */
	binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);
	size_t front = 0, rear = 0;

	if (queue == NULL)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		const binary_tree_t *current = queue[front++];

		/* Perform the given function on the current node's value */
		func(current->n);

		/* Enqueue left child if exists */
		if (current->left != NULL)
			queue[rear++] = (binary_tree_t *)current->left;

		/* Enqueue right child if exists */
		if (current->right != NULL)
			queue[rear++] = (binary_tree_t *)current->right;
	}

	free(queue);
}
