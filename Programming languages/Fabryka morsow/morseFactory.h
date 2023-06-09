//----------------------------------------------------------------------------------------------------------------------------------
// Klasa pochodna morseFactory. Klasa obsługująca obiekty
//
//
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
//----------------------------------------------------------------------------------------------------------------------------------

#ifndef morseFactory_h
#define morseFactory_h
#include "morse2.h"
#include "Bipanie.h"
#include "Dysk_tekst.h"
#include "MessBox.h"
#include "Konsola.h"
#include "Blink.h"

class morseFactory : public morse2
{
public:
	enum Exit {								// Enumerator przechowujący nazwy wyjść
		BEEP, 
		DISK,
		MESSBOX,
		BLINK,
		CONSOLE
	};

	void setExternalInfo(std::string Info);		// Przeciążona metoda virtualna setExternalInfo
	void setOutput(Exit output);				// Metoda ustawia jaki obiekt ma teraz pracować

												// Przeciążona metoda virtualna dla convert dla typów:
	void convert(std::string message);			// String
	void convert(int integer_number);			// Int
	void convert(double double_number);			// Double
	void convert(float float_number);			// Float

	morseFactory();								// Konstruktor 
	morseFactory(const morseFactory& Kop);		// Konstruktor kopiujący
	~morseFactory();							// Destruktor

protected: 
	morse2* abc;								// Wskaźnik na obiekt 
	Exit def;									// Pole typu Exit przechowujące dane wyjście
};

#endif 