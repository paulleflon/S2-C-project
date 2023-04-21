#ifndef POINT_H
#define POINT_H

typedef struct Point {
    int x;
    int y;
} Point;

Point* create_point(int x, int y);
void delete_point(Point *point);
void print_point(Point *p);

#endif