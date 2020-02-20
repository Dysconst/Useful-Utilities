#pragma once
#include <math.h>

namespace CommonUtilities
{
	template <class T>
	class Vector2
	{
	public:
		T x;
		T y;

		Vector2<T>();
		Vector2<T>(const T& aX, const T& aY);
		Vector2<T>(const Vector2<T>& aVector) = default;
		~Vector2<T>() = default;
		T LengthSqr() const;
		T Length() const;
		Vector2<T> GetNormalized() const;
		void Normalize();
		T Dot(const Vector2<T>& aVector) const;
	};

	template <class T>
	inline Vector2<T>::Vector2()
	{
		x = 0;
		y = 0;
	}

	template <class T>
	inline Vector2<T>::Vector2(const T& aX, const T& aY)
	{
		x = aX;
		y = aY;
	}

	template <class T>
	inline T Vector2<T>::LengthSqr() const
	{
		return (x * x) + (y * y);
	}

	template <class T>
	inline T Vector2<T>::Length() const
	{
		return sqrt((x * x) + (y * y));
	}

	template <class T>
	inline Vector2<T> Vector2<T>::GetNormalized() const
	{
		return Vector2<T>(x, y) / Length();
	}

	template<class T>
	inline void Vector2<T>::Normalize()
	{
		T vectorLength = Length();
		x /= vectorLength;
		y /= vectorLength;
	}

	template<class T>
	inline T Vector2<T>::Dot(const Vector2<T>& aVector) const
	{
		return T(x * aVector.x + y * aVector.y);
	}

	template <class T>
	inline Vector2<T> operator+(const Vector2<T>& aVector, const Vector2<T>& aSecondVector)
	{
		return Vector2<T>(aVector.x + aSecondVector.x, aVector.y + aSecondVector.y);
	}

	template <class T>
	inline Vector2<T> operator-(const Vector2<T>& aVector, const Vector2<T>& aSecondVector)
	{
		return Vector2<T>(aVector.x - aSecondVector.x, aVector.y - aSecondVector.y);
	}

	template <class T>
	inline Vector2<T> operator*(const Vector2<T>& aVector, const T& aScalar)
	{
		return Vector2<T>(aVector.x * aScalar, aVector.y * aScalar);
	}

	template <class T>
	inline Vector2<T> operator*(const T& aScalar, const Vector2<T>& aVector)
	{
		return Vector2<T>(aVector.x * aScalar, aVector.y * aScalar);
	}

	template <class T>
	inline Vector2<T> operator/(const Vector2<T>& aVector, const T& aScalar)
	{
		return Vector2<T>(aVector.x / aScalar, aVector.y / aScalar);
	}

	template <class T>
	inline void operator+=(Vector2<T>& aVector, const Vector2<T>& aSecondVector)
	{
		aVector = aVector + aSecondVector;
	}

	template <class T>
	inline void operator-=(Vector2<T>& aVector, const Vector2<T>& aSecondVector)
	{
		aVector = aVector - aSecondVector;
	}

	template <class T>
	inline void operator*=(Vector2<T>& aVector, const T& aScalar)
	{
		aVector = aVector * aScalar;
	}

	template <class T>
	inline void operator/=(Vector2<T>& aVector, const T& aScalar)
	{
		aVector = aVector / aScalar;
	}
}