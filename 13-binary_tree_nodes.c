#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child
 * @tree: Pointer to the root node of the tree to count the nodes
 * Return: Number of nodes with at least one child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t n = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		n++;

	n += binary_tree_nodes(tree->left);
	n += binary_tree_nodes(tree->right);

	return (n);
}
