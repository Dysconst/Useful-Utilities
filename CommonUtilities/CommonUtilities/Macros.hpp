#pragma once
#include <windows.h>
#include <cassert>
#define MAX(a, b) ((a) > (b)) ? (a) : (b);

#define MIN(a, b) ((a) < (b)) ? (a) : (b);

#define SAFE_DELETE(aPointer) delete[] aPointer; \
	aPointer = nullptr;

#define CYCLIC_ERASE(aVector, anIndex)																\
	assert(!aVector.empty() && anIndex >= 0 && anIndex < aVector.size() && "Index out of range!");		\
	if(!aVector.empty() && anIndex >= 0 && anIndex < aVector.size())									\
	{																									\
		aVector[(anIndex)] = aVector.back();															\
		aVector.pop_back();																				\
	}