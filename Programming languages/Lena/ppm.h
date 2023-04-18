//-------------------------------------------------------------------------------------------------
// Opis: Klasa pochodna, otwiera pliki typu .ppm oraz je obs³uguje 
//
// Autor: Jakub Lefik		Wersja: 1.0
// Data utworzenia: 19.12.2020
//
//	Historia zmian:			Data:
//  1. -------------		--.--.----
//
//-------------------------------------------------------------------------------------------------

#ifndef PPM_H
#define PPM_H
#include <fstream>
#include "obraz.h"
// Wiem ¿e tutaj nie powinny byæ za³¹czane klasy pgm i pbm ale jako ¿e nie mo¿na zmieniaæ maina musia³em je tu umieœciæ :)
#include "pgm.h"
#include "pbm.h"

class ppm
	: public obraz
{														
private: 
	int red, green, blue, kolor;

public :
	ppm();								//--------------------- 4 IRON RULES --------------------------
	ppm(const ppm& Kop);		
	ppm operator=(const ppm& Row);									
	virtual ~ppm();
	ppm(std::string pic);				// Konstruktor parametrowy do otwierania plików, a tak¿e wczytywania danych
};

int liczkolory(const obraz& ob);
#endif