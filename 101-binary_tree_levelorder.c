#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using
 *  level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *queue_head, *queue_tail;
	const binary_tree_t *current;
	levelorder_queue_t *tmp;

	if (tree == NULL || func == NULL)
		return;
	queue_head = NULL, queue_tail = NULL;
	queue_head = queue_tail = malloc(sizeof(levelorder_queue_t));
	if (queue_head == NULL)
		return;
	queue_head->node = tree, queue_head->next = NULL;
	while (queue_head)
	{
		current = queue_head->node;
		func(current->n);
		if (current->left)
		{
			queue_tail->next = malloc(sizeof(levelorder_queue_t));
			if (!queue_tail->next)
			{
				free(queue_head);
				return;
			}
			queue_tail = queue_tail->next;
			queue_tail->node = current->left, queue_tail->next = NULL;
		}
		if (current->right)
		{
			queue_tail->next = malloc(sizeof(levelorder_queue_t));
			if (!queue_tail->next)
			{
				free(queue_head);
				return;
			}
			queue_tail = queue_tail->next;
			queue_tail->node = current->right, queue_tail->next = NULL;
		}
		tmp = queue_head, queue_head = queue_head->next;
		free(tmp);
	}
}
