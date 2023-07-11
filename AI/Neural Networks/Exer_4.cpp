#include <iostream>
#include <cmath>
using namespace std;
const double beta = 0.4;
const double ni = 0.9;
double f(double s)
{
    return 1 / (1 + exp(-beta * s));
}
void show(double tab[], double w[2][13])
{
    double s1 = 0;
    double s2 = 0;
    for (int i = 0; i < 13; i++)
    {
        s1 = s1 + tab[i] * w[0][i];
        s2 = s2 + tab[i] * w[1][i];
    }
    cout << "s1: =" << f(s1) << " s2: " << f(s2) << endl;
}
int main()
{

    double w[2][13] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    double tab1[13] = {1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1};
    double tab4[13] = {1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1};
    double tab7[13] = {1, 1, 1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1};
    double tab2[13] = {1, 1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1};
    double d1[2] = {1, 1}, d4[2] = {1, 0}, d7[2]{0, 0}, d2[2]{0, 1};

    double E, s1, s2, y1, y2;
    double e4, e7, e2;
    int iter = 0;

    do
    {
        E = 0;
        e4 = 0;
        e7 = 0;
        s1 = 0;
        s2 = 0;
        for (int i = 0; i < 13; i++)
        {
            s1 = s1 + tab1[i] * w[0][i];
            s2 = s2 + tab1[i] * w[1][i];
        }
        y1 = f(s1);
        y2 = f(s2);
        for (int i = 0; i < 13; i++)
        {
            w[0][i] = w[0][i] + ni * (d1[0] - y1) * beta * (1 - y1) * y1 *
                                    tab1[i];
            w[1][i] = w[1][i] + ni * (d1[1] - y2) * beta * (1 - y2) * y2 *
                                    tab1[i];
        }
        E = 0.5 * (d1[0] - y1) * (d1[0] - y1) + 0.5 * (d1[1] - y2) * (d1[1] - y2);
        
        // DLA 4
        s1 = 0;
        s2 = 0;
        for (int i = 0; i < 13; i++)
        {
            s1 = s1 + tab4[i] * w[0][i];
            s2 = s2 + tab4[i] * w[1][i];
        }
        y1 = f(s1);
        y2 = f(s2);
        for (int i = 0; i < 13; i++)
        {
            w[0][i] = w[0][i] + ni * (d4[0] - y1) * beta * (1 - y1) * y1 *
                                    tab4[i];
            w[1][i] = w[1][i] + ni * (d4[1] - y2) * beta * (1 - y2) * y2 *
                                    tab4[i];
        }
        e4 = 0.5 * (d4[0] - y1) * (d4[0] - y1) + 0.5 * (d4[1] - y2) * (d4[1] - y2);
        // DLA 7
        s1 = 0;
        s2 = 0;

        for (int i = 0; i < 13; i++)
        {
            s1 = s1 + tab7[i] * w[0][i];
            s2 = s2 + tab7[i] * w[1][i];
        }

        y1 = f(s1);
        y2 = f(s2);

        for (int i = 0; i < 13; i++)
        {
            w[0][i] = w[0][i] + ni * (d7[0] - y1) * beta * (1 - y1) * y1 *
                                    tab7[i];
            w[1][i] = w[1][i] + ni * (d7[1] - y2) * beta * (1 - y2) * y2 *
                                    tab7[i];
        }

        e7 = 0.5 * (d7[0] - y1) * (d7[0] - y1) + 0.5 * (d7[1] - y2) * (d7[1] - y2);
        // DLA 2
        s1 = 0;
        s2 = 0;

        for (int i = 0; i < 13; i++)
        {
            s1 = s1 + tab2[i] * w[0][i];
            s2 = s2 + tab2[i] * w[1][i];
        }

        y1 = f(s1);
        y2 = f(s2);

        for (int i = 0; i < 13; i++)
        {
            w[0][i] = w[0][i] + ni * (d2[0] - y1) * beta * (1 - y1) * y1 *
                                    tab2[i];
            w[1][i] = w[1][i] + ni * (d2[1] - y2) * beta * (1 - y2) * y2 *
                                    tab2[i];
        }
        e2 = 0.5 * (d2[0] - y1) * (d2[0] - y1) + 0.5 * (d2[1] - y2) * (d2[1] - y2);
        E += e4 + e7 + e2;
        iter++;
    } while (E > 0.00005);

    cout << fixed << "Iteracji: " << iter << " ni: " << ni << " Minimalny blad: "
         << 0.00005 << endl;

    cout << "Dla 1: \n Oczekiwane: 1, 1 ";
    show(tab1, w);
    cout << "Dla 4: \n Oczekiwane: 1, 0 ";
    show(tab4, w);
    cout << "Dla 7: \n Oczekiwane: 0, 0 ";
    show(tab7, w);
    cout << "Dla 2: \n Oczekiwane: 0, 1 ";
    show(tab2, w);

    return 0;
}