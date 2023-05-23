/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Line.c
 */

#ifndef LINE_H
#define LINE_H
#include "Point.h"

//creation of the Line structure
typedef struct Line {
    Point *p1;
    Point *p2;
} Line;

//functions defined in the source
Line* create_line(Point *p1, Point *p2);
void delete_line(Line *line);
void print_line(Line *line);

#endif
