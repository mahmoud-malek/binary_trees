#ifndef BINARY_TREES
#define BINARY_TREES

#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/**
 * struct levelorder_queue_s - Binary tree node
 *
 * @node: in the node
 * @next: ode
 */

typedef struct levelorder_queue_s
{
	const binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

/**
 * struct binary_tree_queue_s - Binary tree queue
 *
 * @node:  node
 * @next: ode
 */

typedef struct binary_tree_queue_s
{
	const binary_tree_t *node;
	struct binary_tree_queue_s *next;
} binary_tree_queue_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_queue_t *enqueue(binary_tree_queue_t *queue_head,
							 const binary_tree_t *node);

int is_complete(const binary_tree_t *tree, int index, int node_count);
size_t binary_tree_size(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int is_bst_util(const binary_tree_t *tree, int min, int max);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
bst_t *remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *delete_node(bst_t *root, bst_t *node);
bst_t *inorder_successor_node(bst_t *root);
binary_tree_t *basic_tree(void);
int binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max);
int binary_tree_height2(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *recursive_avl_insert(avl_t **tree, avl_t *parent,
							avl_t **new_node, int value);
int calculate_balance(const binary_tree_t *tree);
size_t calculate_height(const binary_tree_t *tree);
avl_t *array_to_avl(int *array, size_t size);
int node_removal_type(bst_t *root);
int find_successor(bst_t *node);
void balance_avl(avl_t **avl_tree);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *create_avl_from_sorted_array(avl_t *parent, int *array,
									int start, int end);
int binary_tree_is_heap(const binary_tree_t *tree);
int validate_parent(const binary_tree_t *tree);
int is_complete_tree(const binary_tree_t *tree);
int complete_tree_checker(const binary_tree_t *tree, int index, int total_nodes);
size_t tree_size(const binary_tree_t *tree);
heap_t *max_heap_insert(heap_t **root, int value);
size_t tree_size2(const binary_tree_t *tree);

#endif /*Binary trees header*/
