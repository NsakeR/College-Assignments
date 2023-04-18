//-------------------------------------------------------------------------------------------------
// Opis: Klasa pochodna, otwiera pliki typu .pbm oraz je obs�uguje 
//
// Autor: Jakub Lefik		Wersja: 1.0
// Data utworzenia: 19.12.2020
//
//	Historia zmian:			Data:
//  1. -------------		--.--.----
//
//-------------------------------------------------------------------------------------------------


#ifndef PBM_H
#define PBM_H
#include <fstream>
#include "obraz.h"

class pbm
	: public obraz
{
private:
	int gray_pbm;

public:
	pbm();								//--------------------- 4 IRON RULES --------------------------
	pbm(const pbm& Kop);
	pbm operator=(const pbm& Row);
	virtual ~pbm();

	pbm(std::string pic);				// Konstruktor parametrowy do otwierania plik�w, a tak�e wczytywania danych
};

#endif