#include <stdio.h>
#include <stdlib.h>
#include "../headers/Rectangle.h"

Rectangle* create_rectangle(Point *origin, int width, int height) {
	Rectangle* rectangle = (Rectangle*)malloc(sizeof(Rectangle));
	rectangle->origin = origin;
	rectangle->width = width;
	rectangle->height = height;
	return rectangle;
}

void delete_rectangle(Rectangle *rectangle) {
	free(rectangle->origin);
	free(rectangle);
}

void print_rectangle(Rectangle *rectangle) {
	printf("RECTANGLE %d %d %d %d\n", rectangle->origin->pos_x, rectangle->origin->pos_y, rectangle->width, rectangle->height);
}
