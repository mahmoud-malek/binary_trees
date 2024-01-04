#include "binary_trees.h"

bst_t *remove_node(bst_t *root, int value);
bst_t *remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *delete_node(bst_t *root, bst_t *node);
bst_t *inorder_successor_node(bst_t *root);

/**
 * remove_node - Removes a node from a Binary Search Tree.
 *
 * @root: A pointer to the root node of the tree where a node will be removed.
 * @value: The value to be removed in the tree.
 *
 * Return: A pointer to the new root node of the tree after the removal.
 */
bst_t *remove_node(bst_t *root, int value)
{
	return (remove_recursive(root, root, value));
}

/**
 * remove_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (delete_node(root, node));
		if (node->n > value)
			return (remove_recursive(root, node->left, value));
		return (remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * delete_node - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *delete_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor_node(node->right);
	node->n = successor->n;

	return (delete_node(root, successor));
}

/**
 * inorder_successor_node - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor_node(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
