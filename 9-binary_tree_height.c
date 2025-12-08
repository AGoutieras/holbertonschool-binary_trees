#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the node in the tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (0);
	if (binary_tree_height(tree->right) > binary_tree_height(tree->left))
		return (1 + binary_tree_height(tree->right));
	return (1 + binary_tree_height(tree->left));
}
