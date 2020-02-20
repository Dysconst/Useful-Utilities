#pragma once
#include <math.h>

namespace CommonUtilities
{
	template <class T>
	class Vector3
	{
	public:
		T x;
		T y;
		T z;

		Vector3<T>();

		Vector3<T>(const T& aX, const T& aY, const T& aZ);

		Vector3<T>(const Vector3<T>& aVector) = default;

		~Vector3<T>() = default;

		T LengthSqr() const;

		T Length() const;

		Vector3<T> GetNormalized() const;

		void Normalize();

		T Dot(const Vector3<T>& aVector) const;

		Vector3<T> Cross(const Vector3<T>& aVector) const;
	};

	template <class T>
	inline Vector3<T>::Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	template <class T>
	inline Vector3<T>::Vector3(const T& aX, const T& aY, const T& aZ)
	{
		x = aX;
		y = aY;
		z = aZ;
	}

	template <class T>
	inline T Vector3<T>::LengthSqr() const
	{
		return (x * x) + (y * y) + (z * z);
	}

	template <class T>
	inline T Vector3<T>::Length() const
	{
		return sqrt((x * x) + (y * y) + (z * z));
	}

	template <class T>
	inline Vector3<T> Vector3<T>::GetNormalized() const
	{
		return Vector3<T>(x, y, z) / Length();
	}

	template<class T>
	inline void Vector3<T>::Normalize()
	{
		T vectorLength = Length();
		x /= vectorLength;
		y /= vectorLength;
		z /= vectorLength;
	}

	template<class T>
	inline T Vector3<T>::Dot(const Vector3<T>& aVector) const
	{
		return T(x * aVector.x + y * aVector.y + z * aVector.z);
	}

	template<class T>
	inline Vector3<T> Vector3<T>::Cross(const Vector3<T>& aVector) const
	{
		return Vector3<T>(y * aVector.z - z * aVector.y, z * aVector.x - x * aVector.z, x * aVector.y - y * aVector.x);
	}
 
	template <class T>
	inline Vector3<T> operator+(const Vector3<T>& aVector, const Vector3<T>& aSecondVector) 
	{
		return Vector3<T>(aVector.x + aSecondVector.x, aVector.y + aSecondVector.y, aVector.z + aSecondVector.z);
	}

	template <class T>
	inline Vector3<T> operator+(const Vector3<T>& aVector, const T& aScalar)
	{
		return Vector3<T>(aVector.x + aScalar, aVector.y + aScalar, aVector.z + aScalar);
	}

	template <class T>
	inline Vector3<T> operator-(const Vector3<T>& aVector, const Vector3<T>& aSecondVector) 
	{
		return Vector3<T>(aVector.x - aSecondVector.x, aVector.y - aSecondVector.y, aVector.z - aSecondVector.z);
	}

	template <class T>
	inline Vector3<T> operator*(const Vector3<T>& aVector, const T& aScalar) 
	{
		return Vector3<T>(aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar);
	}

	template <class T>
	inline Vector3<T> operator*(const T& aScalar, const Vector3<T>& aVector) 
	{
		return Vector3<T>(aVector.x * aScalar, aVector.y * aScalar, aVector.z * aScalar);
	}

	template <class T>
	inline Vector3<T> operator/(const Vector3<T>& aVector, const T& aScalar) 
	{
		return Vector3<T>(aVector.x / aScalar, aVector.y / aScalar, aVector.z / aScalar);
	}
					   
	template <class T>
	inline void operator+=(Vector3<T>& aVector, const Vector3<T>& aSecondVector) 
	{
		aVector = aVector + aSecondVector;
	}

	template <class T>
	inline void operator+=(Vector3<T>& aVector, const T& aScalar)
	{
		aVector = aVector + aScalar;
	}
					   
	template <class T> 
	inline void operator-=(Vector3<T>& aVector, const Vector3<T>& aSecondVector) 
	{
		aVector = aVector - aSecondVector;
	}
					   
	template <class T> 
	inline void operator*=(Vector3<T>& aVector, const T& aScalar) 
	{
		aVector = aVector * aScalar;
	}

	template <class T> 
	inline void operator/=(Vector3<T>& aVector, const T& aScalar) 
	{
		aVector = aVector / aScalar;
	}
}