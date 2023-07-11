#include <iostream>
#include <vector> 

using namespace std;

void aritmeticalCoding(string alfabet, string text) {

    float leftB = 0.0, rightB = 1.0, tempL, tempR;
    float prawd;

    vector<pair<char, float>> vec;
    cout << "Podaj prawdopodobienstwa" << endl;
    for (unsigned int i = 0; i < alfabet.size(); i++) {
        cin >> prawd;
        vec.push_back(make_pair(alfabet[i], prawd));
    }

    float zero = 0.0, cpp = 0.0, cpd = 0.0, tempcpd;

    vector<pair<float, float>> borders;
    for (unsigned int i = 0, j = 0; i < text.size(), j < alfabet.size() - 1; i++, j++) {
        tempL = leftB;
        tempR = rightB;
        tempcpd = cpd;

        if (text[i] == vec[0].first) {
            cpp = zero;
            cpd = vec[0].second;
            j--;
        }
        else if (text[i] == text[i - 1]) {
            j--;
        }
        else {
            cpp = tempcpd;
            cpd = tempcpd + vec[j + 1].second;
        }

        leftB = tempL + (tempR - tempL) * cpp;
        rightB = tempL + (tempR - tempL) * cpd;

        borders.push_back(make_pair(leftB, rightB));
    }

    cout << "[ " << borders.back().first << " " << borders.back().second << " )\n\n";
}

void aritmeticalDecoding(string alfabet, float x, int s) {
    
    string text;
    float leftB = 0.0, rightB = 1.0;
    float prawd;
    vector<pair<char, float>> vec;
    cout << "Podaj prawdopodobienstwa" << endl;
    for (unsigned int i = 0; i < alfabet.size(); i++) {
        cin >> prawd;
        vec.push_back(make_pair(alfabet[i], prawd));
    }

    vector<pair<float, float>> borders;
    borders.push_back(make_pair(0.0, 1.0));

    for (int i = 0; i < s; i++) {
        for (int z = 0; z < alfabet.size(); z++) {

            if (z == 0) {
                leftB = borders[i].first;
                rightB = leftB + (borders[i].second - borders[i].first) * vec[0].second;
            }
            else {
                leftB = rightB;
                rightB = leftB + (borders[i].second - borders[i].first) * vec[z].second;
            }

            if (x >= leftB && x < rightB) {
                text += vec[z].first;
                borders.push_back(make_pair(leftB, rightB));
                break;
            }
        }
    }

    cout << text << endl;
}

void showVec(vector <pair<char, float>> v) {
    for (auto i : v) {
        cout << i.first << " " << i.second << endl;
    }
}

int main()
{
    string alfabet, text;
    int q, s; 
    float x;
    cout << "! Kodowanie arytmetyczne !\n\n";

    while (true) {
        cout << "Co chcesz zrobic" << endl;
        cout << "1. Zakodowac" << endl;
        cout << "2. Odkodowac" << endl;
        cout << "3. Wyjdz " << endl;


        cin >> q;
        if (q == 3)
            break;

        switch (q) {
        case 1:
            cout << "Podaj tekst" << endl;
            cin >> text;
            cout << "Podaj alfabet" << endl;
            cin >> alfabet;

            aritmeticalCoding(alfabet, text);
            break;
        case 2:
            cout << "Podaj wartosc X "; cin >> x;
            cout << "Ile liter: ";   cin >> s;
            cout << "Podaj alfabet: "; cin >> alfabet;

            aritmeticalDecoding(alfabet, x, s);
            break;

        default:
            ;
        }
    }
}
