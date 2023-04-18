//----------------------------------------------------------------------------------------------------------------------------------
// Klasa bazowa morse2. Klasa zawiera deklaracje metod virtualnych.
//
//
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
//----------------------------------------------------------------------------------------------------------------------------------

#ifndef MORSE2_H
#define MORSE2_H
#include <sstream>			// Dla std::string i ¿eby u¿yæ to_string()
#include <iostream>			// Dla klas pochodnych coby nie za³¹czaæ co chwila

class morse2
{
protected:			
	std::string translate;								// String do którego zapisywana jest wiadomoœæ w kodzie Morse'a
	std::string externalInfo;							// String przechowuj¹cy ustawienia 
														
														// Metoda t³umacz¹ca na kod Morse'a dla typu:
	std::string translator_s(std::string abcd);			// String (litery)
	std::string translator_i(int integer_number);		// Int
	std::string translator_d(double double_number);		// Double 
	std::string translator_f(float float_number);		// Float

public:
	inline virtual void convert(std::string tekst) { translate = translator_s(tekst); }		// Zdefiniowana funkcja convert dla typu string
	inline virtual void convert(int i_number) { translate = translator_i(i_number); }		// Zdefiniowana funkcja convert dla typu int
	inline virtual void convert(double d_number) { translate = translator_d(d_number); }	// Zdefiniowana funkcja convert dla typu double
	inline virtual void convert(float f_number) { translate = translator_f(f_number); }		// Zdefiniowana funkcja convert dla typu float

	inline virtual void setExternalInfo(std::string informations) { externalInfo = informations; };	   // Zdefiniowana funkcja setExternalInfo 		
	
	std::string getTranslate() { return translate; };				// Getter dla pola translate
	std::string getExternalInfo() { return externalInfo; };			// Getter dla pola externalInfo

	morse2() : translate(""), externalInfo("") { };		// Kontruktor 
	virtual ~morse2() { };								// Virtualny destruktor
};

#endif


