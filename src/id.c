/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This source file contains the function needed to give an id to every new shape
 */

#include "../headers/id.h"

unsigned int id = 0;

unsigned int get_next_id() {
	return id++;
}
