//-------------------------------------------------------------------------------------------------
// Opis: Klasa bazowa, zawiera elementy które zbieraj¹ informacje z plików 
//
// Autor: Jakub Lefik		Wersja: 1.0
// Data utworzenia: 19.12.2020
//
//	Historia zmian:							Data:
//  1. Klasa obraz zawiera teraz obraz 		04.02.2021
//
//-------------------------------------------------------------------------------------------------

#ifndef obraz_h
#define obraz_h
#include <set>
#include <iostream>
#include <string>

class obraz 
{
public:									//-------------------4 IRON RULES----------------------
	obraz();								
	obraz(const obraz& Kop);
	obraz operator=(const obraz& row);
	virtual ~obraz();
										//--------------------- Gettery -----------------------
	int getColors_counter();
	
	int uniqueColors;					// Zmienna do której zapisuje colors.size
	void diagnostic();					// Metoda diagnostyczna 
	
protected:								// Zmienne typu protected ¿eby mo¿na by³o dziedziczyæ
	std::set <int> colors;
	int rozmiar_tab;
	int* whole_pic;
	int colors_counter;   
	std::string file_name;
	
};

#endif 
