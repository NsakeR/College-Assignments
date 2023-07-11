#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    double d, f;
    double rmax = RAND_MAX * 1.0;
    double tabX[2000];
    double tabY[2000];
    double tabZ[2000];

    fstream plik;
    plik.open("wyniki.txt", ios::out);
    /*for (int i = 0; i < 1000; i++) {
        d = 1.0 * rand() / rmax;
        cout << d << endl;
        if (d <= 0.5 && d >= 0.0) {
            tabX[i] = sqrt(2.0 * d);
        }
        else if (d < 1.0 && d > 0.5) {
            tabX[i] = 2.0 - sqrt(2.0 * (1.0 - d));
        }

        plik << tabX[i] << endl;
    }*/

    for (int i = 0; i < 1000; i++) {
        d = 1.0 * (rand() /rmax) * 2.0;
       
        f = 1.0 * (rand() / rmax );
        cout << "D = " << d << "F = " << f << endl;

        if (d <= 0.5 && d >= 0.0) {
            if (f <= d) {
                tabZ[i] = d;
            }
        }
        else if (d < 1.0 && d > 0.5) {
            if (f <= 2.0 - d) {
                tabZ[i] = d;
            }
        }

        plik << tabZ[i] << endl;
    }

    plik.close();
    return 0;
}
