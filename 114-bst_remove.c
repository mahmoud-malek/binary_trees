#include "binary_trees.h"

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 *
 * Return: Once located, the node containing a value equals
 *  to value must be removed and freed.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}

		temp = minValueNode(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
 * minValueNode - Removes a node from a Binary Search Tree
 * @node: Pointer to the root node of the tree where you will remove a node
 *
 * Return: Once located, the node containing a value equals to
 *  value must be removed and freed.
 */

bst_t *minValueNode(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left != NULL)
		current = current->left;
	return (current);
}
