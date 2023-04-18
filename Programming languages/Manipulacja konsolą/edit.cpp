/*******************************************************************************************************************/
// Plik wykonawczy klasy odpowiadaj¹cej za manipulacje tekstem w konsoli  
//
// Autor: Jakub Lefik
// Data utworzenia : 4.12.2020						 Wersja 1.0
// 
// Zmiany:
//
/*******************************************************************************************************************/

#include "edit.h"

Edit::Edit()
{
	text = "";
	C.X = 0;
	C.Y = 0;
	lenght_of_field = 0;
}

Edit::Edit(const Edit& Kop)
{
	text = Kop.text;
	C.X = Kop.C.X;
	C.Y = Kop.C.Y;
	lenght_of_field = Kop.lenght_of_field;
}

Edit Edit::operator=(const Edit& Row)
{
	if (this == &Row) return *this;
	else {
		this->text = Row.text;
		this->C.X = Row.C.X;
		this->C.Y = Row.C.Y;
		this->lenght_of_field = Row.lenght_of_field;
	}
	return *this;
}

Edit::~Edit()
{
}

//---------------------------------------------Settery---------------------------------------------

void Edit::setPosition(unsigned int x, unsigned int y)
{
	C.X = x;
	C.Y = y - 1;
}

void Edit::setLenght(unsigned int Dl)
{
	lenght_of_field = Dl;
}

void Edit::setText(std::string Text)
{	
	text = Text;
}

void Edit::setTextColor(Colors text_color)
{
	Text_color = text_color;
}

void Edit::setBackgroundColor(Colors back_color)
{
	Back_color = back_color;
}
//---------------------------------------------Gettery---------------------------------------------

std::string Edit::getText()
{
	return text;
}

int Edit::getPosition()
{
	return C.X, C.Y;
}

int Edit::getBlueLength() {
	return lenght_of_field;
}

Edit::Colors Edit::getCols()
{
	return Back_color, Text_color;
}

void Edit::userText()
{
	char abc;
	while (abc = _getch())
	{
		if (abc == 13)									// jesli wykryje enter -> break
			break;										
														// Pozwala wpisywaæ tylko: 
		if (abc >= 65 && abc <= 90) {					// du¿e znaki (z tablicy ASCII)
			text += abc;
		}	
		else if (abc >= 48 && abc <= 57) {				// cyfry	  
			text += abc;
		}
		else if (abc >= 97 && abc <= 122) {				// male znaki
			text += abc;								// Oznacza to tak¿e, ¿e polskie i obce znaki specjalne zosta³y "wy³¹czone" :)
		}
		else if (abc == 32) { 
			text += " ";
		}

		display();
	}
}

void Edit::display()
{	
	Col = ((Back_color) << 4) + (Text_color);							// ustawianie koloru

	int length = text.length();
	int len = lenght_of_field;
																		// funkcje wbudowane w nag³ówek Windows.h
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), C);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Col);		

	std::string abcd = "";
	int B = 0;

	if (length - len > 0) {
		B = length - len;
	}

	for (int i = B; i < length; i++) {									
		abcd += text[i];												// przypisywanie tekstu Ala + wpisanego przez u¿ytkownika
	}

	if (length - len < 0) {
		for (int i = 0; i < len - length; i++) {
			abcd += " ";												// Dope³nianie do (lenght_of_field) niebieskich pól
		}
	}
	std::cout << abcd;

	int t1 = abcd.length();

	COORD temp;
	temp.Y = C.Y;
	temp.X = C.X + t1 - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), temp);
}



std::ostream& operator<<(std::ostream& wyj, const Edit& E) {
	wyj << E.C.X << E.C.Y << E.lenght_of_field << E.Back_color << E.Text_color << E.text;
	return wyj;
}