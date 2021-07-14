#pragma once

template <typename T>
class Matrix
{
public:
	Matrix(); // ����������� �� ��������� - ������� �-�� 2 �� 3 �� 1
	Matrix(int rows, int cols);
	~Matrix();

	void Show();
	void Transpose();
	
	T* operator[](const int index); 
	Matrix& operator+(Matrix& second);
	Matrix& operator-(Matrix& second);
	Matrix& operator=(Matrix& equal);
	Matrix& operator*(Matrix& second);
	Matrix& operator*(T coeff);

private:

	T** m_matrix; 
	int m_rowsNum;
	int m_colsNum;

	void Create(int rows, int cols);// ������� �-�� ��������� ������� �� ������
	void Destroy();
};