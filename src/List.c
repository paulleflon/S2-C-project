///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This source file contains Single Linked List related function implementations
/// It was only used in the first part of the project.

#include <stdlib.h>
#include "../headers/List.h"

Node* create_node(Shape *shape) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = shape;
	node->next = NULL;
	return node;
}

void append_shape(List *lst, Shape *shape) {
	Node *new_node = create_node(shape);
	if (*lst == NULL) {
		*lst = new_node;
	} else {
		Node *current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}