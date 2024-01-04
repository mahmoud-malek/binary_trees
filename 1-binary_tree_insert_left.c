#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 *         If parent already has a left-child, the new node takes its place,
 *         and the old left-child becomes the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	new_node = binary_tree_node(parent, value);

	/* Check if parent is NULL */
	if (parent == NULL || new_node == NULL)
		return (NULL);

	/* If parent already has a left child */
	if (parent->left != NULL)
	{
		/* Set the new node's left to parent's left */
		new_node->left = parent->left;
		/* Set the old left-child's parent to the new node */
		parent->left->parent = new_node;
	}

	/* Set the new node as the left child of the parent */
	parent->left = new_node;

	return (new_node);
}
