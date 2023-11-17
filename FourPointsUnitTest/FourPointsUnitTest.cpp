#include "pch.h"
#include "CppUnitTest.h"
#include <stdbool.h>
struct POINTS {
	float x;
	float y;
};
extern "C" bool FourPoints();
extern "C" bool IsRectangle(struct POINTS point[4]);

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
}
