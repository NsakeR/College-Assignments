// Poissona.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include <random>
#include <fstream>

using namespace std;

int main()
{
    int k1[2000]{0}, k2[2000]{0}, k[2000]{0};
    double lambda1 = 10, lambda2 = 1.8;
    double y;
    double S = 0.0;
    int l = -1;
    double q = exp(-1.0 * lambda2);
    int x = -1;

    fstream plik;
    plik.open("wyn.txt", ios::out);
    for (int g = 0; g < 2000; g++) {
        l = -1;
        while (S <= lambda1) {
            y = 1.0 * rand() / RAND_MAX * 1.0;
            S += y;
            
            l++;
        }
        k1[g] = l;

        S = 1.0;
        x = -1;
        while (S > q) {
            y = 1.0 * rand() / RAND_MAX * 1.0;
            S *= y;
            x++;
        }
        k2[g] = x;
        k[g] = k1[g] + k2[g];
        plik << k[g] << endl;
    }

    double sredniak1 = 0.0, sredniak2 = 0.0;
    double wariancjak1, wariancjak2, wariancjak;
    double srKwa1 = 0.0, srKwa2 = 0.0, srK = 0.0;
    double srk =0.0;

    for (int i = 0; i < 2000; i++) {
        sredniak1 += k1[i];
        sredniak2 += k2[i];
        
        srKwa1 += pow(k1[i], 2);
        srKwa2 += pow(k2[i], 2);

        srk += k[i];
        srK += pow(k[i], 2);
    }
    srk = srk / 2000;
    srK = srK / 2000;

    sredniak1 = sredniak1 / 2000;
    sredniak2 = sredniak2 / 2000;

    srKwa1 = srKwa1 / 2000;
    srKwa2 = srKwa2 / 2000;
   

    wariancjak1 = srKwa1 -pow(sredniak1, 2);
    wariancjak2 = srKwa2 -pow(sredniak2, 2);
    wariancjak  = srK -pow(srk, 2);

    cout << "Lambda1: " << lambda1 << " Srednia: " << sredniak1 << " Wariancja:" << wariancjak1 << endl;
    cout << "Lambda2: " << lambda2 << " Srednia: " << sredniak2 << " Wariancja:" << wariancjak2 << endl;
    cout << " Srednia k : " << srk << " Wariancja:" << wariancjak << endl;
    plik.close();
    return 0;
}

