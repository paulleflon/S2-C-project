///========================================================================
///                              VectorEditor
///                     By Adèle Chamoux & Paul Leflon
///========================================================================
/// This source file contains Polygon related function implementations


#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Shapes/Polygon.h"

Polygon* create_polygon(int coords[], int n) {
	Polygon *poly = (Polygon*)malloc(sizeof(Polygon));
	if (n % 2) {
		printf("There should be an even number of coordinates. This polygon will be empty.\n");
		poly->n = 0;
		poly->points = NULL;
	} else {
		// As a parameter, n is the length of coords.
		// However, as an attribute of poly, it's the number of vertices, so half the number of coordinates.
		poly->n = n / 2;
		poly->points = (Point**)malloc(n / 2 * sizeof(Point*));
		int index = 0; // index is the index of a vertice, while i is the index of a coordinate.
		for (int i = 0; i < n; i+=2)
			poly->points[index++] = create_point(coords[i], coords[i + 1]);
	}
	return poly;
}

void delete_polygon(Polygon *polygon) {
	int n = polygon->n;
	for (int i = 0; i < n;i++) {
		free(polygon->points[i]);
	}
	free(polygon);
}

void print_polygon(Polygon *polygon) {
	printf("POLYGON ");
	int n = polygon->n;
	for (int i = 0; i < n;i++) {
		printf("%d,%d ", polygon->points[i]->x, polygon->points[i]->y);
	}
	printf("\n");
}
