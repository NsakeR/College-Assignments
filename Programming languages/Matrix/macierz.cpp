#include "macierz.h"

macierz::macierz() : row(2), col(2)
{
	Mac = new double* [row];
	for (int i = 0; i < row; i++) {
		Mac[i] = new double[col];

		for (int j = 0; j < col; j++)
			Mac[i][j] = 0.0;
	}
}


macierz::macierz(const macierz& kop) : row(kop.row), col(kop.col)
{
	Mac = new double* [row];
	for (int i = 0; i < row; i++) {
		Mac[i] = new double[col];

		for (int j = 0; j < col; j++)
			Mac[i][j] = kop.Mac[i][j];
	}
}



 macierz& macierz::operator=(const macierz& r1)
{
	for (int g = 0; g < row; g++) {
		for (int j = 0; j < col; j++) {
			this->Mac[g][j] = r1.Mac[g][j];
		}
	}
	return *this;
}

macierz macierz::operator*(const macierz& Mn)
{
	macierz temp;
	if (row == Mn.col) {
		temp.Mac[0][0] = Mn.Mac[0][0] * this->Mac[0][0] + Mn.Mac[0][1] * this->Mac[1][0];
		temp.Mac[0][1] = Mn.Mac[0][0] * this->Mac[0][1] + Mn.Mac[0][1] * this->Mac[1][1];
		temp.Mac[1][0] = Mn.Mac[1][0] * this->Mac[0][0] + Mn.Mac[1][1] * this->Mac[1][0];
		temp.Mac[1][1] = Mn.Mac[1][0] * this->Mac[0][1] + Mn.Mac[1][1] * this->Mac[1][1];
	}

	return temp;
}

macierz macierz::operator*(const double Liczba)
{

	for (int g = 0; g < row; g++) {
		for (int j = 0; j < col; j++) {
			this->Mac[g][j] = Mac[g][j] * Liczba;
		}
	}
	return *this;
}

const macierz macierz::operator+(const macierz& Dod)
{
	macierz temp;
	if (row == Dod.row && col == Dod.col) {

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				temp.Mac[i][j] = Mac[i][j] + Dod.Mac[i][j];
			}
		}
	}
	return temp;
}

const macierz macierz::operator-(const macierz& Od)
{
	macierz temp;
	if (row == Od.row && col == Od.col) {

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				temp.Mac[i][j] = Mac[i][j] - Od.Mac[i][j];
			}
		}
	}
	return temp;
}

int macierz::getRow()
{
	return row;
}

int macierz::getCol()
{
	return col;
}

double macierz::getWart(int x, int y)
{
	if (x < row && y < col && row >= 0 && col >= 0) {
		return Mac[x][y];
	}
	else { return 0; }
}

void macierz::set(int rz, int kol, double value)
{		if(rz < row && kol < col)
		this->Mac[rz][kol] = value;
}

void macierz::transp()
{
	macierz temp;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			temp.Mac[i][j] = Mac[j][i];
		}
	}
}

double macierz::det()
{
	if (row == col) {
		return Mac[0][0] * Mac[1][1] - Mac[0][1] * Mac[1][0];
	}
	else { return 0; }
}

bool macierz::operator==(const macierz& Por)
{
	if (row == Por.row && col == Por.col) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				Mac[i][j] == Por.Mac[i][j];
			}
		}
		return true;
	}
	else { return false; }
}

std::ostream& operator<<(std::ostream& so, const macierz& dt)
{

	for (int i = 0; i < dt.row; i++) {
		for (int j = 0; j < dt.col; j++) {
			so << dt.Mac[i][j] << " ";
		}
		so << std::endl;
	}
	
	return so;
}

macierz::~macierz()
{
	for (int i = 0; i < row; i++)
		delete[] Mac[i];

	delete[] Mac;
}