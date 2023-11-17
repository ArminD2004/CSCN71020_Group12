#include <stdio.h>	
#include <stdlib.h>
#include <math.h>
#include "FourPointsFunctionality.h"
#include <stdbool.h>
//Create a program that allows the application to accept four points: Each point is an X Y pair. 
//Check for user input validation to ensure proper values are inputted. 


struct POINTS {
	float x;
	float y;
};

struct POINTS point[4];


bool IsRectangle(struct POINTS point[4]) {

    printf("Your points are: ");
    for (int i = 0; i < 4; i++) {
        printf("P%d(%.2f,%.2f), ", i + 1, point[i].x, point[i].y);
    }

    printf("\n");

    float distance[3];

        for (int i = 0; i < 3; i++) {
        distance[i] = sqrtf(pow(point[i + 1].x - point[i].x, 2) + pow(point[i + 1].y - point[i].y, 2));
        printf("The distance between P%d and P%d is %.2f\n", i + 1, i + 2, distance[i]);
    }

    float D4 = sqrtf(pow(point[3].x - point[0].x, 2) + pow(point[3].y - point[0].y, 2));
    printf("The distance between P4 and P1 is %.2f\n", D4);

    if (distance[0] == distance[2] && distance[1] == D4) {
        printf("\nThese points create a rectangle.\n");

        float perimeter = 2 * (distance[0] + distance[1]);
        printf("\nThe perimeter of the rectangle is: %.2f\n", perimeter);

        float area = distance[0] * distance[1];
        printf("The area of the rectangle is: %.2f\n", area);

        return true;
    }
    else {
        printf("These points do not create a rectangle.\n");
        return false;
    }
}

bool FourPoints() {
	
	printf("Hello. This is the FourPoints function, please enter X & Y values to create a point in the form (X,Y).\n");

    for (int i = 0; i < 4; i++) {

        printf("Enter values for X%d: ", i + 1);
        scanf_s("%f", &point[i].x);

        printf("Enter values for Y%d: ", i + 1);
        scanf_s("%f", &point[i].y);


        if (point[i].x < 0 || point[i].y < 0) {									//Section to check if the input values are > 0. 
            printf("ERROR, values must be greater than or equal to 0.\n");
            exit(1);
        }
	}
	return IsRectangle(point);
}

