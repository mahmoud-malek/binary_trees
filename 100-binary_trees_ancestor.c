#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	const binary_tree_t *temp;
	const binary_tree_t *temp2;

	/* Handle edge cases where either of the nodes is NULL */
	if (first == NULL || second == NULL)
		return (NULL);

	/* Store the first node to traverse upwards */
	temp = first;
	temp2 = second;
	/* Traverse upwards from the first node */
	while (temp && temp2)
	{
		if (temp == temp2 || temp->parent == temp2 || temp2->parent == temp)
			return ((binary_tree_t *)temp);

		temp = temp->parent;
		temp2 = temp2->parent;
	}

	return (NULL); /* No common ancestor found */
}
