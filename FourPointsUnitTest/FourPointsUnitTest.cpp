#include "pch.h"
#include "CppUnitTest.h"
#include "FourPointsFunctionality.h"
#include <stdbool.h>
#include <FourPointsfunctionality.c>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FourPointsUnitTest
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


		TEST_METHOD(TestNegativePoints)			//though negative values cannot be used during scanf portion of our main 
		{										//we still need to test it to ensure IsRectangle is working as intended. 
			struct POINTS TestPoint[4];

			TestPoint[0] = { 0, 0 };
			TestPoint[1] = { 0,-2 };
			TestPoint[2] = { -3,2 };
			TestPoint[3] = { 3,0 };

			bool result = IsRectangle(TestPoint);

			Assert::IsFalse(result);
		}

		//TODO --> Test More Values, test negative inputs, etc. 
	};
}
