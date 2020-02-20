#pragma once
#include <array>
#include "Vector4.hpp"

namespace CommonUtilities
{
	template<class T>
	class Matrix3x3;

	template<class T>
	class Matrix4x4
	{
	public:
		// Creates the identity matrix
		Matrix4x4<T>();

		// Copy Constructor
		Matrix4x4<T>(const Matrix4x4<T>& aMatrix);


		Matrix4x4<T>(const T aXX, const T aXY, const T aXZ, const T aXW,
					 const T aYX, const T aYY, const T aYZ, const T aYW, 
					 const T aZX, const T aZY, const T aZZ, const T aZW, 
					 const T aWX, const T aWY, const T aWZ, const T aWW);

		// Copies top left3x3 part of the Matrix4x4
		Matrix4x4<T>(const Matrix3x3<T>& aMatrix);

		// () operator for accessing element (row, column) for read/write or read, respectively
		T& operator()(const T row, const T column);
		const T& operator()(const T row, const T column) const;

		// Static functions for creating rotation matrices
		static Matrix4x4<T> CreateRotationAroundX(T anAngleInRadians);
		static Matrix4x4<T> CreateRotationAroundY(T anAngleInRadians);
		static Matrix4x4<T> CreateRotationAroundZ(T anAngleInRadians);

		// Static function for creating a transpose of a matrix
		static Matrix4x4<T> Transpose(const Matrix4x4<T>& aMatrixToTranspose);

		Matrix4x4<T> operator=(const Matrix4x4<T> & aRightMatrix);
		bool operator==(const Matrix4x4<T> & aRightMatrix) const;

	private:
		std::array<std::array<T, 4>, 4> myContainer;
	};

	template<class T>
	inline Matrix4x4<T>::Matrix4x4()
	{
		for (int row = 0; row < myContainer.size(); row++)
		{
			for (int column = 0; column < myContainer.size(); column++)
			{
				myContainer[row][column] = 0;
			}
		}

		for (int lineNumber = 0; lineNumber < myContainer.size(); ++lineNumber)
		{
			myContainer[lineNumber][lineNumber] = 1;
		}
	}

	template<class T>
	inline Matrix4x4<T>::Matrix4x4(const Matrix4x4<T>& aMatrix)
	{
		myContainer = aMatrix.myContainer;
	}

	template<class T>
	inline Matrix4x4<T>::Matrix4x4(const T aXX, const T aXY, const T aXZ, const T aXW,
								   const T aYX, const T aYY, const T aYZ, const T aYW,
								   const T aZX, const T aZY, const T aZZ, const T aZW,
								   const T aWX, const T aWY, const T aWZ, const T aWW)
	{
		myContainer[0][0] = aXX;
		myContainer[0][1] = aXY;
		myContainer[0][2] = aXZ;
		myContainer[0][3] = aXW;

		myContainer[1][0] = aYX;
		myContainer[1][1] = aYY;
		myContainer[1][2] = aYZ;
		myContainer[1][3] = aYW;

		myContainer[2][0] = aZX;
		myContainer[2][1] = aZY;
		myContainer[2][2] = aZZ;
		myContainer[2][3] = aZW;

		myContainer[3][0] = aWX;
		myContainer[3][1] = aWY;
		myContainer[3][2] = aWZ;
		myContainer[3][3] = aWW;
	}


	template<class T>
	inline Matrix4x4<T>::Matrix4x4(const Matrix3x3<T>& aMatrix)
	{
		for (int row = 0; row < myContainer.size(); row++)
		{
			for (int column = 0; column < myContainer.size(); column++)
			{
				myContainer[row][column] = 0;
			}
		}

		for (int row = 0; row < aMatrix.myContainer.size(); row++)
		{
			for (int column = 0; column < aMatrix.myContainer.size(); column++)
			{
				myContainer[row][column] = aMatrix.myContainer[row][column];
			}
		}
	}

	template<class T>
	inline const T & Matrix4x4<T>::operator()(const T row, const T column) const
	{
		return myContainer[row - 1][column - 1];
	}

	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundX(T anAngleInRadians)
	{
		return Matrix4x4<T>(1, 0, 0, 0,
			0,  cos(anAngleInRadians), sin(anAngleInRadians), 0,
			0, -sin(anAngleInRadians), cos(anAngleInRadians), 0,
			0, 0, 0, 1);
	}

	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundY(T anAngleInRadians)
	{
		return Matrix4x4<T>(cos(anAngleInRadians), 0, -sin(anAngleInRadians), 0,
			0, 1, 0, 0,
			sin(anAngleInRadians), 0, cos(anAngleInRadians), 0,
			0, 0, 0, 1);
	}

	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::CreateRotationAroundZ(T anAngleInRadians)
	{
		return Matrix4x4<T>(cos(anAngleInRadians), sin(anAngleInRadians), 0, 0,
			-sin(anAngleInRadians), cos(anAngleInRadians), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1);
	}

	template<class T>
	inline T & Matrix4x4<T>::operator()(const T row, const T column)
	{
		return myContainer[row - 1][column - 1];
	}

	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::Transpose(const Matrix4x4<T>& aMatrixToTranspose)
	{
			Matrix4x4<T> transposedMatrix = Matrix4x4<T>();

			for (int row = 0; row < aMatrixToTranspose.myContainer.size(); row++)
			{
				for (int column = 0; column < aMatrixToTranspose.myContainer.size(); column++)
				{
					transposedMatrix.myContainer[row][column] = aMatrixToTranspose.myContainer[column][row];
				}
			}
			return transposedMatrix;
	}

	template<class T>
	inline Matrix4x4<T> Matrix4x4<T>::operator=(const Matrix4x4<T>& aRightMatrix)
	{
		return Matrix4x4<T>(myContainer[0][0] = aRightMatrix(1,1),
							myContainer[1][0] = aRightMatrix(2,1),
							myContainer[2][0] = aRightMatrix(3,1),
							myContainer[3][0] = aRightMatrix(4,1),
							myContainer[0][1] = aRightMatrix(1,2),
							myContainer[1][1] = aRightMatrix(2,2),
							myContainer[2][1] = aRightMatrix(3,2),
							myContainer[3][1] = aRightMatrix(4,2),
							myContainer[0][2] = aRightMatrix(1,3),
							myContainer[1][2] = aRightMatrix(2,3),
							myContainer[2][2] = aRightMatrix(3,3),
							myContainer[3][2] = aRightMatrix(4,3),
							myContainer[0][3] = aRightMatrix(1,4),
							myContainer[1][3] = aRightMatrix(2,4),
							myContainer[2][3] = aRightMatrix(3,4),
							myContainer[3][3] = aRightMatrix(4,4));
	}

	template<class T>
	inline bool Matrix4x4<T>::operator==(const Matrix4x4<T>& aRightMatrix) const
	{
		return myContainer[0][0] == aRightMatrix(1,1) &&
			   myContainer[1][0] == aRightMatrix(2,1) &&
			   myContainer[2][0] == aRightMatrix(3,1) &&
			   myContainer[3][0] == aRightMatrix(4,1) &&
			   myContainer[0][1] == aRightMatrix(1,2) &&
			   myContainer[1][1] == aRightMatrix(2,2) &&
			   myContainer[2][1] == aRightMatrix(3,2) &&
			   myContainer[3][1] == aRightMatrix(4,2) &&
			   myContainer[0][2] == aRightMatrix(1,3) &&
			   myContainer[1][2] == aRightMatrix(2,3) &&
			   myContainer[2][2] == aRightMatrix(3,3) &&
			   myContainer[3][2] == aRightMatrix(4,3) &&
			   myContainer[0][3] == aRightMatrix(1,4) &&
			   myContainer[1][3] == aRightMatrix(2,4) &&
			   myContainer[2][3] == aRightMatrix(3,4) &&
			   myContainer[3][3] == aRightMatrix(4,4);
	}

	template<class T>
	inline Matrix4x4<T> operator+(const Matrix4x4<T>& aLeftMatrix, const Matrix4x4<T>& aRightMatrix)
	{
		return Matrix4x4<T>(aLeftMatrix(1,1) + aRightMatrix(1,1), aLeftMatrix(1,2) + aRightMatrix(1,2), aLeftMatrix(1,3) + aRightMatrix(1,3), aLeftMatrix(1,4) + aRightMatrix(1,4),
							aLeftMatrix(2,1) + aRightMatrix(2,1), aLeftMatrix(2,2) + aRightMatrix(2,2), aLeftMatrix(2,3) + aRightMatrix(2,3), aLeftMatrix(2,4) + aRightMatrix(2,4),
							aLeftMatrix(3,1) + aRightMatrix(3,1), aLeftMatrix(3,2) + aRightMatrix(3,2), aLeftMatrix(3,3) + aRightMatrix(3,3), aLeftMatrix(3,4) + aRightMatrix(3,4),
							aLeftMatrix(4,1) + aRightMatrix(4,1), aLeftMatrix(4,2) + aRightMatrix(4,2), aLeftMatrix(4,3) + aRightMatrix(4,3), aLeftMatrix(4,4) + aRightMatrix(4,4));
	}

	template<class T>
	inline Matrix4x4<T> operator-(const Matrix4x4<T>& aLeftMatrix, const Matrix4x4<T>& aRightMatrix)
	{
		return Matrix4x4<T>(aLeftMatrix(1,1) - aRightMatrix(1,1), aLeftMatrix(1,2) - aRightMatrix(1,2), aLeftMatrix(1,3) - aRightMatrix(1,3), aLeftMatrix(1,4) - aRightMatrix(1,4),
							aLeftMatrix(2,1) - aRightMatrix(2,1), aLeftMatrix(2,2) - aRightMatrix(2,2), aLeftMatrix(2,3) - aRightMatrix(2,3), aLeftMatrix(2,4) - aRightMatrix(2,4),
							aLeftMatrix(3,1) - aRightMatrix(3,1), aLeftMatrix(3,2) - aRightMatrix(3,2), aLeftMatrix(3,3) - aRightMatrix(3,3), aLeftMatrix(3,4) - aRightMatrix(3,4),
							aLeftMatrix(4,1) - aRightMatrix(4,1), aLeftMatrix(4,2) - aRightMatrix(4,2), aLeftMatrix(4,3) - aRightMatrix(4,3), aLeftMatrix(4,4) - aRightMatrix(4,4));
	}

	template<class T>
	inline Matrix4x4<T> operator*(const Matrix4x4<T>& aLeftMatrix, const Matrix4x4<T>& aRightMatrix)
	{
		return Matrix4x4<T>(aLeftMatrix(1,1) * aRightMatrix(1,1) + aLeftMatrix(1,2) * aRightMatrix(2,1) + aLeftMatrix(1,3) * aRightMatrix(3,1) + aLeftMatrix(1,4) * aRightMatrix(4,1),
							aLeftMatrix(1,1) * aRightMatrix(1,2) + aLeftMatrix(1,2) * aRightMatrix(2,2) + aLeftMatrix(1,3) * aRightMatrix(3,2) + aLeftMatrix(1,4) * aRightMatrix(4,2),
							aLeftMatrix(1,1) * aRightMatrix(1,3) + aLeftMatrix(1,2) * aRightMatrix(2,3) + aLeftMatrix(1,3) * aRightMatrix(3,3) + aLeftMatrix(1,4) * aRightMatrix(4,3),
							aLeftMatrix(1,1) * aRightMatrix(1,4) + aLeftMatrix(1,2) * aRightMatrix(2,4) + aLeftMatrix(1,3) * aRightMatrix(3,4) + aLeftMatrix(1,4) * aRightMatrix(4,4),

							aLeftMatrix(2,1) * aRightMatrix(1,1) + aLeftMatrix(2,2) * aRightMatrix(2,1) + aLeftMatrix(2,3) * aRightMatrix(3,1) + aLeftMatrix(2,4) * aRightMatrix(4,1),
							aLeftMatrix(2,1) * aRightMatrix(1,2) + aLeftMatrix(2,2) * aRightMatrix(2,2) + aLeftMatrix(2,3) * aRightMatrix(3,2) + aLeftMatrix(2,4) * aRightMatrix(4,2),
							aLeftMatrix(2,1) * aRightMatrix(1,3) + aLeftMatrix(2,2) * aRightMatrix(2,3) + aLeftMatrix(2,3) * aRightMatrix(3,3) + aLeftMatrix(2,4) * aRightMatrix(4,3),
							aLeftMatrix(2,1) * aRightMatrix(1,4) + aLeftMatrix(2,2) * aRightMatrix(2,4) + aLeftMatrix(2,3) * aRightMatrix(3,4) + aLeftMatrix(2,4) * aRightMatrix(4,4),

							aLeftMatrix(3,1) * aRightMatrix(1,1) + aLeftMatrix(3,2) * aRightMatrix(2,1) + aLeftMatrix(3,3) * aRightMatrix(3,1) + aLeftMatrix(3,4) * aRightMatrix(4,1),
							aLeftMatrix(3,1) * aRightMatrix(1,2) + aLeftMatrix(3,2) * aRightMatrix(2,2) + aLeftMatrix(3,3) * aRightMatrix(3,2) + aLeftMatrix(3,4) * aRightMatrix(4,2),
							aLeftMatrix(3,1) * aRightMatrix(1,3) + aLeftMatrix(3,2) * aRightMatrix(2,3) + aLeftMatrix(3,3) * aRightMatrix(3,3) + aLeftMatrix(3,4) * aRightMatrix(4,3),
							aLeftMatrix(3,1) * aRightMatrix(1,4) + aLeftMatrix(3,2) * aRightMatrix(2,4) + aLeftMatrix(3,3) * aRightMatrix(3,4) + aLeftMatrix(3,4) * aRightMatrix(4,4),

							aLeftMatrix(4,1) * aRightMatrix(1,1) + aLeftMatrix(4,2) * aRightMatrix(2,1) + aLeftMatrix(4,3) * aRightMatrix(3,1) + aLeftMatrix(4,4) * aRightMatrix(4,1),
							aLeftMatrix(4,1) * aRightMatrix(1,2) + aLeftMatrix(4,2) * aRightMatrix(2,2) + aLeftMatrix(4,3) * aRightMatrix(3,2) + aLeftMatrix(4,4) * aRightMatrix(4,2),
							aLeftMatrix(4,1) * aRightMatrix(1,3) + aLeftMatrix(4,2) * aRightMatrix(2,3) + aLeftMatrix(4,3) * aRightMatrix(3,3) + aLeftMatrix(4,4) * aRightMatrix(4,3),
							aLeftMatrix(4,1) * aRightMatrix(1,4) + aLeftMatrix(4,2) * aRightMatrix(2,4) + aLeftMatrix(4,3) * aRightMatrix(3,4) + aLeftMatrix(4,4) * aRightMatrix(4,4));
	}

	template<class T>
	inline Vector4<T> operator*(const Vector4<T>& aVector, const Matrix4x4<T>& aMatrix)
	{
		return Vector4<T>(aVector.x * aMatrix(1,1) + aVector.y * aMatrix(2,1) + aVector.z * aMatrix(3,1) + aVector.w * aMatrix(4,1),
						  aVector.x * aMatrix(1,2) + aVector.y * aMatrix(2,2) + aVector.z * aMatrix(3,2) + aVector.w * aMatrix(4,2),
						  aVector.x * aMatrix(1,3) + aVector.y * aMatrix(2,3) + aVector.z * aMatrix(3,3) + aVector.w * aMatrix(4,3),
						  aVector.x * aMatrix(1,4) + aVector.y * aMatrix(2,4) + aVector.z * aMatrix(3,4) + aVector.w * aMatrix(4,4));
	}

	template<class T>
	inline Vector4<T> operator*(const T& aScalar, const Matrix4x4<T>& aMatrix)
	{
		return Vector4<T>(aScalar * aMatrix(1,1), aScalar * aMatrix(1,2), aScalar * aMatrix(1,3), aScalar * aMatrix(1,4),
						  aScalar * aMatrix(2,1), aScalar * aMatrix(2,2), aScalar * aMatrix(2,3), aScalar * aMatrix(2,4),
						  aScalar * aMatrix(3,1), aScalar * aMatrix(3,2), aScalar * aMatrix(3,3), aScalar * aMatrix(3,4),
						  aScalar * aMatrix(4,1), aScalar * aMatrix(4,2), aScalar * aMatrix(4,3), aScalar * aMatrix(4,4));
	}

	template<class T>
	inline Matrix4x4<T>& operator+=(Matrix4x4<T>& aLeftMatrix, const Matrix4x4<T>& aRightMatrix)
	{
		return aLeftMatrix = aLeftMatrix + aRightMatrix;
	}

	template<class T>
	inline Matrix4x4<T>& operator-=(Matrix4x4<T>& aLeftMatrix, const Matrix4x4<T>& aRightMatrix)
	{
		return aLeftMatrix = aLeftMatrix - aRightMatrix;
	}

	template<class T>
	inline Matrix4x4<T>& operator*=(Matrix4x4<T>& aLeftMatrix, const Matrix4x4<T>& aRightMatrix)
	{
		return aLeftMatrix = aLeftMatrix * aRightMatrix;
	}

	template<class T>
	inline Matrix4x4<T>& operator*=(const Vector4<T>& aVector, const Matrix4x4<T>& aRightMatrix)
	{
		return aVector = aVector * aRightMatrix;
	}

	template<class T>
	inline Matrix4x4<T>& operator*=(const T& aScalar, const Matrix4x4<T>& aRightMatrix)
	{
		return (*this) = aScalar * aRightMatrix;
	}
}