#ifndef NODE_H
#define NODE_H
#include "Shapes/Shape.h"

typedef struct Node {
	Shape *value;
	struct Node *next;
} Node;

typedef Node* List;

Node* create_node(Shape *shape);
int list_length(List lst);
void append_shape(List *lst, Shape *shape);
// delete_shape or any other required function to be implemented in the final project.

#endif NODE_H
