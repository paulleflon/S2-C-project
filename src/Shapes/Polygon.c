/*             Pixel tracer by Adèle Chamoux & Paul Leflon
 * ----------------------------------------------------------------------
 * This source file regroups the functions for the shape "polygon"
 */


#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Shapes/Polygon.h"

//allows to dynamically allocate a structured polygon whose coordinates are given in parameter
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
		int index = 0;
		for (int i = 0; i < n; i+=2)
			poly->points[index++] = create_point(coords[i], coords[i + 1]);
	}
	return poly;
}

//allows to free the memory allocated to the polygon given in parameter
void delete_polygon(Polygon *polygon) {
	int n = polygon->n;
	for (int i = 0; i < n;i++) {
		free(polygon->points[i]);
	}
	free(polygon);
}

//allows to display on the screen the information of a polygon
void print_polygon(Polygon *polygon) {
	printf("POLYGON ");
	int n = polygon->n;
	for (int i = 0; i < n;i++) {
		printf("%d,%d ", polygon->points[i]->x, polygon->points[i]->y);
	}
	printf("\n");
}
