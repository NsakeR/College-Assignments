//-------------------------------------------------------------------------------------------------
// Opis: Klasa pochodna, otwiera pliki typu .pgm oraz je obs³uguje 
//
// Autor: Jakub Lefik		Wersja: 1.0
// Data utworzenia: 19.12.2020
//
//	Historia zmian:			Data:
//  1. -------------		--.--.----
//
//-------------------------------------------------------------------------------------------------

#ifndef PGM_H
#define PGM_H
#include <fstream>
#include "obraz.h"

class pgm
	: public obraz
{
private:
	int gray;

public:
	pgm();								//--------------------- 4 IRON RULES --------------------------
	pgm(const pgm& Kop);
	pgm operator=(const pgm& Row);
	virtual ~pgm();

	pgm(std::string pic);				// Konstruktor parametrowy do otwierania plików, a tak¿e wczytywania danych
};

#endif