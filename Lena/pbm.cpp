//-------------------------------------------------------------------------------------------------
// Opis: Klasa pochodna, otwiera pliki typu .pbm oraz je obs³uguje 
//
// Autor: Jakub Lefik		Wersja: 1.0
// Data utworzenia: 19.12.2020
//
//	Historia zmian:			Data:
//  1. -------------		--.--.----
//
//-------------------------------------------------------------------------------------------------

#include "pbm.h"

pbm::pbm() : obraz()													// Konstruktor bezparametrowy
{
	gray_pbm = 0;
}

pbm::pbm(std::string pic)
{
	file_name = pic;

	std::ifstream obr;
	obr.open(file_name, std::ios::in);

	if (obr.is_open() == true) {
		std::clog << "Plik otwarto" << std::endl;				// Komunikat o poprawnym otwarciu pliku
		std::clog << "Licze..." << std::endl;
		obr.seekg(33, std::ios_base::beg);						// Przesuwa wskaŸnik odczytu danych strumienia na bit 33 (dla pliku pbm jest to miejsce gdzie zaczynaj¹ siê informacje w formacie 1/0 (czarny/bia³y pixel))

		while (!obr.eof()) {
			obr >> gray_pbm;									// Wczytywanie kolejnych zmiennych w pêtli 

			colors_counter++;									// Postinkrementacja licznika kolorów
			rozmiar_tab += 3;
			colors.insert(gray_pbm);							// Wstaw unikaln¹ wartoœæ do kontenera set (jeœli jest ju¿ taka wartoœæ w tym kontenerze, nie zostanie ona wpisana ponownie)
		}
		obr.close();
																
		rozmiar_tab = rozmiar_tab - 3;
		whole_pic = new int[rozmiar_tab];

		obr.open(file_name, std::ios::in);

		int data;
		if (obr.is_open() == true) {
			obr.seekg(33, std::ios_base::beg);
			for (int i = 0; i < rozmiar_tab; ++i) {
				obr >> data;
				whole_pic[i] = data;
			}
		}
		obr.close();
		uniqueColors = colors.size();
		diagnostic();										  // Zaimplementowa³em ³atwiejsz¹ i bardziej przyjazn¹ mo¿liwoœæ pozyskania wartoœci z wykonywanego programu
		
	}
	else { std::cerr << "Plik " << file_name <<" nie zostal otworzony"; }
}

pbm::pbm(const pbm& Kop) : obraz(Kop)										// Konstruktor kopiuj¹cy
{
	gray_pbm = Kop.gray_pbm;
}

pbm pbm::operator=(const pbm& Row)								// Przeci¹¿ony operator=
{
	if (this == &Row) return *this;								// sprawdza czy to nie ten sam obiekt 
	else {
		gray_pbm = Row.gray_pbm;
	}
	return *this;
}

pbm::~pbm()														// Pusty destruktor
{
}