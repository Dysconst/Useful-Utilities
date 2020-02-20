// CUTestBox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StaticArray.hpp"

#define CU CommonUtilities

int main()
{
	CU::StaticArray<int, 10> myIntArray = { 10, 10, 10, 10, 0, 0, 0, 0, 0 };

	std::cout << myIntArray[7] << std::endl;

	return 0;
}