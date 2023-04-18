#include <iostream>
#include "macierz.h"

int main()
{
	macierz A, B, C, D;

	A.set(0, 0, 1.0);
	A.set(0, 1, 2.0);
	A.set(1, 0, 3.0);
	A.set(1, 1, 4.0);

	B = A;
	B.set(0, 0, 5.0);
	
	A.getWart(1, 0);

	C = A * B;
	D = B * A;

	std::cout << C;
	std::cout << D;

	if (C == D) std::cout << "rowne";
	system("pause");
	return 0;
}