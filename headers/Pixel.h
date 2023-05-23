/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This is the header file of the source file Pixel.c
 */

#ifndef PIXEL_H
#define PIXEL_H

#include "Shapes/Shape.h"

/**
 * Represents a single displayed pixel
 */
typedef struct Pixel {
	int x;
	int y;
} Pixel;

/**
 * Dynamically allocates a Pixel
 * @param x The x coordinate of the Pixel
 * @param y The y coordinate of the Pixel
 * @return A pointer to the allocated Pixel
 */
Pixel* create_pixel(int x, int y);
/**
 * Frees the memory allocated to a Pixel
 * @param pixel The pixel to free
 * @return There is nothing to return
 */
void delete_pixel(Pixel *pixel);
/**
 * Converts a Point shape to a Pixel list
 * @param shape The shape to convert
 * @param pixel_tab A pointer to the Pixel list to fill
 * @param nb_pixels The amount of Pixel the function filled
 * @return The values "returned" by the function are directly stored in `pixel_tab` and `nb_pixels`
 */
void pixel_point(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
/**
 * Converts a Line shape to a Pixel list
 * @param shape The shape to convert
 * @param pixel_tab A pointer to the Pixel list to fill
 * @param nb_pixels The amount of Pixel the function filled
 * @return The values "returned" by the function are directly stored in `pixel_tab` and `nb_pixels`
 */
void pixel_line(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
/**
 * Converts a Circle shape to a Pixel list
 * @param shape The shape to convert
 * @param pixel_tab A pointer to the Pixel list to fill
 * @param nb_pixels The amount of Pixel the function filled
 * @return The values "returned" by the function are directly stored in `pixel_tab` and `nb_pixels`
 */
void pixel_circle(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
/**
 * Converts a Rectangle shape to a Pixel list
 * @param shape The shape to convert
 * @param pixel_tab A pointer to the Pixel list to fill
 * @param nb_pixels The amount of Pixel the function filled
 * @return The values "returned" by the function are directly stored in `pixel_tab` and `nb_pixels`
 */
void pixel_rectangle(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
/**
 * Converts a Square shape to a Pixel list
 * @param shape The shape to convert
 * @param pixel_tab A pointer to the Pixel list to fill
 * @param nb_pixels The amount of Pixel the function filled
 * @return The values "returned" by the function are directly stored in `pixel_tab` and `nb_pixels`
 */
void pixel_square(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
/**
 * Converts a Polygon shape to a Pixel list
 * @param shape The shape to convert
 * @param pixel_tab A pointer to the Pixel list to fill
 * @param nb_pixels The amount of Pixel the function filled
 * @return The values "returned" by the function are directly stored in `pixel_tab` and `nb_pixels`
 */
void pixel_polygon(Shape *shape, Pixel ***pixel_tab, int *nb_pixels);
/**
 * Converts any shape to a Pixel list
 * @param shape The shape to convert
 * @param nb_pixels The amount of Pixel the function filled
 * @return The generated Pixel list. Its length is stored in `nb_pixels`
 */
Pixel** create_shape_to_pixel(Shape *shape, int *nb_pixels);
/**
 * Frees he memory allocated to a Pixel list
 * @param pixel_tab The pixel List to free
 * @param nb_pixels The length of the list
 * @return There is nothing to return
 */
void delete_pixel_shape(Pixel ***pixel_tab, int nb_pixels);

#endif
