#include <stdio.h>
#include <string.h>
#include "headers/point.h"
#include "headers/segment.h"
#include "headers/square.h"


int menu(char** options, int options_size) {
	for (int i = 0; i < options_size; i++) {
		printf("%c - %s\n", 65 + i, options[i]);
	}
	char choice;
	do {
		scanf("%c", &choice);
	} while (
		!(choice >= 65 && choice < 65 + options_size) && // Upper cased
		!(choice >= 97 && choice < 97 + options_size) // Lower cased
	);
	return choice >= 97 ? choice - 97 : choice - 65;
}

void add_shape() {
	printf("Select a shape:\n");
	char* options = {"Point", "Line", "Circle", "Square", "Rectangle", "Polygon"};
	int shape = menu(options, 6);
}


int main() {
	
	printf("Select an option:\n");
	char* options[] = {"Add a shape", "Display the list of shapes", "Delete a shape", "Draw shapes", "Help"};
	int choice = menu(options, 5);
    return 0;
}


