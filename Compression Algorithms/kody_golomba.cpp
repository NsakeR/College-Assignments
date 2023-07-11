#include <iostream>
#include <string>
#include <cmath>
#include <bitset>

using namespace std;

string kodowanie_unarny(string number) {
    string temp;
    for (int i = 0; i < number.length(); i++) {
        if (number[i] == '0') {
            temp += "0";
        }
        else if (number[i] == '1') {
            temp += "10";
        }
        else if (number[i] == '2') {
            temp += "110";
        }
        else if (number[i] == '3') {
            temp += "1110";
        }
        else if (number[i] == '4') {
            temp += "11110";
        }
        else if (number[i] == '5') {
            temp += "111110";
        }
        else if (number[i] == '6') {
            temp += "1111110";
        }
        else if (number[i] == '7') {
            temp += "11111110";
        }
        else if (number[i] == '8') {
            temp += "111111110";
        }

        else if (number[i] == '9') {
            temp += "1111111110";
        }
        else if (number[i] == 'A') {
            temp += "11111111110";
        }
        else if (number[i] == 'B') {
            temp += "111111111110";
        }
        else if (number[i] == 'C') {
            temp += "1111111111110";
        }
        else if (number[i] == 'D') {
            temp += "11111111111110";
        }
        else if (number[i] == 'E') {
            temp += "111111111111110";
        }
    }
    return temp;
};


// KOD BINARNY
//
string kodowanie_binarny(string number) {
    string temp;
    for (int i = 0; i < number.length(); i++) {
        if (number[i] == '0') {
            temp += "0000";
        }
        else if (number[i] == '1') {
            temp += "0001";
        }
        else if (number[i] == '2') {
            temp += "0010";
        }
        else if (number[i] == '3') {
            temp += "0011";
        }
        else if (number[i] == '4') {
            temp += "0100";
        }
        else if (number[i] == '5') {
            temp += "0101";
        }
        else if (number[i] == '6') {
            temp += "0110";
        }
        else if (number[i] == '7') {
            temp += "0111";
        }
        else if (number[i] == '8') {
            temp += "1000";
        }
        else if (number[i] == '9') {
            temp += "1001";
        }
        else if (number[i] == 'A') {
            temp += "1010";
        }
        else if (number[i] == 'B') {
            temp += "1011";
        }
        else if (number[i] == 'C') {
            temp += "1100";
        }
        else if (number[i] == 'D') {
            temp += "1101";
        }
        else if (number[i] == 'E') {
            temp += "1110";
        }
        else if (number[i] == 'F') {
            temp += "1111";
        }
    }
    return temp;
};


string golomb(string x, int m) {
    string temp, h, temp2;
    
    if (m == 1) {
        temp = kodowanie_unarny(x);
        return temp;
    }
    
    int number;
    int eq = 0;
    int r = 0, k = 0, o = 0;
    if (ceil(log2(m)) == floor(log2(m)))
    {
        //cz1 
        number = stoi(x);
        eq = number / m;
        h = to_string(eq);

        temp = kodowanie_unarny(h);
        temp += " ";
        h = "";

        //cz2 
        k = (int)log2(m);
        r = number - (eq * m);
        h = to_string(r);
        temp2 = kodowanie_binarny(h);
        temp2.erase(0, 4 - k);
        temp += temp2;
        temp2 = "";
    }
    else {
        //cz1 
        number = stoi(x);
        eq = number / m;
        h = to_string(eq);
        temp = kodowanie_unarny(h);
        h = "";
        temp += " ";
        //cz2
        r = number - (eq * m);
        k = (int)log2(m) + 1;
        if (r < (pow(2, k) - m)) {
            h = to_string(r);
            temp2 = kodowanie_binarny(h);
            temp2.erase(0, 4 - k + 1);
            temp += temp2;
        }
        else {
            o = r + (pow(2, k) - m);
            h = to_string(o);
            temp2 = kodowanie_binarny(h);
            temp2.erase(0, 4 - k);
            temp += temp2;
        }
    }
    return temp;
}


int main()
{
    string x, wynik;
    int m;

    cout << "Kodowanie Golomba" << endl;
    cout << "Wpisz rzad m: " << endl;
    cin >> m;
    cout << "Wpisz liczbe x: " << endl;
    cin >> x;
    wynik = golomb(x, m);
    cout << wynik;

    return 0;
}
