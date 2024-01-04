#include "binary_trees.h"

int abs(int a)
{
	return a < 0 ? -a : a;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int height(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return 0;
	}
	return 1 + max(height(tree->left), height(tree->right));
}

int is_bst(binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
	{
		return 1;
	}
	if (tree->n < min || tree->n > max)
	{
		return 0;
	}
	return is_bst(tree->left, min, tree->n - 1) &&
		   is_bst(tree->right, tree->n + 1, max);
}

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return 1;
	}
	return is_bst(tree, INT_MIN, INT_MAX) &&
		   abs(height(tree->left) - height(tree->right)) <= 1 &&
		   binary_tree_is_avl(tree->left) &&
		   binary_tree_is_avl(tree->right);
}
