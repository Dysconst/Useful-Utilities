#pragma once
#include <math.h>

namespace CommonUtilities
{
	template <class T>
	class Vector4
	{
	public:
		T x;
		T y;
		T z;
		T w;

		Vector4<T>();

		Vector4<T>(const T& aX, const T& aY, const T& aZ, const T& aW);

		Vector4<T>(const Vector4<T>& aVector) = default;

		~Vector4<T>() = default;

		T LengthSqr() const;

		T Length() const;

		Vector4<T> GetNormalized() const;

		void Normalize();

		T Dot(const Vector4<T>& aVector) const;
	};

	template <class T>
	inline Vector4<T>::Vector4()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	template <class T>
	inline Vector4<T>::Vector4(const T& aX, const T& aY, const T& aZ, const T& aW)
	{
		x = aX;
		y = aY;
		z = aZ;
		w = aW;
	}

	template <class T>
	inline T Vector4<T>::LengthSqr() const
	{
		return (x * x) + (y * y) + (z * z) + (w * w);
	}

	template <class T>
	inline T Vector4<T>::Length() const
	{
		return sqrt((x * x) + (y * y) + (z * z) + (w * w));
	}

	template <class T>
	inline Vector4<T> Vector4<T>::GetNormalized() const
	{
		return Vector4<T>(x, y, z, w) / Length();
	}

	template<class T>
	inline void Vector4<T>::Normalize()
	{
		T vectorLength = Length();
		x /= vectorLength;
		y /= vectorLength;
		z /= vectorLength;
		w /= vectorLength;
	}

	template<class T>
	inline T Vector4<T>::Dot(const Vector4<T>& aVector) const
	{
		return T(x * aVector.x + y * aVector.y + z * aVector.z + w * aVector.w);
	}

	template <class T>
	inline Vector4<T> operator+(const Vector4<T>& aVector, const Vector4<T>& aSecondVector)
	{
		return Vector4<T>(aVector.x + aSecondVector.x, aVector.y + aSecondVector.y, aVector.z + aSecondVector.z, aVector.w + aSecondVector.w);
	}

	template <class T>
	inline Vector4<T> operator-(const Vector4<T>& aVector, const Vector4<T>& aSecondVector)
	{
		return Vector4<T>(aVector.x - aSecondVector.x, aVector.y - aSecondVector.y, aVector.z - aSecondVector.z, aVector.w - aSecondVector.w);
	}

	template <class T>
	inline Vector4<T> operator*(const Vector4<T>& aVector, const T& aScalar)
	{
		return Vector4<T>(aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar, aVector.w * aScalar);
	}

	template <class T>
	inline Vector4<T> operator*(const T& aScalar, const Vector4<T>& aVector)
	{
		return Vector4<T>(aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar, aVector.w * aScalar);
	}

	template <class T>
	inline Vector4<T> operator/(const Vector4<T>& aVector, const T& aScalar)
	{
		return Vector4<T>(aVector.x / aScalar, aVector.y / aScalar, aVector.z / aScalar, aVector.w / aScalar);
	}

	template <class T>
	inline void operator+=(Vector4<T>& aVector, const Vector4<T>& aSecondVector)
	{
		aVector = aVector + aSecondVector;
	}

	template <class T>
	inline void operator-=(Vector4<T>& aVector, const Vector4<T>& aSecondVector)
	{
		aVector = aVector - aSecondVector;
	}

	template <class T>
	inline void operator*=(Vector4<T>& aVector, const T& aScalar)
	{
		aVector = aVector * aScalar;
	}

	template <class T>
	inline void operator/=(Vector4<T>& aVector, const T& aScalar)
	{
		aVector = aVector / aScalar;
	}
}