#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double beta = 0.7;

double f(double s)
{
    return (1.0 - exp(-beta * s)) / (1.0 + exp(-beta * s));
}
int main()
{
    double w[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double tab1[13] = {1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, -1, 1};
    double tab4[13] = {1, 1, -1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1};
    double modTab1[13] = {1, -1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1};
    double modTab4[13] = {1, 1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1};
    double d1 = 1.0, d4 = -1.0;
    double E;
    double e4 = 0.0;
    double ni = 0.01;
    int iter = 0;
    double s, y1, y4, mody1, mody4;
    do
    {
        E = 0.0;
        s = 0.0;
        for (int i = 0; i < 13; i++)
        {
            s += tab1[i] * w[i];
        }
        y1 = f(s);
        s = 0.0;
        for (int i = 0; i < 13; i++)
        {
            s += modTab1[i] * w[i];
        }
        mody1 = f(s);
        for (int i = 0; i < 13; i++)
        {
            w[i] = w[i] + ni * d1 * tab1[i];
        }
        E = 0.5 * (d1 - y1) * (d1 - y1);
        s = 0.0;
        for (int i = 0; i < 13; i++)
        {
            s += tab4[i] * w[i];
        }
        y4 = f(s);
        s = 0.0;
        for (int i = 0; i < 13; i++)
        {
            s += modTab4[i] * w[i];
        }
        mody4 = f(s);
        for (int i = 0; i < 13; i++)
        {
            w[i] = w[i] + ni * d4 * tab4[i];
        }
        e4 = 0.5 * (d4 - y4) * (d4 - y4);
        E = E + e4;
        iter++;
    } while (E > 0.0000005);
    cout << iter << endl;
    cout << "dla 4 " << setprecision(15) << y4 << endl;
    cout << "dla 1 " << y1 << endl;
    cout << "dla mod 1 " << mody1 << endl;
    cout << "dla mod 4 " << mody4 << endl;
    return 0;
}