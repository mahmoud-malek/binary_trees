#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *temp;

	/* Handle edge cases where either of the nodes is NULL */
	if (first == NULL || second == NULL)
		return NULL;

	/* Store the first node to traverse upwards */
	temp = first;

	/* Traverse upwards from the first node */
	while (temp)
	{
		const binary_tree_t *ancestor = second;

		/* Check if the current node is the common ancestor */
		while (ancestor)
		{
			if (temp == ancestor)
				return (binary_tree_t *)temp;
			ancestor = ancestor->parent;
		}

		/* Move to the parent of the first node */
		temp = temp->parent;
	}

	return NULL; /* No common ancestor found */
}
