#include <iostream>
#include <cmath>
#include <random>
#include <fstream>

using namespace std;

int main()
{
    double D;
    double rmax = 1.0 * RAND_MAX;
    int tabX[4] = { 2,   6,   8,   12 };
    double P[4] = { 0.2, 0.5, 0.2, 0.1 };
    int tabWyn[4]{ 0 };
    int tabWyn2[4]{ 0 };
    int tabWyn3[4]{ 0 };
    fstream plik;
    plik.open("wyniki.txt", ios::out);
    
    for (int i = 0; i < 2000; i++) {
        D = 1.0 * rand() / rmax;
        if (D <= 0.2) {
            tabWyn[0]++;
        } else if (D > 0.2 && D <= 0.7) {
            tabWyn[1]++;
        }
        else if (D > 0.7 && D <= 0.9) {
            tabWyn[2]++;
        }
        else if (D > 0.9 && D <= 1.0) {
            tabWyn[3]++;
        }
    }
    cout << "Liczby" << endl;

    for (int i = 0; i < 4; i++) {
        cout << tabX[i] << " ";
    }
    cout << endl;
    cout << "Prawdopodobienstwa" << endl;
    for (int i = 0; i < 4; i++) {
        cout << P[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "Metoda odwroconej dystrybuanty " << endl;
    for (int i = 0; i < 4; i++) {
        cout << tabWyn[i] << endl;
    }

    

    // METODA ELIMINACJI
    int j;
    double r;
    cout << endl;
    cout << "Metoda eliminacji " << endl;
    for (int i = 0; i < 20000; i++) {
        r = 1.0 * rand() / rmax;
        j = rand() % 4;

        if (r <= P[j]) {
            tabWyn2[j]++;
        }
        
        if (tabWyn2[0] + tabWyn2[1] + tabWyn2[2] + tabWyn2[3] >= 2000) {
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << tabWyn2[i] << endl;
    }

    plik.close();

    // METODA Z BIBLIOTEKI
    std::default_random_engine generator;
    std::discrete_distribution<> d({ 20, 50, 20, 10 });
    cout << endl;
    cout << endl;
    cout << "Biblioteka " << endl;
    for (int i = 0; i < 2000; i++)
    {
        r = d(generator);
        if (r == 0)
            tabWyn3[0]++;
        if (r == 1)
            tabWyn3[1]++;
        if (r == 2)
            tabWyn3[2]++;
        if (r == 3)
            tabWyn3[3]++;
    }
    for (int i = 0; i < 4; i++) {
       cout << tabWyn3[i] << endl;
    }
    return 0;
}

