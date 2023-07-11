//===============================================================================
== == == ==
// DLA 8 LITER
// Przerobiony przykład dla samego STYX
#include <iostream>
    using namespace std;
const double beta = 0.4;
const double ni = 0.4;
double f(double s)
{
    return 1 / (1 + exp(-beta * s));
}
double calc(double tab[], double w[3][36], double d[])
{
    double s1 = 0;
    double s2 = 0;
    double s3 = 0;
    for (int i = 0; i < 36; i++)
    {
        s1 = s1 + tab[i] * w[0][i];
        s2 = s2 + tab[i] * w[1][i];
        s3 = s3 + tab[i] * w[2][i];
    }
    double y1 = f(s1);
    double y2 = f(s2);
    double y3 = f(s3);
    for (int i = 0; i < 36; i++)
    {
        w[0][i] = w[0][i] + ni * (d[0] - y1) * beta * (1 - y1) * y1 * tab[i];
        w[1][i] = w[1][i] + ni * (d[1] - y2) * beta * (1 - y2) * y2 * tab[i];
        w[2][i] = w[2][i] + ni * (d[2] - y3) * beta * (1 - y3) * y3 * tab[i];
    }
    double e = 0.5 * (d[0] - y1) * (d[0] - y1) + 0.5 * (d[1] - y2) * (d[1] - y2) + 0.5 * (d[2] - y3) * (d[2] - y3);
    return e;
}
void show(double tab[], double w[3][36])
{
    double s1 = 0;
    double s2 = 0;
    double s3 = 0;
    for (int i = 0; i < 36; i++)
    {
        s1 = s1 + tab[i] * w[0][i];
        s2 = s2 + tab[i] * w[1][i];
        s3 = s3 + tab[i] * w[2][i];
    }
    cout << "s1: =" << f(s1) << " s2: " << f(s2) << " s3: " << f(s3) << endl;
}
int main()
{

    double w[3][36] = {0};

    double tabS[36] = {1, -1, 1, 1, 1, -1, 1, -1, -1, -1, 1, 1, -1, -1, -1, -1, -1, 1, 1, 1, -1, -1, -1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, 1, 1, -1};
    double tabT[36] = {1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1};
    double tabY[36] = {1, 1, -1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1};
    double tabX[36] = {1, 1, -1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, -1, 1, -1, -1, -1, 1, -1, -1, -1, 1, -1, 1, -1, 1, -1, -1, -1, 1, 1, -1, -1, -1, 1};
    double tabE[36] = {1, 1, 1, 1, 1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, 1, 1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, 1, 1, 1, -1};
    double tabF[36] = {1, 1, 1, 1, 1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, 1, 1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, -1, -1, -1, -1};
    double tabG[36] = {1, -1, 1, 1, 1, -1, 1, -1, -1, -1, 1, 1, -1, -1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, -1, 1, 1, -1, -1, -1, 1, -1, 1, 1, 1, -1};
    double tabH[36] = {1, 1, -1, -1, -1, 1, 1, -1, -1, -1, 1, 1, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, -1, -1, -1, 1, 1, -1, -1, -1, 1, 1, -1, -1, -1, 1};
    double S[3]{1, 1, 1}, T[3]{1, 1, 0}, Y[3]{1, 0, 0}, X[3]{1, 0, 1}, E[3]{0, 1, 1},
        F[3]{0, 0, 1}, G[3]{0, 1, 0}, H[3]{0, 0, 0};

    double eS, eT, eY, eX, eE, eF, eG, eH;
    int iter = 0;

    do
    {
        eS = 0;
        eT = 0;
        eY = 0;
        eX = 0;
        eE = 0;
        eF = 0;
        eG = 0;
        eH = 0;
        eS = calc(tabS, w, S);
        eT = calc(tabT, w, T);
        eY = calc(tabY, w, Y);
        eX = calc(tabX, w, X);
        eE = calc(tabE, w, E);
        eF = calc(tabF, w, F);
        eG = calc(tabG, w, G);
        eH = calc(tabH, w, H);
        eS += eT + eY + eX + eE + eF + eG + eH;

        iter++;
    } while (eS > 0.00005);
    
    cout << fixed << "Iteracji: " << iter << " ni: " << ni << " Minimalny blad: "
         << 0.0005 << endl;
    cout << "Dla S: \n Oczekiwane: 1, 1, 1 ";
    show(tabS, w);
    cout << "Dla T: \n Oczekiwane: 1, 1, 0 ";
    show(tabT, w);
    cout << "Dla Y: \n Oczekiwane: 1, 0, 0 ";
    show(tabY, w);
    cout << "Dla X: \n Oczekiwane: 1, 0, 1 ";
    show(tabX, w);
    cout << "Dla E: \n Oczekiwane: 0, 1, 1 ";
    show(tabE, w);
    cout << "Dla F: \n Oczekiwane: 0, 0, 1 ";
    show(tabF, w);
    cout << "Dla G: \n Oczekiwane: 0, 1, 0 ";
    show(tabG, w);
    cout << "Dla H: \n Oczekiwane: 0, 0, 0 ";
    show(tabH, w);

    return 0;
}