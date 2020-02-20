#pragma once
#include "pch.h"
#include <initializer_list>
#include <assert.h>
#include <new>
#include <type_traits>

namespace CommonUtilities
{
	template<class T, int size>
	class StaticArray
	{
	public:
		StaticArray() = default;
		StaticArray(const StaticArray& aStaticArray);
		StaticArray(const std::initializer_list<T>& aInitList);

		~StaticArray() = default;

		StaticArray& operator=(const StaticArray& aGrowingArray);
		inline T& operator[](const int aIndex);
		inline const T& operator[](const int aIndex) const;

		inline void Insert(const int aIndex, const T& aObject);
		inline auto DeleteAll()->std::enable_if<std::is_pointer<T>::value>;

		const int GetSize() const;
	private:
		int mySize = size;
		T myArray[size];
	};

	template<class T, int size>
	StaticArray<T, size>::StaticArray(const StaticArray & aStaticArray)
	{
		(*this) = aStaticArray;
	}

	template<class T, int size>
	StaticArray<T, size>::StaticArray(const std::initializer_list<T>& aInitList)
	{
		myArray = T[size];

		for (int index = 0; index < size; index++)
		{
			myArray[index] = aInitList[index];
		}
	}

	template<class T, int size>
	StaticArray<T, size>& StaticArray<T, size>::operator=(const StaticArray& aGrowingArray)
	{
		//assert(mySize == aGrowingArray.mySize && "Array of different size can't be used as argument!");
		for (int index = 0; index < mySize; index++)
		{
			myArray[index] = aGrowingArray.myArray[index];
		}
		mySize = aGrowingArray.mySize;
		return (*this);
	}

	template<class T, int size>
	inline T& StaticArray<T, size>::operator[](const int aIndex)
	{
		assert(mySize > aIndex && aIndex >= 0);
		return myArray[aIndex];
	}

	template<class T, int size>
	inline const T& StaticArray<T, size>::operator[](const int aIndex) const
	{
		assert(mySize > aIndex && aIndex >= 0);
		return myArray[aIndex];
	}

	template<class T, int size>
	inline void StaticArray<T, size>::Insert(const int aIndex, const T& aObject)
	{
		assert(aIndex < mySize && aIndex > 0 && "Index out of range!");

		for (int index = aIndex; index < mySize - 1; ++index)
		{
			myArray[index + 1] = myArray[index];
		}

		myArray[aIndex] = aObject;
	}

	template<class T, int size>
	inline auto StaticArray<T, size>::DeleteAll()
		-> std::enable_if<std::is_pointer<T>::value>
	{
		for (auto& aType : myArray)
		{
			delete aType;
			aType = nullptr;
		}
	}

	template<class T, int size>
	const int StaticArray<T, size>::GetSize() const
	{
		return mySize;
	}
}