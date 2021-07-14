#include "Matrix.h"
#include <iostream>

template <typename T>
void Matrix<T>::Create(int rows, int cols)
{
	m_rowsNum = rows;
	m_colsNum = cols;
	m_matrix = new T* [m_rowsNum];
	for (int i = 0; i < m_rowsNum; i++)
	{
		m_matrix[i] = new T[m_colsNum];
	}

	for (int i = 0; i < m_rowsNum; i++)
	{
		for (int j = 0; j < m_colsNum; j++)
		{
			m_matrix[i][j] = 1; // May be zero will be more applicable? Anyway there is minor change.
		}
	}
}

template <typename T>
void Matrix<T>::Destroy()
{
	for (int i = 0; i < m_rowsNum; i++)
	{
		delete[] m_matrix[i];
	}
	// You didn't delete matrix, did you?
}

template <typename T>
Matrix<T>::Matrix()
{
	Create(2, 3);

	//std::cout << "Автоматически создана матрица вида: " << "\n";
	//Show();
}

template <typename T>
Matrix<T>::Matrix(int rows, int cols) : m_rowsNum(rows), m_colsNum(cols)
{
	// Here you can reuse some methods (like Create).

	m_matrix = new T* [m_rowsNum]; // был int
	for (int i = 0; i < m_rowsNum; i++)
	{
		m_matrix[i] = new T[m_colsNum]; // был int
	}

	std::cout << "Enter matrix" << "\n";

	for (int i = 0; i < m_rowsNum; i++)
	{
		for (int j = 0; j < m_colsNum; j++)
		{
			std::cin >> m_matrix[i][j];						
		}	
	}

	// May be it will be better to remove this block o replace it by "Show" method?
	// DEBUG
	std::cout << "Matrix generated. Success." << "\n";
	for (int i = 0; i < m_rowsNum; i++)
	{
		for (int j = 0; j < m_colsNum; j++)
		{
			std::cout << m_matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

template <typename T>
Matrix<T>::~Matrix()
{
	Destroy();
	//Your destructor just call "Destroy" method. Why don't you use only destructor instead of this method?
}

template <typename T>
void Matrix<T>::Show()
{
	for (int i = 0; i < m_rowsNum; i++)
	{
		for (int j = 0; j < m_colsNum; j++)
		{
			std::cout << m_matrix[i][j] << " "; // try to use "\t" instead of spacebar.
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

template <typename T>
void Matrix<T>::Transpose()
{
	// теперь тут требует ввести желаемую матрицу - это некруто и неудобно
	// мжно, конечно, добавить конструктор с заполнением одним числом
	Matrix transp;//(m_colsNum, m_rowsNum);		
	transp.Create(m_colsNum, m_rowsNum);
	
	for (int i = 0; i < m_rowsNum; i++)
	{
		for (int j = 0; j < m_colsNum; j++)
		{
			transp.m_matrix[j][i] = m_matrix[i][j];				
		}		
	}

	// Why don't you use "Destroy" or destructor?
	for (int i = 0; i < m_rowsNum; i++)
	{
		delete[] m_matrix[i];
	}

	// Here you can use "=" operator or copy constructor. If you use copy constructor destructor call will be unnecessary (and code will became simplier) 😉.
	m_colsNum = transp.m_colsNum; 
	m_rowsNum = transp.m_rowsNum; 
	Create(transp.m_rowsNum, transp.m_colsNum);

	for (int i = 0; i < m_rowsNum; i++) 
	{
		for (int j = 0; j < m_colsNum; j++) 
		{
			m_matrix[i][j] = transp.m_matrix[i][j];
		}
	}

	
}


template <typename T>
T* Matrix<T>::operator[] (const int index)
{
	return m_matrix[index];
}

template <typename T>
Matrix<T>& Matrix<T>::operator+(Matrix<T>& secondMatrix)
{
	if (secondMatrix.m_rowsNum == m_rowsNum && secondMatrix.m_colsNum == m_colsNum)
	{
		for (int i = 0; i < m_rowsNum; i++)
		{
			for (int j = 0; j < m_colsNum; j++)
			{
				m_matrix[i][j] = m_matrix[i][j] + secondMatrix.m_matrix[i][j];
			}
		}
				
		return *this;
	}
	else
	{
		std::cout << "Error! Matrixes must be the same size";
	}
}

template <typename T>
Matrix<T>& Matrix<T>::operator-(Matrix<T>& secondMatrix)
{
	if (secondMatrix.m_rowsNum == m_rowsNum && secondMatrix.m_colsNum == m_colsNum)
	{
		for (int i = 0; i < m_rowsNum; i++)
		{
			for (int j = 0; j < m_colsNum; j++)
			{
				m_matrix[i][j] = m_matrix[i][j] - secondMatrix.m_matrix[i][j];
			}
		}

		return *this;
	}
	else
	{
		std::cout << "Error! Matrixes must be the same size";
	}
}

// May be here will be better to use copy constructor. Also it will be more intuitively.
template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>& equalMatrix)
{
	for (int i = 0; i < m_rowsNum; i++)
	{
		for (int j = 0; j < m_colsNum; j++)
		{
			m_matrix[i][j] = equalMatrix.m_matrix[i][j];
		}
	}

	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*(Matrix<T>& secondMatrix)
{
	Matrix res(m_rowsNum, secondMatrix.m_colsNum);
	// Are you using "show" for the debug purposes?
	this->Show();
	secondMatrix.Show();

	if (m_colsNum == secondMatrix.m_rowsNum)
	{
		for (int i = 0; i < m_rowsNum; i++)
		{
			for (int j = 0; j < secondMatrix.m_colsNum; j++)
			{
				res[i][j] = 0; 
				for (int k = 0; k < m_colsNum; k++)
				{
					res[i][j] += m_matrix[i][k] * secondMatrix.m_matrix[k][j];
					
				}
				std::cout << res[i][j] << " ";
			}
			std::cout << "\n";
		}
		return res;
	}
	else
	{
		std::cout << "Error! Cols1 must be equal to Rows2" << "/n";
	}

}

template <typename T>
Matrix<T>& Matrix<T>::operator*(T coeff)
{
	for (int i = 0; i < m_rowsNum; i++)
	{
		for (int j = 0; j < m_colsNum; j++)
		{
			m_matrix[i][j] = m_matrix[i][j] * coeff;
		}
	}
	return *this;
}