/*******************************************************************************************************************/
// Plik definiuj¹cy zachowanie manipulatorów kolorów
//
// Autor: Jakub Lefik
// Data utworzenia : 4.12.2020			Wersja 1.0
// 
// Zmiany:
//
/*******************************************************************************************************************/

#include "ccolor.h"

std::ostream& defcolor(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return manip;
}

std::ostream& black(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
	return manip;
}

std::ostream& blue(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	return manip;
}

std::ostream& green(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	return manip;
}

std::ostream& aqua(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	return manip;
}

std::ostream& red(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	return manip;
}

std::ostream& purple(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	return manip;
}

std::ostream& yellow(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	return manip;
}

std::ostream& white(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	return manip;
}

std::ostream& gray(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	return manip;
}

std::ostream& light_blue(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	return manip;
}

std::ostream& light_green(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	return manip;
}

std::ostream& light_aqua(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	return manip;
}

std::ostream& light_red(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	return manip;
}

std::ostream& light_purple(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	return manip;
}

std::ostream& light_yellow(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	return manip;
}

std::ostream& bright_white(std::ostream& manip)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	return manip;
}

std::string SetColor(WORD color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	return "";
};
