#pragma once
#include <array>
#include "Vector3.hpp"
#include "Matrix4x4.hpp"

namespace CommonUtilities
{
	template<class T>
	class Matrix3x3
	{
	public:
		// Creates the identity matrix
		Matrix3x3<T>();

		// Copy Constructor
		Matrix3x3<T>(const Matrix3x3<T>& aMatrix);

		Matrix3x3<T>(const T aXX, const T aXY, const T aXZ, const T aYX, const T aYY, const T aYZ, const T aZX, const T aZY, const T aZZ);

		// Copies top left3x3 part of the Matrix4x4
		Matrix3x3<T>(const Matrix4x4<T>& aMatrix);

		// () operator for accessing element (row, column) for read/write or read, respectively
		T& operator()(const T row, const T column);
		const T& operator()(const T row, const T column) const;

		// Static functions for creating rotation matrices
		static Matrix3x3<T> CreateRotationAroundX(T anAngleInRadians);
		static Matrix3x3<T> CreateRotationAroundY(T anAngleInRadians);
		static Matrix3x3<T> CreateRotationAroundZ(T anAngleInRadians);

		// Static function for creating a transpose of a matrix
		static Matrix3x3<T> Transpose(const Matrix3x3<T>& aMatrixToTranspose);

		Matrix3x3<T> operator=(const Matrix3x3<T> & aRightMatrix);
		bool operator==(const Matrix3x3<T> & aRightMatrix) const;

	private:
		std::array<std::array<T, 3>, 3> myContainer;
	};

	template<class T>
	inline Matrix3x3<T>::Matrix3x3()
	{
		for (int row = 0; row < myContainer.size(); row++)
		{
			for (int column = 0; column < myContainer.size(); column++)
			{
				myContainer[row][column] = 0;
			}
		}

		for (int index = 0; index < myContainer.size(); index++)
		{
			myContainer[index][index] = 1;
		}
	}

	template<class T>
	inline Matrix3x3<T>::Matrix3x3(const Matrix3x3<T>& aMatrix)
	{
		myContainer = aMatrix.myContainer;
	}

	template<class T>
	inline Matrix3x3<T>::Matrix3x3(const T aXX, const T aXY, const T aXZ, const T aYX, const T aYY, const T aYZ, const T aZX, const T aZY, const T aZZ)
	{
		myContainer[0][0] = aXX;
		myContainer[0][1] = aXY;
		myContainer[0][2] = aXZ;

		myContainer[1][0] = aYX;
		myContainer[1][1] = aYY;
		myContainer[1][2] = aYZ;

		myContainer[2][0] = aZX;
		myContainer[2][1] = aZY;
		myContainer[2][2] = aZZ;
	}

	template<class T>
	inline Matrix3x3<T>::Matrix3x3(const Matrix4x4<T>& aMatrix)
	{
		for (int row = 0; row < myContainer.size(); row++)
		{
			for (int column = 0; column < myContainer.size(); column++)
			{
				myContainer[row][column] = aMatrix(row + 1, column +  1);
			}
		}
	}

	template<class T>
	inline const T & Matrix3x3<T>::operator()(const T row, const T column) const
	{
		return myContainer[row - 1][column - 1];
	}

	template<class T>
	inline Matrix3x3<T> Matrix3x3<T>::CreateRotationAroundX(T anAngleInRadians)
	{
		return Matrix3x3<T>(1, 0, 0,
			0, cos(anAngleInRadians), sin(anAngleInRadians),
			0, -sin(anAngleInRadians), cos(anAngleInRadians));
	}

	template<class T>
	inline Matrix3x3<T> Matrix3x3<T>::CreateRotationAroundY(T anAngleInRadians)
	{
		return Matrix3x3<T>(cos(anAngleInRadians), 0, -sin(anAngleInRadians),
							0, 1, 0,
							sin(anAngleInRadians), 0, cos(anAngleInRadians));
	}

	template<class T>
	inline Matrix3x3<T> Matrix3x3<T>::CreateRotationAroundZ(T anAngleInRadians)
	{
		return Matrix3x3<T>(cos(anAngleInRadians), sin(anAngleInRadians), 0,
						   -sin(anAngleInRadians), cos(anAngleInRadians), 0,
							0, 0, 1);
	}

	template<class T>
	inline T & Matrix3x3<T>::operator()(const T row, const T column)
	{
		return myContainer[row - 1][column - 1];
	}

	template<class T>
	inline Matrix3x3<T> Matrix3x3<T>::Transpose(const Matrix3x3<T>& aMatrixToTranspose)
	{
		Matrix3x3<T> transposedMatrix = Matrix3x3<T>();

		for (int row = 0; row < 3; row++)
		{
			for (int column = 0; column < 3; column++)
			{
				transposedMatrix.myContainer[row][column] = aMatrixToTranspose.myContainer[column][row];
			}
		}
		return transposedMatrix;
	}

	template<class T>
	inline Matrix3x3<T> Matrix3x3<T>::operator=(const Matrix3x3<T>& aRightMatrix)
	{
		return Matrix3x3<T>(myContainer[0][0] = aRightMatrix(1,1),
			myContainer[1][0] = aRightMatrix(2,1),
			myContainer[2][0] = aRightMatrix(3,1),
			myContainer[0][1] = aRightMatrix(1,2),
			myContainer[1][1] = aRightMatrix(2,2),
			myContainer[2][1] = aRightMatrix(3,2),
			myContainer[0][2] = aRightMatrix(1,3),
			myContainer[1][2] = aRightMatrix(2,3),
			myContainer[2][2] = aRightMatrix(3,3));
	}

	template<class T>
	inline bool Matrix3x3<T>::operator==(const Matrix3x3<T>& aRightMatrix) const
	{
		return myContainer[0][0] == aRightMatrix(1,1) &&
			myContainer[1][0] == aRightMatrix(2,1) &&
			myContainer[2][0] == aRightMatrix(3,1) &&
			myContainer[0][1] == aRightMatrix(1,2) &&
			myContainer[1][1] == aRightMatrix(2,2) &&
			myContainer[2][1] == aRightMatrix(3,2) &&
			myContainer[0][2] == aRightMatrix(1,3) &&
			myContainer[1][2] == aRightMatrix(2,3) &&
			myContainer[2][2] == aRightMatrix(3,3);
	}

	template<class T>
	inline Matrix3x3<T> operator+(const Matrix3x3<T>& aLeftMatrix, const Matrix3x3<T>& aRightMatrix)
	{
		return Matrix3x3<T>(aLeftMatrix(1,1) + aRightMatrix(1,1), aLeftMatrix(1,2) + aRightMatrix(1,2), aLeftMatrix(1,3) + aRightMatrix(1,3),
			aLeftMatrix(2,1) + aRightMatrix(2,1), aLeftMatrix(2,2) + aRightMatrix(2,2), aLeftMatrix(2,3) + aRightMatrix(2,3),
			aLeftMatrix(3,1) + aRightMatrix(3,1), aLeftMatrix(3,2) + aRightMatrix(3,2), aLeftMatrix(3,3) + aRightMatrix(3,3));
	}

	template<class T>
	inline Matrix3x3<T> operator-(const Matrix3x3<T>& aLeftMatrix, const Matrix3x3<T>& aRightMatrix)
	{
		return Matrix3x3<T>(aLeftMatrix(1,1) - aRightMatrix(1,1), aLeftMatrix(1,2) - aRightMatrix(1,2), aLeftMatrix(1,3) - aRightMatrix(1,3),
			aLeftMatrix(2,1) - aRightMatrix(2,1), aLeftMatrix(2,2) - aRightMatrix(2,2), aLeftMatrix(2,3) - aRightMatrix(2,3),
			aLeftMatrix(3,1) - aRightMatrix(3,1), aLeftMatrix(3,2) - aRightMatrix(3,2), aLeftMatrix(3,3) - aRightMatrix(3,3));

	}

	template<class T>
	inline Matrix3x3<T> operator*(const Matrix3x3<T>& aLeftMatrix, const Matrix3x3<T>& aRightMatrix)
	{
		return Matrix3x3<T>(aLeftMatrix(1,1) * aRightMatrix(1,1) + aLeftMatrix(1,2) * aRightMatrix(2,1) + aLeftMatrix(1,3) * aRightMatrix(3,1),
			aLeftMatrix(1,1) * aRightMatrix(1,2) + aLeftMatrix(1,2) * aRightMatrix(2,2) + aLeftMatrix(1,3) * aRightMatrix(3,2),
			aLeftMatrix(1,1) * aRightMatrix(1,3) + aLeftMatrix(1,2) * aRightMatrix(2,3) + aLeftMatrix(1,3) * aRightMatrix(3,3),

			aLeftMatrix(2,1) * aRightMatrix(1,1) + aLeftMatrix(2,2) * aRightMatrix(2,1) + aLeftMatrix(2,3) * aRightMatrix(3,1),
			aLeftMatrix(2,1) * aRightMatrix(1,2) + aLeftMatrix(2,2) * aRightMatrix(2,2) + aLeftMatrix(2,3) * aRightMatrix(3,2),
			aLeftMatrix(2,1) * aRightMatrix(1,3) + aLeftMatrix(2,2) * aRightMatrix(2,3) + aLeftMatrix(2,3) * aRightMatrix(3,3),

			aLeftMatrix(3,1) * aRightMatrix(1,1) + aLeftMatrix(3,2) * aRightMatrix(2,1) + aLeftMatrix(3,3) * aRightMatrix(3,1),
			aLeftMatrix(3,1) * aRightMatrix(1,2) + aLeftMatrix(3,2) * aRightMatrix(2,2) + aLeftMatrix(3,3) * aRightMatrix(3,2),
			aLeftMatrix(3,1) * aRightMatrix(1,3) + aLeftMatrix(3,2) * aRightMatrix(2,3) + aLeftMatrix(3,3) * aRightMatrix(3,3));
	}

	template<class T>
	inline Vector3<T> operator*(const Vector3<T>& aVector, const Matrix3x3<T>& aMatrix)
	{
		return Vector3<T>(aVector.x * aMatrix(1, 1) + aVector.y * aMatrix(2, 1) + aVector.z * aMatrix(3, 1),
			aVector.x * aMatrix(1, 2) + aVector.y * aMatrix(2, 2) + aVector.z * aMatrix(3, 2),
			aVector.x * aMatrix(1, 3) + aVector.y * aMatrix(2, 3) + aVector.z * aMatrix(3, 3));
	}

	template<class T>
	inline Vector3<T> operator*(const T& aScalar, const Matrix3x3<T>& aMatrix)
	{
		return Vector3<T>(aScalar * aMatrix(1,1), aScalar * aMatrix(1,2), aScalar * aMatrix(1,3),
			aScalar * aMatrix(2,1), aScalar * aMatrix(2,2), aScalar * aMatrix(2,3),
			aScalar * aMatrix(3,1), aScalar * aMatrix(3,2), aScalar * aMatrix(3,3));
	}

	template<class T>
	inline Matrix3x3<T>& operator+=(Matrix3x3<T>& aLeftMatrix, const Matrix3x3<T>& aRightMatrix)
	{
		return aLeftMatrix = aLeftMatrix + aRightMatrix;
	}

	template<class T>
	inline Matrix3x3<T>& operator-=(Matrix3x3<T>& aLeftMatrix, const Matrix3x3<T>& aRightMatrix)
	{
		return aLeftMatrix = aLeftMatrix - aRightMatrix;
	}

	template<class T>
	inline Matrix3x3<T>& operator*=(Matrix3x3<T>& aLeftMatrix, const Matrix3x3<T>& aRightMatrix)
	{
		return aLeftMatrix = aLeftMatrix * aRightMatrix;
	}

	template<class T>
	inline Matrix3x3<T>& operator*=(const Vector3<T>& aVector, const Matrix3x3<T>& aRightMatrix)
	{
		return aVector = aVector * aRightMatrix;
	}

	template<class T>
	inline Matrix3x3<T>& operator*=(const T& aScalar, const Matrix3x3<T>& aRightMatrix)
	{
		return (*this) = aScalar * aRightMatrix;
	}
}