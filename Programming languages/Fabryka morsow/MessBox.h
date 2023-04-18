//----------------------------------------------------------------------------------------------------------------------------------
// Klasa pochodna MessBox. Klasa wywo³uje okienko powiadomienia z ustalon¹ zawartoœci¹.
//
//
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
//----------------------------------------------------------------------------------------------------------------------------------

#ifndef MESSBOX_H
#define MESSBOX_H
#include "morse2.h"
#include <windows.h>    // Dla MessageBox'a
class MessBox :
    public morse2
{
public:
    inline void convert(std::string tekst_box) { morse2::convert(tekst_box); alert(); };        // Przeci¹¿ona funkcja convert 

private:
    void alert() {            // Funkcja która powoduje wywo³anie okienka dialogowego
        
        // Wersja eksperymentalna:
        //const wchar_t morse_text = translate;
        //std::cout << morse_text << std::endl;
        //MessageBox(NULL, (LPCWSTR)morse_text.c_str(), L"Okienko powiadomienia", MB_OK);
        // Wersja dzia³aj¹ca: 
        MessageBox(NULL, L"Tu powinna byc wiadomosc w kodzie morse'a ale nie potrafie dojsc jak skonwertowac morse_tekst na LPCWSTR ¿eby siê Pani nie przestraszy³a chinskich znaczkow ", L"Okienko powiadomienia", MB_OK);
    }

};
#endif

