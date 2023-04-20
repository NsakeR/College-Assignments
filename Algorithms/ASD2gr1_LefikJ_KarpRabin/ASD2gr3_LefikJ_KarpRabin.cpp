///////////////////////////////////////////////////////////////////////////////////////////////////
//  
//  Program realizuje wyszukiwanie pozycji łańcucha znakowego w tekście algorytmem Karpa-Rabina
//   
//  Autor: Jakub Lefik  Wersja: 1.0
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

void KarpRabin(std::string nazwa_pliku) {
    std::ifstream file;
    file.open(nazwa_pliku);

    int base = 256;
    long primeNumber = 151;
    std::string searchedFor;
    std::vector<char> seek;
    std::vector<char> data;
    std::vector<long long> H;
    std::cin >> searchedFor;

    // Przepisanie ze stringa do vectora

    for (size_t i = 0; i < searchedFor.length(); i++) {
        seek.push_back(searchedFor[i]);
    }

    // Znajdź jakiego hasha szukamy

    int k1 = seek[0];
    for (size_t i = 0; i < seek.size() - 1; i++) {
        int temp = (k1 * base + (int)seek[i + 1]) % primeNumber;
        k1 = temp;
    }

    long N = seek.size();

    // Wczytaj z pliku

    while (!file.eof()) {
        char g;
        file.get(g);
        data.push_back(g);
    }
    file.close();

    // Zbuduj pierwszy ciąg 4 znakowy 

    int t1 = (int)data[0];
    for (int i = 1; i < N; i++) {
        int temp = (t1 * base + (int)data[i]) % primeNumber;
        t1 = temp;
    }

    H.push_back(t1);

    // Wywal pierwszy element i wstaw (pierwszy + dlugość poszukiwanego wzorca)

    for (size_t i = 0; i < data.size() - N; i++) {
        int tamp = ((H[i] - (long long)data[i] * (long long(powl((long)256, N - (long)1)))) * 256 + (long)data[N + i]) % primeNumber;
        if (tamp < 0) {
            tamp += primeNumber;
        }
        H.push_back(tamp);
        if (k1 == H[i]) {
            std::cout << i  << " ";
        }
    }
};

int main()
{
    int testCases;
    std::cin >> testCases;

    for (int pog = 0; pog < testCases; pog++) {
        std::cout << "pog";
        std::string filename ;
        std::cin >> filename;
        KarpRabin(filename);
    }

    return 0;
}
