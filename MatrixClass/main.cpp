#include <stdlib.h>
#include <iostream>
#include "Matrix.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int r, c;
	std::cout << "¬ведите число строк матрицы:" << "\n";
	std::cin >> r;
	std::cout << "¬ведите число столбцов матрицы:" << "\n";
	std::cin >> c;

	Matrix<double> m(r, c);	

	m = m * 2; 
	m.Show();

	return 0;
}