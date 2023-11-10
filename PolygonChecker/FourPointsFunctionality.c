#include <stdio.h>	
#include <stdlib.h>
#include <math.h>
#include "FourPointsFunctionality.h"
//Create a program that allows the application to accept four points: Each point is an X Y pair. 
//Check for user input validation to ensure proper values are inputted. 


struct POINTS {
	float x;
	float y;
};

void FourPoints() {
	struct POINTS point[4];
	float distance[3];

	printf("Hello. This is the FourPoints function, please enter X & Y values to create a point in the form (X,Y).\n");

	for (int i = 0; i < 4; i++) {


		printf("Enter values for X%d: ", i + 1);
		scanf_s("%f", &point[i].x);

		printf("Enter values for Y%d: ", i + 1);
		scanf_s("%f", &point[i].y);


		if (point[i].x < 0 || point[i].y < 0) {									//Section to check if the input values are > 0. 
			printf("ERROR, values must be greater than 0.\n");
			exit(1);
		}
	}
	printf("Your points are: ");

	for (int i = 0; i < 4; i++) {
		printf("P%d(%.2f,%.2f), ", i + 1, point[i].x, point[i].y);
	}

	printf("\n");

	for (int i = 0; i < 3; i++) {
		distance[i] = sqrtf(pow(point[i + 1].x - point[i].x, 2) + pow(point[i + 1].y - point[i].y, 2));
		printf("The distance between P%d and P%d is %.2f\n", i + 1, i + 2, distance[i]);
	}
	float D4 = sqrtf(pow(point[3].x - point[0].x, 2) + pow(point[3].y - point[0].y, 2));
	printf("The distance betwen P4 and P1 is %.2f\n", D4);

}