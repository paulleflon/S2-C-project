#ifndef PIXEL_H
#define PIXEL_H

#include "Shapes/Shape.h"

typedef struct Pixel {
	int x;
	int y;
} Pixel;

Pixel* create_pixel(int x, int y);
void delete_pixel(Pixel *pixel);

void pixel_point(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
void pixel_line(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
void pixel_rectangle(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
void pixel_square(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
void pixel_polygon(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);

#endif
