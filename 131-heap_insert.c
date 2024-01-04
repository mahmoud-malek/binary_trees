#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 *
 * @root: A double pointer to the root node of the Heap to insert the value.
 * @value: The value to be inserted into the heap.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *traverse;
	int tree_size, leaves, sub, bit, level, temp;

	if (!root)
		return (NULL);

	if (!(*root))
		return (*root = binary_tree_node(NULL, value));

	tree = *root;
	tree_size = tree_size2(tree);
	leaves = tree_size;

	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);

	if (leaves & 1)
		tree->right = new_node;
	else
		tree->left = new_node;

	traverse = new_node;
	for (; traverse->parent && (traverse->n > traverse->parent->n);
		 traverse = traverse->parent)
	{
		temp = traverse->n;
		traverse->n = traverse->parent->n;
		traverse->parent->n = temp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * tree_size2 - Measures the size of a binary tree.
 *
 * @tree: A pointer to the tree to be measured.
 *
 * Return: Size of the tree, 0 if tree is NULL.
 */
size_t tree_size2(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (tree_size2(tree->left) + tree_size2(tree->right) + 1);
}


/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node of the node to create
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
