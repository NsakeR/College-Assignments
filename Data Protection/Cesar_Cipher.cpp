//////////////////////////////////////////////////////////
//
//  Autor: Jakub Lefik
//  Wersja: 1.0 
//  Desc: Zrobiony program który szyfruje i rozszyfrowuje szyfr cezara  15.03.2022
// 
//  Wersja: 1.1
//  Desc: Dodano automatyczne rozpoznawanie klucza  16.03.2022
//
//////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

char cezar(char m, char k)
{
	char c = NULL;
	if (k >= 97 && k <= 122)
	{
		k -= 97;
	}
	else if (k >= 65 && k <= 90)
	{
		k -= 65;
	}
	else { std::cout << "Key is not a LETTER!!" << std::endl; }

	if (m >= 97 && m <= 122)
	{
		m -= 97;
		c = (m + k) % 26;
	}
	else if (m >= 65 && m <= 90)
	{
		m -= 65;
		c = (m + k) % 26;
	}
	else if (m <= 0 || m > 25)
	{
		return -1;
	}
	c += 65;
	return c;
}

char decipher (char m, char k)
{
    char c = NULL;
    if (k >= 97 && k <= 122)
    {
        k -= 97;
    }
    else if (k >= 65 && k <= 90)
    {
        k -= 65;
    }
    else { std::cout << "Key is not a LETTER!!" << std::endl; }

        if (m >= 97 && m <= 122)
        {
            m -= 97;
            if (m - k < 0) {
                c = (m + 26 - k) % 26;
            }
            else { c = (m - k) % 26; }
        }
        else if (m >= 65 && m <= 90)
        {
            m -= 65;
            if (m - k < 0) {
                c = (m + 26 - k) % 26;
            }
            else { c = (m - k) % 26; }
        }
         else if (m <= 0 || m > 25)
         {
             return -1;
         }
        c += 97;
    
    return c;
}

std::string deszyfr(std::string m, char k)
{
	char c = NULL;
    std::string temp;
	if (k >= 97 && k <= 122)
	{
		k -= 97;
	}
	else if (k >= 65 && k <= 90)
	{
		k -= 65;
	}
	else { std::cout << "Key is not a LETTER!!" << std::endl; }

    for (size_t i = 0; i < m.length(); i++) {
        if (m[i] >= 97 && m[i] <= 122)
        {
            m[i] -= 97;
            if (m[i] - k < 0) {
                c = (m[i] + 26 - k) % 26;
            }
            else { c = (m[i] - k) % 26; }
        }
        else if (m[i] >= 65 && m[i] <= 90)
        {
            m[i] -= 65;
            if (m[i] - k < 0) {
                c = (m[i] + 26 - k) % 26;
            }
            else { c = (m[i] - k) % 26; }
        }
       /* else if (m[i] <= 0 || m[i] > 25)
        {
            return "";
        }*/
        c += 97;
        temp += c;
    }
	return temp;
}

double chi_sq(std::string x) {
    int c[26]{ 0 };
    char* m = new char [x.length()];
    
    for (size_t z = 0; z < x.length(); z++) {
        m[z] = x[z];
    }

    int i = 0, t = 0;
    double e[26], f[26] = { 0.08087, 0.01493, 0.02781, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04094, 0.02587, 0.06749, 0.07507, 0.01929, 0.00096, 0.05987, 0.06234, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074 };
    double mr = 0;

    while (m[i] != '\0' && i < x.length()) {
        switch (m[i]) {
        case 'A':
        case 'a':
            c[0]++;
            break;
        case 'B':
        case 'b':
            c[1]++;
            break;
        case 'C':
        case 'c':
            c[2]++;
            break;
        case 'D':
        case 'd':
            c[3]++;
            break;
        case 'E':
        case 'e':
            c[4]++;
            break;
        case 'F':
        case 'f':
            c[5]++;
            break;
        case 'G':
        case 'g':
            c[6]++;
            break;
        case 'H':
        case 'h':
            c[7]++;
            break;
        case 'I':
        case 'i':
            c[8]++;
            break;
        case 'J':
        case 'j':
            c[9]++;
            break;
        case 'K':
        case 'k':
            c[10]++;
            break;
        case 'L':
        case 'l':
            c[11]++;
            break;
        case 'M':
        case 'm':
            c[12]++;
            break;
        case 'N':
        case 'n':
            c[13]++;
            break;
        case 'O':
        case 'o':
            c[14]++;
            break;
        case 'P':
        case 'p':
            c[15]++;
            break;
        case 'Q':
        case 'q':
            c[16]++;
            break;
        case 'R':
        case 'r':
            c[17]++;
            break;
        case 'S':
        case 's':
            c[18]++;
            break;
        case 'T':
        case 't':
            c[19]++;
            break;
        case 'U':
        case 'u':
            c[20]++;
            break;
        case 'V':
        case 'v':
            c[21]++;
            break;
        case 'W':
        case 'w':
            c[22]++;
            break;
        case 'X':
        case 'x':
            c[23]++;
            break;
        case 'Y':
        case 'y':
            c[24]++;
            break;
        case 'Z':
        case 'z':
            c[25]++;
            break;
        default:
            ;
        }
        i++;
    }

    for (int j = 0; j < 26; j++) {
        t += c[j];
    }
   
    for (i = 0; i < 26; i++) {
        e[i] = t * f[i];
    }

    for (i = 0; i < 26; i++) {
        mr += ((c[i] - e[i]) * (c[i] - e[i])) / t;
    }

    return mr;
}

char automatic_codeLetter(double tabChi[30]) {
    char key;
    double t = tabChi[0];
    for (int i = 0; i < 26; i++) {
        if (t > tabChi[i]) {
            t = tabChi[i];
            key = i;
        }
    }

    return key + 65;
}
int main()
{
	std::cout << "Witam w szyfrowaniu Cezara" << std::endl << "Wybierz opcje \n";
	std::cout << "1. Zakoduj tekst Ala ma kota a kot ma Ole" << std::endl;
	std::cout << "2. Podaj tekst z klawiatury" << std::endl;
	std::cout << "3. Podaj nazwe pliku tekstowego" << std::endl;
	
	
	std::string fileName;
	std::fstream plik;
	std::string message;
	int x = 0;
	std::cin >> x;
	int i = 0;
	switch (x) {
		case 1:
			message = "Ala ma kota a kot ma Ole";
			break;

		case 2:
			std::cout << "Podaj wiadomosc \n";
			std::cin.ignore();
			getline(std::cin, message);
			std::cout << std::endl;
			break;

		case 3:
			std::cin >> fileName;
			plik.open(fileName, std::ios::in);
            if (plik.good() == false) {
                std::cout << "Plik nie zostal otwarty" << std::endl;
                return -1;
            }
			getline(plik, message);
			plik.close();
			break;

		default: 
			message = "Ala ma kota a kot ma Ole";
			break;
	}
    std::cout << std::endl;
    if (x != 1) {
        std::cout << "Mamy wiadomosc, co chcesz z nia zrobic" << std::endl << "Wybierz opcje \n";
        std::cout << "1. Zakoduj tekst " << std::endl;
        std::cout << "2. Odkoduj tekst " << std::endl;
        std::cout << "3. Znajdz klucz" << std::endl;
        std::cin >> x;
    }
        char key = 'h';
        double chi2[30];
        char a;
        
        switch (x) {
        case 1:
            std::cout << "Podaj klucz do kodowania: ";
            std::cin >> key;
            i = 0;
            while (message[i] != '\0' && i < 2500)
            {
                message[i] = cezar(message[i], key);
                i++;
            }
            i = 0;
            std::cout << " Zaszyfrowana wiadomosc: ";
            while (message[i] != '\0' && i < 2500)
            {
                std::cout << message[i];
                i++;
            }
            std::cout << std::endl;
            break;
        case 2:
            i = 0;
            for (key = 'A'; key <= 'Z'; key++) {
                chi2[i] = chi_sq(deszyfr(message, key));
                i++;
            }
            key = automatic_codeLetter(chi2);
            std::cout << "Litera kodujaca to: " << key << std::endl;
            i = 0;
            std::cout << " Odszyfrowana wiadomosc: ";
            while (message[i] != '\0' && i < 2500)
            {
                message[i] = decipher(message[i], key);
                i++;
            }
            i = 0;
            while (message[i] != '\0' && i < 2500)
            {
                std::cout << message[i];
                i++;
            }
            std::cout << std::endl;
            break;

        case 3:
            i = 0;
            for (int u = 0; u < 30; u++) {
                chi2[u] = 0;
            };
            for (key = 'A'; key <= 'Z'; key++) {
                chi2[i] = chi_sq(deszyfr(message, key));
                printf("%c\t%.2f\n", key, chi2[i]);
                i++;
            }
            a = automatic_codeLetter(chi2);
            std::cout << "Twoja litera kodujaca to: " << a << std::endl;
            break;

        default:
            std::cout << "Nic nie podauues \n";
            break;
        }
	return 0;
}
