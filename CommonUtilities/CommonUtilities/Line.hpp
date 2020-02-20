#pragma once
#include "Vector2.hpp"

namespace CommonUtilities
{
	template <class T>
	class Line
	{
	public:
		Line();
		Line(const Vector2<T>& aPoint, const Vector2<T>& aPoint1);
		void InitWith2Points(const Vector2<T>& aPoint, const Vector2<T>& aPoint1);
		bool Inside(const Vector2<T>& aPosition) const;
		void Normalize();

	private:
		Vector2<T> myPoint;
		Vector2<T> myDirection;
	};

	template <class T>
	inline Line<T>::Line()
	{
		
	}

	template<class T>
	inline Line<T>::Line(const Vector2<T>& aPoint, const Vector2<T>& aPoint1)
	{
		myDirection = aPoint1 - aPoint;
		myPoint = aPoint1;
	}

	template<class T>
	inline void Line<T>::InitWith2Points(const Vector2<T>& aPoint, const Vector2<T>& aPoint1)
	{

	}

	template<class T>
	inline bool Line<T>::Inside(const Vector2<T>& aPosition) const
	{
		return false;
	}

	template<class T>
	inline void Line<T>::Normalize()
	{

	}
}