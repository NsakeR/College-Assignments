//-------------------------------------------------------------------------------------------------
// Opis: Klasa pochodna, otwiera pliki typu .ppm oraz je obs�uguje 
//
// Autor: Jakub Lefik		Wersja: 1.0
// Data utworzenia: 19.12.2020
//
//	Historia zmian:			Data:
//  1. -------------		--.--.----
//
//-------------------------------------------------------------------------------------------------

#include "ppm.h"

ppm::ppm() : obraz() 											// Konstruktor bezparametrowy
{ 
	red = 0;
	green = 0;
	blue = 0;
	kolor = 0;
}

ppm::ppm(std::string pic) 
{
	file_name = pic;
	
	std::ifstream obr;
	obr.open(file_name, std::ios::in);

	if (obr.is_open() == true) {
		std::clog << "Plik otwarto" << std::endl;				// Komunikat o poprawnym otwarciu pliku
		std::clog << "Licze... (srednio 6 sekund)" << std::endl;
		obr.seekg(37, std::ios_base::beg);						// Przesuwa wska�nik odczytu danych strumienia na bit 37 (dla pliku ppm jest to miejsce gdzie zaczynaj� si� informacje w formacie RGB)

		while (!obr.eof()) {
			obr >> red;											// Wczytywanie kolejnych zmiennych w p�tli 
			obr >> green;
			obr >> blue;

			kolor = red * 1000000 + green * 1000 + blue;		// r, g, b zawieraj� si� w maksymalnie 3cyfrach, a wi�c 3+3+3=9, nie mo�na ich poprostu do siebie doda� gdy� 192+82+10 == 10+82+192, a to przecie� nie ten sam kolor ;) 

			colors_counter++;									// Postinkrementacja licznika kolor�w
			rozmiar_tab += 3;
			colors.insert(kolor);								// Wstaw unikaln� warto�� do kontenera set (je�li jest ju� taka warto�� w tym kontenerze, nie zostanie ona wpisana ponownie)
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
		obr.close();
		uniqueColors = colors.size();
		diagnostic();											// Zaimplementowa�em �atwiejsz� i bardziej przyjazn� u�ytkownikowi mo�liwo�� pozyskania warto�ci z wykonywanego programu
	}
	else { std::cerr << "Plik " << file_name <<" nie zostal otworzony"; }	// Kontrola b��d�w
}

ppm::ppm(const ppm& Kop) : obraz(Kop)									// Konstruktor kopiuj�cy
{
	file_name = Kop.file_name;
	red = Kop.red;
	blue = Kop.blue;
	green = Kop.green;
	kolor = Kop.kolor;
}

ppm ppm::operator=(const ppm& Row)								// Przeci��ony operator=
{
	if (this == &Row) return *this;								// sprawdza czy to nie ten sam obiekt 
	else {	
		file_name = Row.file_name;
		red = Row.red;
		blue = Row.blue;
		green = Row.green;
		kolor = Row.kolor;
	}
	return *this;
}

ppm::~ppm()												// Pusty destruktor
{

}

int liczkolory(const obraz& ob)
{
	return ob.uniqueColors;
}
