// Zadanie 4 - Lena 
// Program nie obsługuje pomijania komentarzy.
// 

#include <iostream>
#include "ppm.h"

int main()
{
	obraz* obraz1;
	obraz1 = new ppm("lena2.ppm");
	obraz1 = new pgm("lena.pgm");

	int kolor;

	kolor = liczkolory(*obraz1);

	std::cout << "Liczba unikalnych kolorow w obrazie ";
	std::cout << kolor;

	delete obraz1;

	return 0;
}




