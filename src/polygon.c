#include <stdio.h>
#include <stdlib.h>
#include "../headers/Polygon.h"


Polygon* create_polygon(int coords[], int n) {
	Polygon *poly = (Polygon *)malloc(sizeof(Polygon));
	// As a parameter, n is the length of coords.
	// However, as an attribute of poly, it's the number of vertices, so half the number of coordinates.
	poly->n = n / 2;
	poly->points = (Point **)malloc(n * sizeof(Point*));
	if (n%2 == 0) {
		int index = 0;
		for (int i = 0; i < n; i+=2)
			poly->points[index++] = create_point(coords[i], coords[i + 1]);
	} else 
		printf("n should be even.");
	return poly;
}

void delete_polygon(Polygon *polygon) {
	int n = polygon->n;
	for (int i = 0; i < n;i++) {
		free(polygon->points[i]);
	}
	free(polygon);
	//polygon = NULL;
}

void print_polygon(Polygon *polygon) {
	printf("POLYGON ");
	int n = polygon->n;
	for (int i = 0; i < n;i++) {
		printf("%d,%d ", polygon->points[i]->pos_x, polygon->points[i]->pos_y);
	}
	printf("\n");
}
