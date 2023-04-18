//----------------------------------------------------------------------------------------------------------------------------------
// Klasa pochodna Konsola. Klasa powoduje wyrzucenie na ekran konsoli tekstu zamienionego na kod Morse'a. 
//
//
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
//----------------------------------------------------------------------------------------------------------------------------------

#ifndef KONSOLA_H
#define KONSOLA_H
#include "morse2.h"
#include <iostream>     // Dla cout & endl
class Konsola :
    public morse2
{
public:
    inline void convert(std::string tekst_konsola) { morse2::convert(tekst_konsola);  show(); };    // Przeci¹¿ona funkcja convert
    
private: 
    void show() { std::cout << std::endl << translate << std::endl; };          // Funkcja wyrzucaj¹ca translate na konsolê
};

#endif
