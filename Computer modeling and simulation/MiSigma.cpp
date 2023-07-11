// MiSigma.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;


int main()
{
    double MI= 6, SIGMA = 5, THETA;
    double M_PI = 3.1415;
    double z;
    double tab[50];
    double u1, u2;
    double R,x;
    double rmax = RAND_MAX * 1.0;
    double d;
    int nk;
    fstream plik;
    plik.open("wyn.txt", ios::out);

    for (int i = 0; i < 2000; i++) {
        u1 = 1.0 * rand() / rmax;
        u2 = 1.0 * rand() / rmax;

        R = sqrt(2.0 * u1);
        THETA = 2.0 * M_PI * u2;
        z = R * cos(THETA);
        d = ((MI - 3 * SIGMA) - (MI - 3* SIGMA) )/ 25.0;
        
        
        x = z * SIGMA + MI;
        nk = int((x - (MI - 3.0 * SIGMA)) / d);
        tab[nk]++;
        plik << x << endl;
    }
    plik.close();
        
    return 0;
}

