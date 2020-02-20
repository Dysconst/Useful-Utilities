#include "pch.h"
#include "CppUnitTest.h"
#include "StaticArray.hpp"

#define CU CommonUtilities
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CUSandbox
{
	TEST_CLASS(CUSandbox)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			CU::StaticArray<float, 10> myArray = { 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f };

			myArray.Insert(0, 30.f);
			myArray.DeleteAll();
		}
	};
}