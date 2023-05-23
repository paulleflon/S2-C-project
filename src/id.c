///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This source file contains shape id related function implementations
/// It is also the file where the global id variable is defined

#include "../headers/id.h"

// The last id is stored
unsigned int id = 0;
// And here we return it and increment it, so that it's not possible that two shapes have the same id
unsigned int get_next_id() {
	return id++;
}
