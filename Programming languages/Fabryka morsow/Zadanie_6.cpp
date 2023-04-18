//---------------------------------------------------------------------------------------------------------------------------------
// Main projektu abstrakcyjnej fabryki
// BEEP: Wyjscie glosnikowe (jak nic nie słychać proszę podłączyć słuchawki ;) )
// DISK: Zapis informacji na dysk do pliku (w tym przypadku tekstowego)
// MESSBOX: Wyskakujące okienko
// BLINK: Zmiana tła pod kolejnymi znakami Morse'a
// CONSOLE: Wyrzucenie tekstu na konsolę
// 
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
// 
//---------------------------------------------------------------------------------------------------------------------------------

#include "morseFactory.h" //--- includujemy jedną klasę 

  int main() {

	morseFactory f;

	f.setOutput(morseFactory::BEEP);
	f.setExternalInfo("400 500 200 50 600");		// Wysokość dźwięku, Długość - , Długość . , Czas przerwy między znakami, Czas spacji
	f.convert("Bułka z masłem Litwo Ojczyzno moja. ty jesteś jak zdrowie");

	f.setOutput(morseFactory::DISK);
	f.setExternalInfo("plikzapisowy_dysk.txt");
	f.convert("A kot ma");
	f.convert(123);
	f.convert(1.23);

	f.setOutput(morseFactory::MESSBOX);
	f.convert("A ten kot ma 4 łapki");

	f.setOutput(morseFactory::BLINK);
	f.convert("Ala ma kota");

	f.setOutput(morseFactory::CONSOLE);
	f.convert("Ala ma kota");

  return 0;
}

