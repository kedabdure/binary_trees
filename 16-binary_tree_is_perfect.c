#include "binary_trees.h"

/**
 * binary_tree_height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_count_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes in the tree
 */
size_t binary_tree_count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_count_nodes(tree->left) +
			binary_tree_count_nodes(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, nodes, max_nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	nodes = binary_tree_count_nodes(tree);
	max_nodes = (1 << height) - 1;

	return (nodes == max_nodes);
}
