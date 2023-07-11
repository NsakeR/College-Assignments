#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double beta = 0.5;

double f(double s)
{
    return 1 / (1 + exp(-beta * s));
}

int main()
{
    double ni = 0.5;
    double d1 = 1.0;
    double d4 = 0.0;
    double w[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double tab1[13] = {1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1};
    double tab4[13] = {1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1};
    double mixed1[13] = {1, -1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1};
    double mixed4[13] = {1, 1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1};
    double E;
    double s;
    double e4;
    double y;
    int iter = 0;

    do
    {
        E = 0;
        e4 = 0;
        s = 0;
        for (int i = 0; i < 13; i++)
        {
            s = s + tab1[i] * w[i];
        }
        y = f(s);
        for (int i = 0; i < 13; i++)
        {
            w[i] = w[i] + ni * (d1 - y) * beta * (1 - y) * y * tab1[i];
        }
        E = 0.5 * (d1 - y) * (d1 - y);
        s = 0;
        for (int i = 0; i < 13; i++)
        {
            s = s + tab4[i] * w[i];
        }
        y = f(s);
        for (int i = 0; i < 13; i++)
        {
            w[i] = w[i] + ni * (d4 - y) * beta * (1 - y) * y * tab4[i];
        }
        e4 = 0.5 * (d4 - y) * (d4 - y);
        E = E + e4;
        iter++;
    } while (E > 0.00005);

    cout << "Iteracji: " << iter << endl;

    s = 0;
    for (int i = 0; i < 13; i++)
        s = s + tab1[i] * w[i];
    cout << setprecision(9) << "y1=" << f(s) << endl;

    s = 0;
    for (int i = 0; i < 13; i++)
        s = s + tab4[i] * w[i];
    cout << "y4=" << f(s) << endl;
    
    cout << "---------------------------------------" << endl;
    s = 0;
    for (int i = 0; i < 13; i++)
        s = s + mixed1[i] * w[i];
    cout << "Zmodyfikowana 1=" << f(s) << endl;

    s = 0;
    for (int i = 0; i < 13; i++)
        s = s + mixed4[i] * w[i];
    cout << "Zmodyfikowana 4=" << f(s) << endl;

    return 0;
}