#include <stdio.h>
#include <stdlib.h>
#include "../headers/Line.h"
#include "../headers/Point.h"

// Dynimacally allocates memory for a Line 
Line* create_line(Point *p1, Point *p2) {
    Line *line = (Line*)malloc(sizeof(Line));
	line->p1 = p1;
	line->p2 = p2;
    return line;
}


// Frees the memory allocated to a Line 
void delete_line(Line *line) {
	free(line->p1);
	free(line->p2);
	free(line);
}

// Displays a Line
void print_line(Line *line) {
    printf("LINE %d %d %d %d\n", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}
