#include <stdio.h>
#include <stdbool.h>
#include<math.h> 
#include "triangleSolver.h"

#define DEGREES		57.29578

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 + side2 <= side3 ||
		side1 + side3 <= side2 ||
		side2 + side3 <= side1) {
		result = "Not a triangle";
	}
	else if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
		return 1;
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

double* angleOfTriangle(double side1, double side2, double side3) {
	

	double triangleAngle[3];
	
	triangleAngle[0] = DEGREES * acosf((side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3));
	triangleAngle[1] = DEGREES * acosf((side1 * side1 + side3 * side3 - side2 * side2) / (2 * side1 * side3));
	triangleAngle[2] = DEGREES * acosf((side2 * side2 + side1 * side1 - side3 * side3) / (2 * side1 * side2));

	printf("The first angle is %.3f.\nThe second angle is %.3f.\nThe third angle is %.3f.\n", triangleAngle[0], triangleAngle[1], triangleAngle[2]);
	return triangleAngle;
}



