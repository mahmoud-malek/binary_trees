#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 *  of integers.
 *
 * @heap: A pointer to the root node of the heap to convert.
 * @size: An address to store the size of the array.
 *
 * Return: A sorted array in descending order.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	int extracted_value, index = 0;
	size_t heap_size;

	if (!heap)
		return (NULL);

	heap_size = binary_tree_size(heap);
	*size = heap_size;

	sorted_array = malloc(heap_size * sizeof(int));
	if (!sorted_array)
		return (NULL);

	while (heap)
	{
		extracted_value = heap_extract(&heap);
		sorted_array[index] = extracted_value;
		index++;
	}

	return (sorted_array);
}

/**
 * binary_tree_size - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: If tree is NULL, your function must return 0.
 * In a complete binary tree every level, except possibly the last,
 * is completely filled, and all nodes in the last level
 *  are as far left as possible.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}
