/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This source file looks after the SLL structure used for this project
 */


#include <stdlib.h>
#include "../headers/List.h"

Node* create_node(Shape *shape) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = shape;
	node->next = NULL;
	return node;
}

int list_length(List lst) {
	int n = 0;
	Node *current = lst;
	while (current != NULL) {
		current = current->next;
		n++;
	}
	return n;
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