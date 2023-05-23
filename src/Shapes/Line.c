/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This source file regroups the functions for the shape "line"
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Shapes/Line.h"

//allows to dynamically allocate a structured line whose coordinates are given in parameter
Line* create_line(Point *p1, Point *p2) {
    Line *line = (Line*)malloc(sizeof(Line));
	line->p1 = p1;
	line->p2 = p2;
    return line;
}

//allows to free the memory allocated to the line given in parameter
void delete_line(Line *line) {
	free(line->p1);
	free(line->p2);
	free(line);
}

//allows to display on the screen the information of a line
void print_line(Line *line) {
    printf("LINE %d %d %d %d\n", line->p1->x, line->p1->y, line->p2->x, line->p2->y);
}
