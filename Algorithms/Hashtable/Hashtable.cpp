// Tablica hashowana 
// Autor: Jakub Lefik  Wersja: 1.0
// Data utworzenia: 29.03.2021
// Tablica wpisuje po (kluczach % rozmiar tablicy) pod odpowiednie indeksy łańcuchy znakowe typu string :)

#include <iostream>
#include <string>

void podmien(long Tab1[], std::string Tab2[], int a, int b) {
	Tab1[a] = Tab1[b];
	Tab2[a] = Tab2[b];

	Tab1[b] = 0;
	Tab2[b] = "";
}

int main()
{
	int testCases = 0;
	std::string abc = "";
	int sizeOfTab = 0;
	int addedNumber = 0;

	long* Tab = nullptr;
	std::string* Tab_str = nullptr;

	std::cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		do {
			std::cin >> abc;
			if (abc == "size") {
				std::cin >> sizeOfTab;                  // Wczytaj rozmiar tablicy i zadeklaruj miejsce tablic    
				Tab = new long[sizeOfTab];
				Tab_str = new std::string[sizeOfTab];
				for (int i = 0; i < sizeOfTab; i++) {   // Wyzeruj tablice 
					Tab[i] = 0;
					Tab_str[i] = "";
				}
			}
			else if (abc == "add") {
				std::cin >> abc;
				addedNumber = std::stoi(abc);

				int pos = addedNumber % sizeOfTab;
				if (Tab && Tab_str) {
					if (Tab[pos] == 0) {
						Tab[pos] = addedNumber;
						std::cin >> Tab_str[pos];
					}
					else {
						for (int i = pos + 1; i <= sizeOfTab; i++) {
							if (i == sizeOfTab) {
								i = 0;
							}
							if (Tab[i] == 0) {
								Tab[i] = addedNumber;
								std::cin >> Tab_str[i];
								break;
							}
						}
					}
				}

			}
			else if (abc == "print") {
				for (int i = 0; i < sizeOfTab; i++) {
					if (Tab[i] != 0) {
						std::cout << i << " " << Tab[i] << " " << Tab_str[i] << std::endl;
					}
				}
			}

			else if (abc == "delete") {
				std::cin >> abc;
				addedNumber = std::stoi(abc);
				for (int i = 0; i < sizeOfTab; i++) {       // Przeszukaj tablice w poszukiwaniu klucza, usuń go
					if (Tab[i] == addedNumber) {
						Tab[i] = 0;
						Tab_str[i] = "";
					}
				}
				// Spaghetti, ale działa xD
				for (int i = 0; i < sizeOfTab; i++) {       // Przeszukaj tablice 
					if (i != Tab[i] % sizeOfTab) {           // Jeżeli wynik klucz % 10, jest różny od poprawnego indeksu 
						int cba = Tab[i] % sizeOfTab;
						if (Tab[cba] == 0) {                // ^to sprawdź czy poprawny indeks jest wolny, if == true to przepisz tam wartości i wyzeruj wartości niepoprawnych indeksów
							podmien(Tab, Tab_str, cba, i);
						}
						else {                                              // Jeżeli nie jest wolny
							for (int j = cba; j <= sizeOfTab; j++) {         // To znajdź inny  wolny indeks najbliższy poprawnego
								if (j == sizeOfTab) { j = 0; }
								if (Tab[j] == 0) {
									podmien(Tab, Tab_str, j, i);
									break;
								}
							}
						}
					}
				}
			}

		} while (abc != "stop");

		if (Tab && Tab_str) {
			delete[] Tab;
			delete[] Tab_str;
		}
	}
	return 0;
}