//----------------------------------------------------------------------------------------------------------------------------------
// Klasa pochodna Bipanie. Klasa powoduje odtworzenie na g³oœniku kodu Morse'a.
//
//
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
//----------------------------------------------------------------------------------------------------------------------------------

#ifndef BIPANIE_H
#define BIPANIE_H
#include "morse2.h"
#include <windows.h>        // Dla BEEP i SLEEP
#include <sstream>          // Dla stringstreamow 
#include <vector>           // Dla vectora

class Bipanie :
    public morse2
{
public:

    inline void convert(std::string tekst_beep) { morse2::convert(tekst_beep); glosnik(); };        // Przeci¹¿ona funkcja convert
    inline void setExternalInfo(std::string informations_beep) {                                    // Przeci¹¿ona funkcja setExternalInfo, wpisuje do tablicy kolejne informacje

        std::stringstream inf;                 // stringstream konwertuje stringa na typ liczbowy
        inf << informations_beep; 
        std::string temp; 
        temp = inf.str(); 
        while (std::getline(inf, temp)) {       // pobierz stringa
            int f;                              // zadeklaruj inta
            std::stringstream ss(temp);         // zrób stringstreama od temp
            while ((ss >> f))                   // dopóki ss czyta do inta F
                value_tab.push_back(f);         // dodaj inta do vectora
        }
    };

    Bipanie() : freq(0), dash_dur(0), dot_dur(0), char_sleep(0), pause_sleep(0), value_tab(0) { };      // Kontruktor
    //~Bipanie() { };                                                                                     // Destruktor

private: 
    int freq, dash_dur, dot_dur, char_sleep, pause_sleep ;     // Zmienne przechowuj¹ce informacje dla '-', '.' i ' '
    std::vector<int> value_tab;                                // Vector na dowoln¹(!) iloœæ zmiennych

    void glosnik() {                                           // Funkcja odtwarzaj¹ca dŸwiêki 
        std::string Stronk = translate;
        setValues();

        for (int i = 0; i < Stronk.length(); i++)
        {
            if (Stronk[i] == '-')
            {               
                Beep(freq, dash_dur);
                Sleep(char_sleep);
            }
            else if (Stronk[i] == '.')
            {              
                Beep(freq, dot_dur);
                Sleep(char_sleep);
            }
            else if (Stronk[i] == ' ')
            {
                Sleep(pause_sleep);
            }
        }
    }

    void setValues() {                      // Funkcja ustawiaj¹ca wartoœci 
        freq = value_tab[0];    
        dash_dur = value_tab[1];
        dot_dur = value_tab[2];
        char_sleep = value_tab[3];
        pause_sleep = value_tab[4];
    }
};

#endif