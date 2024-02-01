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
	const binary_tree_t *temp1 = first;
	const binary_tree_t *temp2 = second;

	/* Handle edge cases where either of the nodes is NULL */
	if (first == NULL || second == NULL)
		return (NULL);

	/* Traverse upwards from the first node */
	while (temp1 != temp2)
	{
		temp1 = (temp1 == NULL ? second : temp1->parent);
		temp2 = (temp2 == NULL ? first : temp2->parent);
	}

	return ((binary_tree_t *)temp1);
}
