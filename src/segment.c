#include <stdio.h>
#include <stdlib.h>
#include "../headers/segment.h"

// allows t o dynamically allocate a segment of structured type Line from two points given in parameters
Line *create_line(Point *p1, Point *p2) {
    Line *line = (Line *)malloc(sizeof(Line)); // memory for the Line struct
    if (line != NULL) {
        line->p1 = p1; // p1 is assigned to Line struct
        line->p2 = p2; // p2 is assigned to Line struct
    }
    return line;
}


// allows to free the memory allocated to the segment given in parameter
void delete_line(Line *line) {
    if (line != NULL) {
        free(line -> p1);
        free(line -> p2);
        free(line);
    }
}

// allows to display the information of a segment according to the format: LINE [x1, y1, x2, y2]
void print_line(Line* line) {
    printf("LINE [%d, %d, %d, %d]\n", line->p1->pos_x, line->p1->pos_y, line->p2->pos_x, line->p2->pos_y);
}