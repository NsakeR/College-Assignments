#include <iostream>
#include <cmath>
#include<map>
#include<vector>
using namespace std;

int main()
{
    string wiersz = "";

    cout << "Wpisz stringa" << endl;
    cin >> wiersz;

    map<char, int> m;
    vector<double> p;
    double entropia = 0.0;

    for (char i : wiersz) {
        if (i != ' ') {
            m[i]++;
        }
    }

    double x;
    cout << "Ilosc unikalnych symboli: " << m.size() << endl;
    cout << endl;
    for (auto i : m) {
        x = (1.0 * i.second) / (1.0 * wiersz.size());
        p.push_back(x);
        cout << i.first << " wystepuje: " << i.second << " razy, prawdopodobienstwo wynosi: "<< x << endl;
    }

    for (int i = 0; i < m.size(); i++) {
        entropia += (p[i] * -log2(p[i]));
    }
    cout << endl;
    cout << "Entropia: " << entropia;

    return 0;
}
