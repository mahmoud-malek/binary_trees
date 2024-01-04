#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created AVL tree, NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *avl_tree = NULL;
	size_t outer_index, inner_index;

	if (array == NULL)
		return (NULL);

	for (outer_index = 0; outer_index < size; outer_index++)
	{
		for (inner_index = 0; inner_index < outer_index; inner_index++)
		{
			if (array[inner_index] == array[outer_index])
				break;
		}
		if (inner_index == outer_index)
		{
			if (avl_insert(&avl_tree, array[outer_index]) == NULL)
				return (NULL);
		}
	}

	return (avl_tree);
}
