//-------------------------------------------------------------------------------------------------
// Opis: Klasa bazowa, zawiera elementy które zbieraj¹ informacje z plików 
//
// Autor: Jakub Lefik		Wersja: 1.0
// Data utworzenia: 19.12.2020
//
//	Historia zmian:			Data:
//  1. -------------		--.--.----
//
//-------------------------------------------------------------------------------------------------

#include "obraz.h"

obraz::obraz()
{
	colors_counter = 0;
	rozmiar_tab = 0;
	uniqueColors = 0;
	whole_pic = 0;
}

obraz::obraz(const obraz& Kop)
{
	uniqueColors = Kop.uniqueColors;
	rozmiar_tab = Kop.rozmiar_tab;
	colors = Kop.colors;
	colors_counter = Kop.colors_counter;
	whole_pic = Kop.whole_pic;
}

obraz obraz::operator=(const obraz& row)
{
	if (this == &row) return *this;
	else {
		uniqueColors = row.uniqueColors;
		rozmiar_tab = row.rozmiar_tab;
		colors = row.colors;
		colors_counter = row.colors_counter;
		whole_pic = row.whole_pic;
	}
	return *this;
}

obraz::~obraz()
{

}

// -------------------------Gettery-----------------------------

int obraz::getColors_counter()
{
	return colors_counter;
}

void obraz::diagnostic()
{
	char litera;
	std::clog << "Czy pokazac diagnostyke wykonanego programu? (t/n)" << std::endl;
	std::cin >> litera;

	switch (litera) {
	case 't': case 'T':
		std::clog << "Otworzono plik: " << file_name << std::endl;
		std::clog << "Liczba unikalnych kolorow: " << colors.size() << std::endl;
		std::clog << "Liczba wpisanych kolorow:  " << colors_counter - 1 << std::endl;
		break;

	case 'n': case'N':
		break;
	}
}