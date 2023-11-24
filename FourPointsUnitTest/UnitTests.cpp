#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>
#include <math.h>
#include <assert.h>
struct POINTS {
	float x;
	float y;
};
extern "C" bool FourPoints();
extern "C" bool IsRectangle(struct POINTS point[4]);
extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" double* angleOfTriangle(double side1, double side2, double side3);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(FourPointsUnitTest)
	{
	public:
		
		TEST_METHOD(TestPointsCreateValidRectangle)
		{
			struct POINTS TestPoint[4];			//create a testpoint that takes the two float values x and y. 

			TestPoint[0] = { 0,0 };				
			TestPoint[1] = { 0,2 };
			TestPoint[2] = { 3,2 };
			TestPoint[3] = { 3,0 };

			bool result = IsRectangle(TestPoint);

			Assert::IsTrue(result);
		}

		TEST_METHOD(TestPointsNotValidRectangle)
		{
			struct POINTS TestPoint[4];

			TestPoint[0] = { 1,2 };
			TestPoint[1] = { 5,2 };
			TestPoint[2] = { 7,6 };
			TestPoint[3] = { 3,4 };
			
			bool result = IsRectangle(TestPoint);

			Assert::IsFalse(result);
		}


		TEST_METHOD(TestNegativePoints1)			//though negative values cannot be used during scanf portion of our main 
		{										//we still need to test it to ensure IsRectangle is working as intended. 
			struct POINTS TestPoint[4];

			TestPoint[0] = { 0, 0 };
			TestPoint[1] = { 0,-2 };
			TestPoint[2] = { -3,2 };
			TestPoint[3] = { 3,0 };

			bool result = IsRectangle(TestPoint);

			Assert::IsFalse(result);
		}

		

		TEST_METHOD(TestNegativePoints2)	{	
			struct POINTS TestPoint[4];

			TestPoint[0] = { 0, 1 };
			TestPoint[1] = { 3,-2 };
			TestPoint[2] = { -3,3 };
			TestPoint[3] = { 3,1 };

			bool result = IsRectangle(TestPoint);

			Assert::IsFalse(result);
		}


		TEST_METHOD(TestNegativePoints3) {
			struct POINTS TestPoint[4];

			TestPoint[0] = { 2, 1 };
			TestPoint[1] = { 1,-2 };
			TestPoint[2] = { -3,2 };
			TestPoint[3] = { 3,-1 };

			bool result = IsRectangle(TestPoint);

			Assert::IsFalse(result);
		}

		TEST_METHOD(TestNegativePoints4) {
			struct POINTS TestPoint[4];

			TestPoint[0] = { 1, 1 };
			TestPoint[1] = { 3,-2 };
			TestPoint[2] = { -4,3 };
			TestPoint[3] = { 3,2 };

			bool result = IsRectangle(TestPoint);

			Assert::IsFalse(result);
		}

		TEST_METHOD(TestNegativePoints5) {
			struct POINTS TestPoint[4];

			TestPoint[0] = { 2, 1 };
			TestPoint[1] = { 2,-2 };
			TestPoint[2] = { -3,3 };
			TestPoint[3] = { 3,3 };

			bool result = IsRectangle(TestPoint);

			Assert::IsFalse(result);
		}

		TEST_METHOD(TestNegativePoints6) {
			struct POINTS TestPoint[4];

			TestPoint[0] = { -3, 1 };
			TestPoint[1] = { 3,-4 };
			TestPoint[2] = { -3,-4 };
			TestPoint[3] = { 3,2 };

			bool result = IsRectangle(TestPoint);

			Assert::IsFalse(result);
		}

		TEST_METHOD(TestNegativePoints7) {
			struct POINTS TestPoint[4];

			TestPoint[0] = { 5, 1 };
			TestPoint[1] = { 3,-5 };
			TestPoint[2] = { -2,3 };
			TestPoint[3] = { 3,3 };

			bool result = IsRectangle(TestPoint);

			Assert::IsFalse(result);
		}

		TEST_METHOD(TestNegativePoints8) {
			struct POINTS TestPoint[4];

			TestPoint[0] = { 0, 4 };
			TestPoint[1] = { 3,-1 };
			TestPoint[2] = { -1,3 };
			TestPoint[3] = { 3,5 };

			bool result = IsRectangle(TestPoint);

			Assert::IsFalse(result);
		}
	};

	TEST_CLASS(TriangleAnalyzerUnitTest)
	{
	public:

		TEST_METHOD(TestMethodIfTriangle)
		{
			//This test is used to verify if the result is a triangle according to Triangle Inequality Theorem
			int side1 = 2;
			int side2 = 3;
			int side3 = 9;

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);

		}

		TEST_METHOD(TestMethodIfZero)
		{
			//This test is used to verify if the triangle has a side equal to zero or below
			int side1 = 0;
			int side2 = 0;
			int side3 = 0;

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(TestMethodIfNegative)
		{
			//This test is used to verify if the triangle has a side equal to zero or below
			int side1 = -2;
			int side2 = 1;
			int side3 = 2;

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(TestMethodIsosceles)
		{
			//This test is used to verify if the triangle is an isosceles triangle
			int side1 = 2;
			int side2 = 2;
			int side3 = 3;

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(TestMethodScalene)
		{
			//This test is used to verify if the triangle is scalene
			int side1 = 2;
			int side2 = 3;
			int side3 = 4;

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Scalene triangle", result);
		}

		TEST_METHOD(TestMethodEquilateral)
		{
			//This test is used to verify if the triangle is equilateral
			int side1 = 2;
			int side2 = 2;
			int side3 = 2;

			char* result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Equilateral triangle", result);
		}


	};

	TEST_CLASS(AngleOfTriangleUnitTest)
	{
	public:

		TEST_METHOD(TestMethodFindAngle1)
		{
			//Testing to see verify if side one will give the angle indicated below
			double side1 = 5;
			double side2 = 6;
			double side3 = 8;
			double* triangleAngle = angleOfTriangle(side1, side2, side3);
			double expectedResult1 = 38.6248, expectedResult2 = 48.5092, expectedResult3 = 92.866;

			assert(fabs(triangleAngle[0] - expectedResult1) < 0.01);
		}

		TEST_METHOD(TestMethodFindAngle2)
		{
			//Testing to see verify if side two will give the angle indicated below
			double side1 = 5;
			double side2 = 6;
			double side3 = 8;
			double* triangleAngle = angleOfTriangle(side1, side2, side3);
			double expectedResult1 = 38.6248, expectedResult2 = 48.5092, expectedResult3 = 92.866;

			assert(fabs(triangleAngle[1] - expectedResult2) < 0.01);
		}

		TEST_METHOD(TestMethodFindAngle3)
		{
			//Testing to see verify if side three will give the angle indicated below
			double side1 = 5;
			double side2 = 6;
			double side3 = 8;
			double* triangleAngle = angleOfTriangle(side1, side2, side3);
			double expectedResult1 = 38.6248, expectedResult2 = 48.5092, expectedResult3 = 92.866;

			assert(fabs(triangleAngle[2] - expectedResult3) < 0.01);
		}

		TEST_METHOD(TestMethodFindAngle4)
		{
			//Testing to see verify if side one will give the angle indicated below
			double side1 = 2;
			double side2 = 2;
			double side3 = 3;
			double* triangleAngle = angleOfTriangle(side1, side2, side3);
			double expectedResult1 = 41.4096, expectedResult2 = 41.4096, expectedResult3 = 97.1808;

			assert(fabs(triangleAngle[0] - expectedResult1) < 0.01);
		}

		TEST_METHOD(TestMethodFindAngle5)
		{
			//Testing to see verify if side two will give the angle indicated below
			double side1 = 2;
			double side2 = 2;
			double side3 = 3;
			double* triangleAngle = angleOfTriangle(side1, side2, side3);
			double expectedResult1 = 41.4096, expectedResult2 = 41.4096, expectedResult3 = 97.1808;

			assert(fabs(triangleAngle[1] - expectedResult2) < 0.01);
		}

		TEST_METHOD(TestMethodFindAngle6)
		{
			//Testing to see verify if side three will give the angle indicated below
			double side1 = 2;
			double side2 = 2;
			double side3 = 3;
			double* triangleAngle = angleOfTriangle(side1, side2, side3);
			double expectedResult1 = 41.4096, expectedResult2 = 41.4096, expectedResult3 = 97.1808;

			assert(fabs(triangleAngle[2] - expectedResult3) < 0.01);
		}

		TEST_METHOD(TestMethodFindAngle7)
		{
			//Testing to see verify if side one will give the angle indicated below
			double side1 = 6;
			double side2 = 6;
			double side3 = 6;
			double* triangleAngle = angleOfTriangle(side1, side2, side3);
			double expectedResult1 = 60, expectedResult2 = 60, expectedResult3 = 60;

			assert(fabs(triangleAngle[0] - expectedResult1) < 0.01);
		}

		TEST_METHOD(TestMethodFindAngle8)
		{
			//Testing to see verify if side two will give the angle indicated below
			double side1 = 6;
			double side2 = 6;
			double side3 = 6;
			double* triangleAngle = angleOfTriangle(side1, side2, side3);
			double expectedResult1 = 60, expectedResult2 = 60, expectedResult3 = 60;

			assert(fabs(triangleAngle[1] - expectedResult2) < 0.01);
		}

		TEST_METHOD(TestMethodFindAngle9)
		{
			//Testing to see verify if side three will give the angle indicated below
			double side1 = 6;
			double side2 = 6;
			double side3 = 6;
			double* triangleAngle = angleOfTriangle(side1, side2, side3);
			double expectedResult1 = 60, expectedResult2 = 60, expectedResult3 = 60;

			assert(fabs(triangleAngle[2] - expectedResult3) < 0.01);
		}
	};

}


