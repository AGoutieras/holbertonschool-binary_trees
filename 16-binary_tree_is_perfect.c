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
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	right_height = get_height(tree->right);
	left_height = get_height(tree->left);
	if (right_height > left_height)
		return (1 + right_height);
	return (1 + left_height);
}

/**
 * get_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: 0 if tree is NULL, else returns size of the tree.
 */
int get_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + get_size(tree->right) + get_size(tree->left));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if the root
 * is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int tree_height, tree_size;

	if (tree == NULL)
		return (0);
	tree_height = get_height(tree) + 1;
	tree_size = get_size(tree);
	if (tree_size == ((1 << (tree_height)) - 1))
		return (1);
	return (0);
}
