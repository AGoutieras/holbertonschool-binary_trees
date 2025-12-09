#include "binary_trees.h"

/**
 * get_height - Measures the height of a node in a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the node in the tree, 0 if tree is NULL
 */
int get_height(const binary_tree_t *tree)
{
	int right_height, left_height;

	if (tree == NULL)
		return (0);
	right_height = get_height(tree->right);
	left_height = get_height(tree->left);
	if (right_height > left_height)
		return (1 + right_height);
	return (1 + left_height);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance
 * factor of.
 *
 * Return: The balance factor, and 0 if the root is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	right_height = get_height(tree->right);
	left_height = get_height(tree->left);
	return (left_height - right_height);
}
