#include <stdlib.h>
#include <stdio.h>
#include "../headers/Pixel.h"
Pixel* create_pixel(int x, int y) {
	Pixel* p = (Pixel*) malloc(sizeof(Pixel));
	p->x = x;
	p->y = y;
	return p;
}

void delete_pixel(Pixel* pixel) {
	free(pixel);
}

void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels) {
	Point* pt = (Point*) shape->ptrShape;
	*pixel_tab = (Pixel**) malloc(sizeof (Pixel*));
	*pixel_tab[0] = create_pixel(pt->x, pt->y);
	*nb_pixels = 1;
}

void pixel_line(Shape* shape, Pixel*** pixel_tab, int* nb_pixels) {
	Line* l = (Line*) shape->ptrShape;
	Point* a = (l->p1->x > l->p2->x) ? l->p2 : l->p1;
	Point* b = (l->p1->x > l->p2->x) ? l->p1 : l->p2;
	int dx = b->x - a->x;
	int dy = b->y - a->y;
	int dmin = (dx < abs(dy)) ? dx : abs(dy);
	int dmax = (dx > abs(dy)) ? dx : abs(dy);
	int nb_lines = dmin + 1;
	int line_length = (dmax + 1)/(dmin + 1);

	int* lines = (int*) malloc(nb_lines * sizeof(int));
	for (int i = 0; i < nb_lines; i++)
		lines[i] = line_length;

	int remaining = (dmax + 1) % (dmin + 1);
	int *cumuls = (int*) malloc(nb_lines * sizeof(int));
	cumuls[0] = 0;
	for (int i = 0; i < nb_lines; i++) {
		cumuls[i] = ((i+1)*remaining) % (dmin + 1) < (i * remaining)%(dmin+1);
		lines[i] = lines[i] + cumuls[i];
	}
	*pixel_tab = (Pixel**) malloc(nb_lines * line_length * sizeof(Pixel*));
	*nb_pixels = 0;
	if (dy < 0) {
		if (dx > abs(dy)) {
			int y = b->y - dy;
			int x = a->x;
			for (int i = 0; i < nb_lines; i++) {
				for (int j = 0; j < lines[i]; j++) {
					(*pixel_tab)[(*nb_pixels)++] = create_pixel(x++, y);
				}
				y--;
			}
		} else {
			int y = b->y - dy;
			int x = a->x;
			for (int i = 0; i < nb_lines; i++) {
				for (int j = 0; j < lines[i]; j++) {
					(*pixel_tab)[(*nb_pixels)++] = create_pixel(x, y--);
				}
				x++;
			}
		}
	} else {
		if (dx > dy) {
			int y = b->y - dy;
			int x = a->x;
			for (int i = 0; i < nb_lines; i++) {
				for (int j = 0; j < lines[i]; j++) {
					(*pixel_tab)[(*nb_pixels)++] = create_pixel(x++, y);
				}
				y++;
			}
		} else {
			int y = b->y - dy;
			int x = a->x;
			for (int i = 0; i < nb_lines; i++) {
				for (int j = 0; j < lines[i]; j++) {
					(*pixel_tab)[(*nb_pixels)++] = create_pixel(x, y++);
				}
				x++;
			}
		}
	}
}

void pixel_circle(Shape *shape, Pixel ***pixel_tab, int *nb_pixels) {
	Circle *circle = (Circle*) shape->ptrShape;
	int radius = circle->radius,
		px = circle->center->x,
		py = circle->center->y,
		x = 0,
		y = radius,
		d = 1 - radius;
	*pixel_tab = NULL;
	*nb_pixels = 0;
	while (x < y) {
		*pixel_tab = (Pixel**)realloc(*pixel_tab, (*nb_pixels + 8) * sizeof(Pixel*));
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(px + x, py + y);
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(px + y, py + x);
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(px - x, py + y);
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(px - y, py + x);
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(px + x, py - y);
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(px + y, py - x);
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(px - x, py - y);
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(px - y, py - x);
		if (d >= 2 * x) {
			d-= 2*x + 1;
			x++;
		} else if (d < 2 * (radius - y)) {
			d+= 2*y - 1;
			y--;
		} else {
			d+= 2*(y - x - 1);
			y--;
			x++;
		}
	}
}

void pixel_rectangle(Shape *shape, Pixel ***pixel_tab, int *nb_pixels) {
	Rectangle *r = (Rectangle *)shape->ptrShape;
	int x = r->origin->x,
		y = r->origin->y,
		w = r->width,
		h = r->height;

	*pixel_tab = (Pixel**) malloc(2 * (w + h) * sizeof(Pixel*));
	*nb_pixels = 0;
	int tx = x, ty = y;
	while (tx < x + w - 1) { // Top
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(tx++, ty);
	}

	while (ty < y + h - 1) { // Right
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(tx, ty++);
	}

	while (tx > x) { // Bottom
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(tx--, ty);
	}

	while (ty > y) { // Left
		(*pixel_tab)[(*nb_pixels)++] = create_pixel(tx, ty--);
	}
}

void pixel_square(Shape *shape, Pixel ***pixel_tab, int *nb_pixels) {
	Square *s = (Square*) shape->ptrShape;
	Shape *rectangle = create_rectangle_shape(s->origin->x, s->origin->y, s->length, s->length);
	pixel_rectangle(rectangle, pixel_tab, nb_pixels);
}

void pixel_polygon(Shape *shape, Pixel ***pixel_tab, int *nb_pixels) {
	Polygon *poly = (Polygon*) shape->ptrShape;

	Pixel **temp_tab;
	int temp_nb = 0;
	Shape *line;
	Point *p1, *p2;
	for (int i = 0 ; i < poly->n - 1; i++) {
		p1 = poly->points[i];
		p2 = poly->points[i + 1];
		line = create_line_shape(p1->x, p1->y, p2->x, p2->y);
		pixel_line(line, &temp_tab, &temp_nb);
		*pixel_tab = (Pixel**) realloc(*pixel_tab, (*nb_pixels + temp_nb) * sizeof(Pixel*));
		for (int j = 0; j < temp_nb; j++) {
			(*pixel_tab)[(*nb_pixels)++] = temp_tab[j];
		}
	}
}

Pixel** create_shape_to_pixel(Shape *shape, int *nb_pixels) {
	Pixel **tab;
	switch(shape->type) {
		case point:
			pixel_point(shape, &tab, nb_pixels);
			break;
		case line:
			pixel_line(shape, &tab, nb_pixels);
			break;
		case circle:
			pixel_circle(shape, &tab, nb_pixels);
			break;
		case rectangle:
			pixel_rectangle(shape, &tab, nb_pixels);
			break;
		case square:
			pixel_square(shape, &tab, nb_pixels);
			break;
		case polygon:
			pixel_polygon(shape, &tab, nb_pixels);
			break;
	}
	return tab;
}

void delete_pixel_shape(Pixel ***pixel_tab, int nb_pixels) {
	for (int i = 0; i < nb_pixels; i++) {
		free((*pixel_tab)[i]);
	}
	free(pixel_tab);
}