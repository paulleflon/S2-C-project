///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This file header contains Single Linked List related structures and function declarations
/// It was only used in the first part of the project.

#ifndef NODE_H
#define NODE_H
#include "Shapes/Shape.h"

/**
 * Node structure for a Single Linked List
 */
typedef struct Node {
	Shape *value;
	struct Node *next;
} Node;
/**
 * Type representing a pointer to the head of a Single Linked List
 */
typedef Node* List;

/**
 * Dynamically allocates a Node
 * @param shape The shape this Node stores
 * @return A pointer to the allocated Node
 */
Node* create_node(Shape *shape);
/**
 * Appends a shape to a List
 * @param lst A pointer to the list to which we append the shape
 * @param shape The shape to append
 * @return There is nothing to return
 */
void append_shape(List *lst, Shape *shape);

#endif
