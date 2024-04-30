#include "binary_trees.h"

/**
 * binary_tree_height_b - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
	{
		return (0);
	}

	left = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
	right = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;

	return ((left > right) ? left : right);
}

/**
 * binary_tree_balance - Computes the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}

	left_height = ((int)binary_tree_height_b(tree->left));
	right_height = ((int)binary_tree_height_b(tree->right));

	return (left_height - right_height);
}