/*******************************************************************************************************************/
//Program realzuje proste operacje na macierzy 2x2
//
//Autor: Jakub Lefik
//Data utworzenia : 5.11.2020
//Wersja 1.0
/*******************************************************************************************************************/

#ifndef MACIERZ_H
#define MACIERZ_H
#include <iostream>

class macierz
{
protected:
	int row;
	int col;
	double** Mac;

public:
	macierz();												//konstruktor domy�lny
	macierz(const macierz& kop);							//konstruktor kopiuj�cy
	
	macierz& operator= (const macierz& r1);					//przeci��enie operatora = 
	macierz operator*(const macierz& Mn);					//przeci��enie operatora * do mno�enia macierzy
	macierz operator*(const double Li);						//przeci��enie operatora * do mno�enia macierzy przez liczbe
	const macierz operator+(const macierz& Dod);			//przeci��enie operatora +
	const macierz operator-(const macierz& Od);				//przeci��enie operatora -
	bool operator==(const macierz& Por);					//przeci��enie operatora logicznego ==

	int getRow();											//metoda zwracajaca wiersze
	int getCol();											//metoda zwracaj�ca kolumny
	double getWart(int x, int y);							//metoda zwracaj�ca liczby pod podanymi indeksami
	void set(int x, int y, double value);					//metoda ustawiajaca wartosci
	void transp();											//metoda transpozycja macierzy
	double det();											//metoda licz�ca wyznacznik macierzy

	
	friend std::ostream& operator <<(std::ostream& so, const macierz& dt);  //przeci��enie operatora wyj�cia 

	~macierz();												//destruktor

};

#endif 