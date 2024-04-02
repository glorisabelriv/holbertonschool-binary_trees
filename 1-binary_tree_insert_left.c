#include "binary_trees.h"
/**
 * binary_tree_insert_left - insert a node the left-child
 * @parent- is the pointerto the node
 * @value- value to store in the new node
 * Return: a pointer to created node, or Null
 */


binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	
    if (parent == NULL)
	{
		return (NULL);
	}

	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
	{
		return (NULL);
	}

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left = new_node;
	}
	else
	{
		parent->left = new_node;
	}
	return (new_node);

}
