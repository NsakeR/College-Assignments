// Zadanie 4 - Lena 
// Przebudowałem maina tak aby klasa/funkcja (w zależności od realizacji) liczkolor była zbędna w mainie, zamiast tego mozna użyć obraz1->getNumberOfUniqueColors()
// lub skorzystać z okienka diagnostycznego po wykonanym programie
// Program nie obsługuje pomijania komentarzy.
// 
// Przebudowałem maina, ponieważ sądzę, że jest to czystsza oraz bardziej przejrzysta wersja dla potencjalnego użytkownika. 

#include "ppm.h"
#include "pgm.h"
#include "pbm.h"

//int main() {
//	
//	obraz* obraz1;
//	obraz1 = new ppm("lena2.ppm"); 
//	std::cout << std::endl;
//
//	obraz1 = new pbm("lena.pbm");
//	std::cout << std::endl;
//
//	obraz1 = new pgm("lena.pgm");
//
//	delete obraz1;
//
//	system("pause");
//	return 0;
//}


//#include <iostream>
//#include "ppm.h"
//
//
//int main()
//{
//	obraz* obraz1;
//	obraz1 = new ppm("lena2.ppm");
//
//	int kolor;
//
//	kolor = liczkolory(*obraz1);
//
//	std::cout << "Liczba unikalnych kolorow w obrazie ";
//	std::cout << kolor;
//
//	delete obraz1;
//
//	return 0;
//}
