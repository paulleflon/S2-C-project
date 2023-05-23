///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This header file contains Line related structures and function declarations

#ifndef LINE_H
#define LINE_H
#include "Point.h"

/** Represents a simple Line */
typedef struct Line {
    Point *p1;
    Point *p2;
} Line;

/**
 * Dynamically allocates a Line
 * @param p1 The first end of the Line
 * @param p2 The second end of the Line
 * @return A pointer to the allocated Line
 */
Line* create_line(Point *p1, Point *p2);
/**
 * Frees the memory allocated to the Line and its ends
 * @param line The Line to free
 * @return There is nothing to return
 */
void delete_line(Line *line);
/**
 * Prints the Line in the format "LINE X1,Y1 X2,Y2"
 * @param line The Line to print
 * @return There is nothing to return
 */
void print_line(Line *line);

#endif
