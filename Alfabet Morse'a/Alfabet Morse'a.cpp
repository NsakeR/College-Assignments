#include "morse.h"
#include <iostream>
int main()
{
	morse m;

	m.setFrequency(400);	// czestotliwosc odtwarzania dzwieku
	m.setDotTime(70);		// czas kropki
	m.setDashTime(200);		// czas kreski
	m.setPause(50);			// pauza miedzy . a _ w trakcie morsowania
	m.setCharPause(1500);	// pauza po zakonczeniu odtwarzania dzwięku znaku

	m << "Ala ma kota";
	long i = 0x5A5A5A5A;
	double d = 1.23456789;
	system("pause");
	m << i << pause << d;  //pause jest manipulatorem

	std::cout << " po pauzie " << std::endl;
	system("pause");
	return 0;

}