#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 *         If no common ancestor was found, returns NULL.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t depth_first = 0, depth_second = 0;
	const binary_tree_t *f = first, *s = second;

	while (f->parent != NULL)
	{
		f = f->parent;
		depth_first++;
	}

	while (s->parent != NULL)
	{
		s = s->parent;
		depth_second++;
	}

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	while (first != second)
	{
		first = first->parent;
		second = second->parent;

		if (first == NULL || second == NULL)
			return (NULL);
	}

	return ((binary_tree_t *)first);
}
