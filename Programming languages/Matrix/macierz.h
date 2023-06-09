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
	macierz();												//konstruktor domyślny
	macierz(const macierz& kop);							//konstruktor kopiujący
	
	macierz& operator= (const macierz& r1);					//przeciążenie operatora = 
	macierz operator*(const macierz& Mn);					//przeciążenie operatora * do mnożenia macierzy
	macierz operator*(const double Li);						//przeciążenie operatora * do mnożenia macierzy przez liczbe
	const macierz operator+(const macierz& Dod);			//przeciążenie operatora +
	const macierz operator-(const macierz& Od);				//przeciążenie operatora -
	bool operator==(const macierz& Por);					//przeciążenie operatora logicznego ==

	int getRow();											//metoda zwracajaca wiersze
	int getCol();											//metoda zwracająca kolumny
	double getWart(int x, int y);							//metoda zwracająca liczby pod podanymi indeksami
	void set(int x, int y, double value);					//metoda ustawiajaca wartosci
	void transp();											//metoda transpozycja macierzy
	double det();											//metoda licząca wyznacznik macierzy

	
	friend std::ostream& operator <<(std::ostream& so, const macierz& dt);  //przeciążenie operatora wyjścia 

	~macierz();												//destruktor

};

#endif 