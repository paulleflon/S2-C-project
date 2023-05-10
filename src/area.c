#include <stdio.h>
#include <stdlib.h>
#include "../headers/area.h"

Area* create_area(unsigned int width, unsigned int height) {
    Area* area = (Area*)malloc(sizeof(Area));  // Allocate memory for the Area structure

    area->width = width;
    area->height = height;
    area->nb_shape = 0;

    // Allocate memory for the pixel matrix
    area->mat = (BOOL**)malloc(width * sizeof(BOOL*));
    for (unsigned int i = 0; i < width; i++) {
        area->mat[i] = (BOOL*)malloc(height * sizeof(BOOL));
    }

    // Initialize all pixels in the matrix to a default value (e.g., FALSE)
    for (unsigned int i = 0; i < width; i++) {
        for (unsigned int j = 0; j < height; j++) {
            area->mat[i][j] = 0;
        }
    }

    return area;
}

void add_shape_to_area(Area* area, Shape* shape) {
    if (area->nb_shape < SHAPE_MAX) {
        area->shapes[area->nb_shape] = shape;
        area->nb_shape++;
    } else {
        // Handle error: Maximum number of shapes reached
    }
}


void clear_area(Area* area) {
    // Reset all pixels in the matrix to a default value (e.g., FALSE)
    for (unsigned int i = 0; i < area->width; i++) {
        for (unsigned int j = 0; j < area->height; j++) {
            area->mat[i][j] = 0;
        }
    }
}


void erase_area(Area* area) {
    for (int i = 0; i < area->nb_shape; i++) {
        free(area->shapes[i]);  // Free the memory allocated for each shape
    }
    area->nb_shape = 0;  // Reset the number of shapes to 0
}


void delete_area(Area* area) {
    erase_area(area);  // Delete all associated shapes

    for (unsigned int i = 0; i < area->width; i++) {
        free(area->mat[i]);  // Free the memory allocated for each row of the pixel matrix
    }

    free(area->mat);  // Free the memory allocated for the pixel matrix
    free(area);       // Free the memory allocated for the Area structure
}


// void draw_area(Area* area);
// void print_area(Area* area);
