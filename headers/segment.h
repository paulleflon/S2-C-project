#ifndef SEGMENT_H
#define SEGMENT_H

typedef struct line{
    Point *p1;
    Point *p2;
}Line;

Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);

#endif
