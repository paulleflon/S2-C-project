/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Pixel.c
 */

/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Pixel.c
 */

#ifndef PIXEL_H
#define PIXEL_H

#include "Shapes/Shape.h"

//creation of the Pixel structure
typedef struct Pixel {
	int x;
	int y;
} Pixel;

//functions defined in the source
Pixel* create_pixel(int x, int y);
void delete_pixel(Pixel *pixel);
void pixel_point(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
void pixel_line(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
void pixel_rectangle(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
void pixel_square(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
void pixel_polygon(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);

Pixel** create_shape_to_pixel(Shape *shape, int *nb_pixels);
void delete_pixel_shape(Pixel ***pixel_tab, int nb_pixels);

#endif
