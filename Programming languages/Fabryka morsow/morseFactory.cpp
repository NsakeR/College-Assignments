//----------------------------------------------------------------------------------------------------------------------------------
// Plik .cpp pochodnej klasy morseFactory. Definiuje zachowanie metod.
//
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
//----------------------------------------------------------------------------------------------------------------------------------

#include "morseFactory.h"

void morseFactory::setExternalInfo(std::string Info)
{
	abc->setExternalInfo(Info);
}

void morseFactory::setOutput(Exit output)
{
	if (output == BEEP) {
		abc = new Bipanie;
	}
	else if (output == DISK) {
		abc = new Dysk_tekst;
	}
	else if (output == MESSBOX) {
		abc = new MessBox;
	}
	else if (output == BLINK) {
		abc = new Blink;
	}
	else if (output == CONSOLE) {
		abc = new Konsola;
	}
}

void morseFactory::convert(std::string message) 
{
	abc->convert(message);
}

void morseFactory::convert(int integer_number) 
{
	abc->convert(integer_number);
}

void morseFactory::convert(double double_number) 
{
	abc->convert(double_number);
}

void morseFactory::convert(float float_number) 
{
	abc->convert(float_number);
}

morseFactory::morseFactory() : def(CONSOLE), abc(new Konsola)
{
}

morseFactory::morseFactory(const morseFactory& Kop) : def(Kop.def), abc(0)
{
}

morseFactory::~morseFactory()
{
	delete abc;
}
