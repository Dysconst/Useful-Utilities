#pragma once
#include <initializer_list>
#include <assert.h>
#include <new>
#include <type_traits>

namespace CommonUtilities
{
	template<typename T, int size>
	class StaticArray
	{
	public:
		StaticArray();

		StaticArray(const StaticArray& aStaticArray);
		StaticArray(const std::initializer_list<T>& aInitList);

		~StaticArray() = default;

		StaticArray& operator=(const StaticArray& aGrowingArray);
		inline T& operator[](const int aIndex);
		inline const T& operator[](const int aIndex) const;

		inline void Insert(const int aIndex, const T& aObject);
		inline auto DeleteAll();
		inline auto DeleteAll(std::true_type);
		inline auto DeleteAll(std::false_type);

		const int Count() const;
	private:
		void Init(std::true_type);
		void Init(std::false_type);
		T myArray[size];
		int mySize;
	};

	template<typename T, int size>
	inline StaticArray<T, size>::StaticArray()
	{
		Init(std::conditional_t<std::is_pointer<T>::value, std::true_type, std::false_type>{});
	}

	template<typename T, int size>
	inline void StaticArray<T, size>::Init(std::true_type)
	{
		mySize = size;
		for (int index = 0; index < size; index++)
		{
			myArray[index] = nullptr;
		}
	}

	template<typename T, int size>
	inline void StaticArray<T, size>::Init(std::false_type)
	{
		mySize = size;
	}

	template<typename T, int size>
	StaticArray<T, size>::StaticArray(const StaticArray& aStaticArray)
	{
		(*this) = aStaticArray;
	}

	template<typename T, int size>
	StaticArray<T, size>::StaticArray(const std::initializer_list<T>& aInitList)
	{
		myArray[size];

		int count = 0;
		for (auto& element : aInitList)
		{
			myArray[count] = element;
			++count;
		}
	}

	template<typename T, int size>
	StaticArray<T, size>& StaticArray<T, size>::operator=(const StaticArray& aGrowingArray)
	{
		assert(mySize == aGrowingArray.size && "Array of different size can't be used as argument!");
		for (int index = 0; index < size; index++)
		{
			myArray[index] = aGrowingArray.myArray[index];
		}
		size = aGrowingArray.size;
		return (*this);
	}

	template<typename T, int size>
	inline T& StaticArray<T, size>::operator[](const int aIndex)
	{
		assert(size > aIndex && aIndex >= 0);
		return myArray[aIndex];
	}

	template<typename T, int size>
	inline const T& StaticArray<T, size>::operator[](const int aIndex) const
	{
		assert(size > aIndex && aIndex >= 0);
		return myArray[aIndex];
	}

	template<typename T, int size>
	inline void StaticArray<T, size>::Insert(const int aIndex, const T & aObject)
	{
		assert(aIndex < mySize && aIndex >= 0 && "Index out of range!");

		for (int index = aIndex; index < size - 1; ++index)
		{
			myArray[index + 1] = myArray[index];
		}

		myArray[aIndex] = aObject;
	}

	template<typename T, int size>
	inline auto StaticArray<T, size>::DeleteAll()
	{
		DeleteAll(std::conditional_t<std::is_pointer<T>::value, std::true_type, std::false_type>{});
	}

	template<typename T, int size>
	inline auto StaticArray<T, size>::DeleteAll(std::true_type)
	{
		for (int index = 0; index < size; ++index)
		{
			if (myArray[index] != nullptr)
			{
				delete myArray[index];
			}

			myArray[index] = nullptr;
		}
	}

	template<typename T, int size>
	inline auto StaticArray<T, size>::DeleteAll(std::false_type)
	{
		throw std::logic_error("This function is not implemented for non-pointer members.");
	}

	template<typename T, int size>
	const int StaticArray<T, size>::Count() const
	{
		return size;
	}
}