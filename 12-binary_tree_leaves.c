#include "binary_trees.h"

/**
 * binary_tree_leaves - Count the leaves in a binary tree.
 * @tree: Pointer to the root of the node of the tree
 * to count the number of leaves from.
 *
 * Return: The number of leaves on the tree, from the root,
 * and 0 if the root is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->right == NULL && tree->left == NULL)
		return (1);
	return (binary_tree_leaves(tree->right) + binary_tree_leaves(tree->left));
}
