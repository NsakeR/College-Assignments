/*******************************************************************************************************************/
// Header klasy odpowiadaj¹cej za manipulatory kolorami. 
//
// Autor: Jakub Lefik
// Data utworzenia : 4.12.2020			Wersja 1.0
// 
// Zmiany:
//
/*******************************************************************************************************************/

#ifndef CCOLOR_H
#define CCOLOR_H
#include <iostream>
#include <Windows.h>

std::ostream& defcolor(std::ostream& manip);				// Manipulator ustawiaj¹cy podstawowe kolory konsoli
std::string SetColor(WORD color);							// Manipulator pozwalaj¹cy u¿ytkownikowi ustawiaæ kolory

															// Przeci¹¿one manipulatory kolorów
std::ostream& black(std::ostream& manip);					// Czarnego
std::ostream& blue(std::ostream& manip);					// Niebieskiego
std::ostream& green(std::ostream& manip);					// Zielonego
std::ostream& aqua(std::ostream& manip);					// Akwamarynowego
std::ostream& red(std::ostream& manip);						// Czerwonego
std::ostream& purple(std::ostream& manip);					// Fioletowego
std::ostream& yellow(std::ostream& manip);					// ¯ó³tego
std::ostream& white(std::ostream& manip);					// Bia³ego
std::ostream& gray(std::ostream& manip);					// Szarego
std::ostream& light_blue(std::ostream& manip);				// Jasnoniebieskiego
std::ostream& light_green(std::ostream& manip);				// Jasnozielonego
std::ostream& light_aqua(std::ostream& manip);				// Jasnoakwamarynowego
std::ostream& light_red(std::ostream& manip);				// Jasnoczerwonego
std::ostream& light_purple(std::ostream& manip);			// Jasnofioletowego
std::ostream& light_yellow(std::ostream& manip);			// Jasnozó³tego
std::ostream& bright_white(std::ostream& manip);			// Jasnego bia³ego


#endif