#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 *
 * @array: A pointer to the first element of the sorted array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree, NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (create_avl_from_sorted_array(NULL, array, 0, (int)(size) - 1));
}

/**
 * create_avl_from_sorted_array - Recursively creates an AVL
 *  tree using a sorted array.
 *
 * @parent: Parent of the node to create.
 * @array: Sorted array.
 * @start: Starting index of the array.
 * @end: Ending index of the array.
 *
 * Return: Pointer to the root of the AVL tree created.
 */
avl_t *create_avl_from_sorted_array(avl_t *parent, int *array,
									int start, int end)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (start <= end)
	{
		mid = (start + end) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = create_avl_from_sorted_array(root, array, start, mid - 1);
		root->right = create_avl_from_sorted_array(root, array, mid + 1, end);
		return (root);
	}
	return (NULL);
}
