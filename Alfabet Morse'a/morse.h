///------------------------------------------------------------------------------------------------------/
//Program przekszta�ca �a�cuchy znakowe na alfabet Morse'a odtwarzane na g�o�niku 
//
//Autor: Jakub Lefik
//Data utworzenia: 20.11.2020 r.
//Version: 1.0
///------------------------------------------------------------------------------------------------------ /

#ifndef MORSE_H
#define MORSE_H
#include <sstream>
#include <windows.h>

class morse
{
private:
	unsigned int frequency;
	unsigned int dotTime;
	unsigned int dashTime;
	unsigned int pausa;

public:
	unsigned int charPause;						//manipulator pause potrzebuje dost�pu

	morse();									//4 �elazne zasady wg. Prof. Kowalczyka
	morse(const morse& Kop);					//
	morse& operator=(const morse& Prz);			//
	~morse();									//-----------------------------------------------
												// Ustaw:
	void setFrequency(unsigned int x);			// czestotliwosc odtwarzania dzwieku
	void setDotTime(unsigned int y);			// czas kropki
	void setDashTime(unsigned int z);			// czas kreski
	void setPause(unsigned int w);				// pauza miedzy . a _ w trakcie morsowania
	void setCharPause(unsigned int c);			// pauza miedzy wyrazami
												//-----------------------------------------------	
												// Zwr��:
	unsigned int getFrequency();				// czestotliwosc odtwarzania dzwieku
	unsigned int getDotTime();					// czas kropki
	unsigned int getDashTime();					// czas kreski
	unsigned int getPause();					// pauz� miedzy . a _ w trakcie morsowania
	unsigned int getCharPause();				// pauz� miedzy wyrazami

	friend morse& operator <<(morse& ml, long l);				//Przeci��enie operatora << dla typu long
	friend morse& operator <<(morse& md, double d);				//Przeci��enie operatora << dla typu double
	friend morse& operator <<(morse& mt, std::string text);		//Przeci��enie operatora << dla podanego tekstu

	std::string translator(std::string abcd);                   //Metoda t�umacz�ca litery na kod Morse'a

	morse& operator<<(morse& (*mptr)(morse&));					//Przeci��enie operatora << na strumieniowanie manipulatora
};

morse& pause(morse& manip);										//zadeklarowany manupulator poza klasa 
#endif

