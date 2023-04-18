//-------------------------------------------------------------------------------------------------
// Opis: Klasa pochodna, otwiera pliki typu .pgm oraz je obs�uguje 
//
// Autor: Jakub Lefik		Wersja: 1.0
// Data utworzenia: 19.12.2020
//
//	Historia zmian:			Data:
//  1. -------------		--.--.----
//
//-------------------------------------------------------------------------------------------------
#include "pgm.h"

pgm::pgm() : obraz()												// Konstruktor bezparametrowy
{
	gray = 0;
}

pgm::pgm(std::string pic)
{
	file_name = pic;

	std::ifstream obr;
	obr.open(file_name, std::ios::in);

	if (obr.is_open() == true) {
		std::clog << "Plik otwarto" << std::endl;				// Komunikat o poprawnym otwarciu pliku
		std::clog << "Licze..." << std::endl;
		obr.seekg(37, std::ios_base::beg);						// Przesuwa wska�nik odczytu danych strumienia na bit 37 (dla pliku pgm jest to miejsce gdzie zaczynaj� si� informacje o kolorze w skali nat�enia szaro�ci)

		while (!obr.eof()) {
			obr >> gray;										// Wczytywanie kolejnych zmiennych w p�tli 

			colors_counter++;									// Postinkrementacja licznika kolor�w 
			rozmiar_tab += 3;
			colors.insert(gray);								// Wstaw unikaln� warto�� do kontenera set (je�li jest ju� taka warto�� w tym kontenerze, nie zostanie ona wpisana ponownie)
		}
		obr.close();
		
		rozmiar_tab = rozmiar_tab - 3;
		whole_pic = new int[rozmiar_tab];

		obr.open(file_name, std::ios::in);

		int data;
		if (obr.is_open() == true) {
			obr.seekg(37, std::ios_base::beg);
			for (int i = 0; i < rozmiar_tab; ++i) {
				obr >> data;
				whole_pic[i] = data;
			}
		}
		obr.close();										// Zaimplementowa�em �atwiejsz� i bardziej przyjazn� mo�liwo�� pozyskania warto�ci z wykonywanego programu
		uniqueColors = colors.size();
		diagnostic();
		
	}
	else { std::cerr << "Plik " << file_name << " nie zostal otworzony"; }
}

pgm::pgm(const pgm& Kop) : obraz(Kop)										// Konstruktor kopiuj�cy
{
	gray = Kop.gray;
}

pgm pgm::operator=(const pgm& Row)								// Przeci��ony operator=
{
	if (this == &Row) return *this;								// sprawdza czy to nie ten sam obiekt 
	else {
		gray = Row.gray;
	}
	return *this;
}

pgm::~pgm()														// Pusty destruktor
{

}
