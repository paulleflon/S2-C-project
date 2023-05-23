///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This header file contains Point related structures and function declarations

#ifndef POINT_H
#define POINT_H

/** Represents a simple Point */
typedef struct Point {
    int x;
    int y;
} Point;

/**
 * Dynamically allocates a Point
 * @param x The x coordinate of the Point
 * @param y The y coordinate of the Point
 * @return A pointer to the allocated Point
 */
Point* create_point(int x, int y);
/**
 * Frees the memory allocated to the Point
 * @param point The Point to free
 * @return There is nothing to return
 */
void delete_point(Point *point);
/**
 * Prints the Point in the format "POINT X Y"
 * @param point The Point to print
 * @return There is nothing to return
 */
void print_point(Point *p);

#endif