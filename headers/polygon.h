#ifndef POLYGON_H
#define POLYGON_H

typedef struct polygon {
    int n;
    Point ** points; // 1D dynamical array of Point*
}Polygon;

Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);

#endif
