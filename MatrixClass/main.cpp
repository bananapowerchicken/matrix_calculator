#include <stdlib.h>
#include <iostream>
#include "Matrix.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int r, c;
	std::cout << "������� ����� ����� �������:" << "\n";
	std::cin >> r;
	std::cout << "������� ����� �������� �������:" << "\n";
	std::cin >> c;

	Matrix<double> m(r, c);	

	m = m * 2; 
	m.Show();

	return 0;
}