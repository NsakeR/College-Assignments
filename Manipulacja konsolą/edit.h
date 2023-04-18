/*******************************************************************************************************************/
// Header klasy odpowiadaj�cej za manipulacje tekstem w konsoli  
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
	enum Colors {														// Enumerator przechowuj�cy nazwy kolor�w 
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
	Edit(const Edit & Kop);												// Konstruktor kopiuj�cy
	Edit operator=(const Edit& Row);									// Przeci��ony operator przypisania
	~Edit();															// Destruktor 
	
																		// Settery:
	void setPosition(unsigned int x, unsigned int y);					// Metoda ustawiaj�ca parametry x i y kursora
	void setLenght(unsigned int Dl);									// Metoda pozwalaj�ca okre�li� d�ugo�� niebieskiego pola								
	void setText(std::string Text);										// Metoda ustawiaj�ca wst�pny tekst
	void setTextColor(Colors text_color);								// Metoda ustawiaj�ca kolor tekstu
	void setBackgroundColor(Colors back_color);							// Metoda ustawiaj�ca kolor t�a								
																		
																		// Gettery:
	std::string getText();												// Getter zwracaj�cy ca�y tekst
	int getPosition();													// Getter zwracaj�cy pozycj� kursora
	int getBlueLength();												// Getter zwracaj�cy dlugosc niebieskiego pola
	Colors getCols();													// Getter zwracaj�cy ustawione kolory
	void userText();													// Metoda przyjmuj�ca tekst wpisany przez u�ytkownika

	void display();														// Metoda pracuj�ca, �adnej pracy sie nie boi

	friend std::ostream& operator<<(std::ostream& o, const Edit& edit);		// Operator przesuni�cia bitowego przeci��ony na wy�wietlanie zmiennych

private:																// Zmienne (pola):
	Colors Back_color;													// przechowuje informacje o kolorze t�a
	Colors Text_color;													// przechowuje informacje o kolorze tekstu
	COORD C;															// przechowuje informacje o pozycji kursora
	WORD Col;															// przechowuje informacje o obecnie ustawionych kolorach
	unsigned int lenght_of_field;										// przechowuje informacje o d�ugo�ci niebieskiego pola
	std::string text;													// przechowuje tekst wej�ciowy ustawiany za pomoc� metody setText i tekst wpisany przez uzytkownika
};

#endif