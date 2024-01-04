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
		if (!root->left || !root->right)
		{
			temp = root->left ? root->left : root->right;

			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{

			temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;

			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}

/**
 * findMin - Removes a node from a Binary Search Tree
 * @node: Pointer to the root node of the tree where you will remove a node
 *
 * Return: Once located, the node containing a value equals to
 *  value must be removed and freed.
 */

bst_t *findMin(bst_t *node)
{
	while (node->left != NULL)
	{
		node = node->left;
	}
	return (node);
}
