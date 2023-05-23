///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This source file contains Area related function implementations


#include <stdlib.h>
#include <stdio.h>
#include "../headers/Area.h"
#include "../headers/Pixel.h"

Area* create_area(unsigned int width, unsigned int height) {
	Area* a = (Area*)malloc(sizeof(Area));
	// Dynamically allocating a 2d matrix: We first allocate the matrix, then each of its rows
	a->mat = (BOOL**) malloc(height * sizeof(BOOL*));
	for (int i = 0; i < height; i++) {
		a->mat[i] = (BOOL*) malloc(width * sizeof(BOOL));
	}
    a->nb_shape = 0;
	a->width = width;
	a->height = height;
	return a;
}

void add_shape_to_area(Area *area, Shape* shape) {
	// Making sure we don't try to fill memory that's not allocated
	if (area->nb_shape == SHAPE_MAX)
		return;
	area->shapes[area->nb_shape++] = shape;
}

void clear_area(Area *area) {
	for (int i = 0; i < area->height; i++) {
		for (int j = 0; j < area->width; j++) {
			area->mat[i][j] = 0;
		}
	}
}

void erase_area(Area *area) {
	for (int i = 0; i < area->nb_shape; i++) {
		delete_shape(area->shapes[i]);
	}
	area->nb_shape = 0;
}

void delete_area(Area *area) {
	// erase_area takes care of freeing the stored shapes
	erase_area(area);
	// Then we can safely free the array
	free(area->shapes);
	for (int i = 0; i < area->height; i++) {
		free(area->mat[i]);
	}
	free(area->mat);
	free(area);
}

void draw_area(Area *area) {
	// There is nothing to do here if the area contains no shape.
	if (area->nb_shape == 0)
		return;
	int nb_pixels;
	Pixel **pixel_tab;
	Pixel *pix;
	// We get each shape's pixel list
	for (int i = 0; i < area->nb_shape; i++) {
		nb_pixels = 0;
		pixel_tab = create_shape_to_pixel(area->shapes[i], &nb_pixels);
		for (int j = 0; j < nb_pixels; j++) {
			// Then we loop through each pixels and get its coordinates
			// to fill the corresponding Area pixel.
			pix = pixel_tab[j];
			if (pix->x < area->width && pix->y < area->height)
				area->mat[pix->y][pix->x] = 1;
		}
	}
	delete_pixel_shape(&pixel_tab, nb_pixels);
}

void print_area(Area *area) {
	for (int i = 0; i < area->height; i++) {
		for (int j = 0; j < area->width; j++) {
			printf("%c", area->mat[i][j] ? '#' : '.');
		}
		printf("\n");
	}
}