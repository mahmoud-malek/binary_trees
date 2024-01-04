#include "binary_trees.h"

avl_t *avl_remove(avl_t *root, int value);
bst_t *remove_node_bst(bst_t *bst_root, int value);
int node_removal_type(bst_t *root);
int find_successor(bst_t *node);
void balance_avl(avl_t **avl_tree);

/**
 * avl_remove - Removes a node from an AVL tree.
 *
 * @root: A pointer to the root node of the AVL tree for removing a node.
 * @value: The value to remove in the AVL tree.
 *
 * Return: A pointer to the new root node of the tree after
 *         removing the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *avl_root_updated = (avl_t *)remove_node_bst((bst_t *)root, value);

	if (avl_root_updated == NULL)
		return (NULL);

	balance_avl(&avl_root_updated);

	return (avl_root_updated);
}

/**
 * remove_node_bst - Remove a node from a BST tree.
 *
 * @bst_root: Root of the BST tree.
 * @value: Node with this value to remove.
 *
 * Return: The tree changed
 */
bst_t *remove_node_bst(bst_t *bst_root, int value)
{
	int type = 0;

	if (bst_root == NULL)
		return (NULL);

	if (value < bst_root->n)
		remove_node_bst(bst_root->left, value);
	else if (value > bst_root->n)
		remove_node_bst(bst_root->right, value);
	else if (value == bst_root->n)
	{
		type = node_removal_type(bst_root);
		if (type != 0)
			remove_node_bst(bst_root->right, type);
	}
	else
		return (NULL);

	return (bst_root);
}

/**
 * node_removal_type - Function that removes a node depending on its children.
 *
 * @root: Node to remove.
 *
 * Return: 0 if it has no children or other value if it has
 */
int node_removal_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = find_successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * find_successor - Get the next successor, i.e., the minimum node in
 * the right subtree.
 *
 * @node: Tree to check.
 *
 * Return: The min value of this tree.
 */
int find_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = find_successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * balance_avl - Measures balance factor of an AVL tree.
 *
 * @avl_tree: AVL tree to balance.
 *
 * Return: Balanced AVL tree.
 */
void balance_avl(avl_t **avl_tree)
{
	int balance_value;

	if (avl_tree == NULL || *avl_tree == NULL)
		return;

	if ((*avl_tree)->left == NULL && (*avl_tree)->right == NULL)
		return;

	balance_avl(&(*avl_tree)->left);
	balance_avl(&(*avl_tree)->right);

	balance_value = binary_tree_balance((const binary_tree_t *)*avl_tree);

	if (balance_value > 1)
		*avl_tree = binary_tree_rotate_right((binary_tree_t *)*avl_tree);
	else if (balance_value < -1)
		*avl_tree = binary_tree_rotate_left((binary_tree_t *)*avl_tree);
}
