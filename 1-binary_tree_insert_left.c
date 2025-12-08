#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child
 * of another node of a binary_tree_t tree. If parent already
 * has a left child, the new node must take its place and the old
 * left-child must be set as the left-child of the new node.
 * @parent: Pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: A pointer to the created node, or NULL on failure,
 * or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left;

	if (parent == NULL)
		return (NULL);
	new_left = malloc(sizeof(binary_tree_t));
	if (new_left == NULL)
		return (NULL);
	new_left->n = value;
	new_left->parent = parent;
	new_left->right = NULL;
	if (parent->left == NULL)
		new_left->left = NULL;
	else
	{
		new_left->left = parent->left;
		(parent->left)->parent = new_left;
	}
	parent->left = new_left;
	return (new_left);
}
