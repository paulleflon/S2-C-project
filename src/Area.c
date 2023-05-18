#include <stdlib.h>
#include <stdio.h>
#include "../headers/Area.h"
#include "../headers/Pixel.h"

Area* create_area(unsigned int width, unsigned int height) {
	Area* a = (Area*)malloc(sizeof(Area));
	a->mat = (BOOL**) malloc(height * sizeof(BOOL*));
	for (int i = 0; i < height; i++) {
		a->mat[i] = (BOOL*) malloc(width * sizeof(BOOL));
	}
	return a;
}

void add_shape_to_area(Area *area, Shape* shape) {
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
}

void delete_area(Area *area) {
	erase_area(area);
	free(area->shapes);
	for (int i = 0; i < area->height; i++) {
		free(area->mat[i]);
	}
	free(area->mat);
	free(area);
}

void draw_area(Area *area) {
	int nb_pixels;
	Pixel **pixel_tab;
	Pixel *pix;
	for (int i = 0; i < area->nb_shape; i++) {
		pixel_tab = create_shape_to_pixel(area->shapes[area->nb_shape], &nb_pixels);
		for (int j = 0; j < nb_pixels; j++) {
			pix = pixel_tab[j];
			if (pix->x < area->width && pix->y < area->height)
				area->mat[pix->y][pix->x] = 1;
		}
	}
}

void print_area(Area *area) {
	for (int i = 0; i < area->height; i++) {
		for (int j = 0; j < area->width; j++) {
			printf("%c", area->mat[i][j] ? '#' : '.');
		}
		printf("\n");
	}
}