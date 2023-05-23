/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This source file contains the function needed to give an id to every new shape
 */

#include "../headers/id.h"

// The last id is stored
unsigned int id = 0;
// And here we return it and increment it, so that it's not possible that two shapes have the same id
unsigned int get_next_id() {
	return id++;
}
