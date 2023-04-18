/*******************************************************************************************************************/
// Header klasy odpowiadaj¹cej za manipulacje tekstem w konsoli  
//
// Autor: Jakub Lefik
// Data utworzenia : 4.12.2020						 Wersja 1.0
// 
// Zmiany:
//
/*******************************************************************************************************************/

#ifndef EDIT_H
#define EDIT_H

#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>														// Plik potrzebny do funkcji _getch()

class Edit
{
public:
	enum Colors {														// Enumerator przechowuj¹cy nazwy kolorów 
		Black, 
		Blue, 
		Green, 
		Aqua, 
		Red, 
		Purple, 
		Yellow, 
		White, 
		Gray, 
		Light_Blue, 
		Light_Green, 
		Light_Aqua, 
		Light_Red, 
		Light_Purple, 
		Light_Yellow,
		Bright_White };
																		//_______________4 IRON RULES________________
	Edit();																// Konstruktor bezparametrowy
	Edit(const Edit & Kop);												// Konstruktor kopiuj¹cy
	Edit operator=(const Edit& Row);									// Przeci¹¿ony operator przypisania
	~Edit();															// Destruktor 
	
																		// Settery:
	void setPosition(unsigned int x, unsigned int y);					// Metoda ustawiaj¹ca parametry x i y kursora
	void setLenght(unsigned int Dl);									// Metoda pozwalaj¹ca okreœliæ d³ugoœæ niebieskiego pola								
	void setText(std::string Text);										// Metoda ustawiaj¹ca wstêpny tekst
	void setTextColor(Colors text_color);								// Metoda ustawiaj¹ca kolor tekstu
	void setBackgroundColor(Colors back_color);							// Metoda ustawiaj¹ca kolor t³a								
																		
																		// Gettery:
	std::string getText();												// Getter zwracaj¹cy ca³y tekst
	int getPosition();													// Getter zwracaj¹cy pozycjê kursora
	int getBlueLength();												// Getter zwracaj¹cy dlugosc niebieskiego pola
	Colors getCols();													// Getter zwracaj¹cy ustawione kolory
	void userText();													// Metoda przyjmuj¹ca tekst wpisany przez u¿ytkownika

	void display();														// Metoda pracuj¹ca, ¿adnej pracy sie nie boi

	friend std::ostream& operator<<(std::ostream& o, const Edit& edit);		// Operator przesuniêcia bitowego przeci¹¿ony na wyœwietlanie zmiennych

private:																// Zmienne (pola):
	Colors Back_color;													// przechowuje informacje o kolorze t³a
	Colors Text_color;													// przechowuje informacje o kolorze tekstu
	COORD C;															// przechowuje informacje o pozycji kursora
	WORD Col;															// przechowuje informacje o obecnie ustawionych kolorach
	unsigned int lenght_of_field;										// przechowuje informacje o d³ugoœci niebieskiego pola
	std::string text;													// przechowuje tekst wejœciowy ustawiany za pomoc¹ metody setText i tekst wpisany przez uzytkownika
};

#endif