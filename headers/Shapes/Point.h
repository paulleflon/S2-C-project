/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Point.c
 */

#ifndef POINT_H
#define POINT_H

//creation of the Point structure
typedef struct Point {
    int x;
    int y;
} Point;

//functions defined in the source
Point* create_point(int x, int y);
void delete_point(Point *point);
void print_point(Point *p);

#endif