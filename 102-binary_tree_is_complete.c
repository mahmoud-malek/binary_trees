#include "binary_trees.h"

/**
 * enqueue - Adds a node to the end of the queue
 * @queue_head: Pointer to the head of the queue
 * @node: Node to be enqueued
 *
 * Return: Pointer to the new queue node
 */
binary_tree_queue_t *enqueue(binary_tree_queue_t *queue_head,
							 const binary_tree_t *node)
{
	binary_tree_queue_t *new_node = malloc(sizeof(binary_tree_queue_t));

	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	if (queue_head == NULL)
		return (new_node);

	binary_tree_queue_t *temp = queue_head;

	while (temp->next)
		temp = temp->next;

	temp->next = new_node;
	return (new_node);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	binary_tree_queue_t *queue_head = NULL;
	int flag = 0;

	queue_head = enqueue(queue_head, tree);

	while (queue_head)
	{
		const binary_tree_t *current = queue_head->node;

		if (current->left)
		{
			if (flag == 1)
				return (0);
			queue_head = enqueue(queue_head, current->left);
		}
		else
			flag = 1;

		if (current->right)
		{
			if (flag == 1)
				return (0);
			queue_head = enqueue(queue_head, current->right);
		}
		else
			flag = 1;

		queue_head = queue_head->next;
	}

	return (1);
}
