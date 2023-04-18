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

#ifndef PPM_H
#define PPM_H
#include <fstream>
#include "obraz.h"
// Wiem �e tutaj nie powinny by� za��czane klasy pgm i pbm ale jako �e nie mo�na zmienia� maina musia�em je tu umie�ci� :)
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
	ppm(std::string pic);				// Konstruktor parametrowy do otwierania plik�w, a tak�e wczytywania danych
};

int liczkolory(const obraz& ob);
#endif