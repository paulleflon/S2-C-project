#include "../headers/id.h"

unsigned int id = 0;
unsigned int get_next_id() {
	return id++;
}
