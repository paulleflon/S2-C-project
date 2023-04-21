#include <stdio.h>
#include <stdlib.h>
#include "../headers/Line.h"

Line* create_line(Point *p1, Point *p2) {
    Line *line = (Line*)malloc(sizeof(Line));
	line->p1 = p1;
	line->p2 = p2;
    return line;
}

void delete_line(Line *line) {
	free(line->p1);
	free(line->p2);
	free(line);
}

void print_line(Line *line) {
    printf("LINE %d %d %d %d\n", line->p1->x, line->p1->y, line->p2->x, line->p2->y);
}
