#include <iostream>
#include <string>

using namespace std;

void RLEcoding(string text) {
    
    int counter = 0;

    for (int i = 0; i < text.length(); i++) {

        if (text[i] == text[i + 1] && i < text.length() - 1) {
            counter++;            
        }
        else {
            cout << counter + 1 << text[i];
            counter = 0;
        }
    }
}

void RLEdecoding(string text) {

    int h = 0;

    for (int i = 0; i < text.length(); i++) {
        if (i % 2 == 0) {
            h = stoi(text.substr(i, 1));
        }
        else {
            for (int j = 0; j < h; j++) {
                cout << text[i];
            }
        }
    }

}

int main()
{
    string text;
    int x;

    cout << "! RLE ! \n";
    cout << "1. Kodowanie \n";
    cout << "2. Dekodowanie \n";
    cout << "3. Wyjscie \n";

    while (true) {
        
        cout << "X: "; cin >> x;
        if (x == 3) break;

            switch (x) {
            case 1:
                cout << "Podaj tekst: "; cin >> text;
                RLEcoding(text);
            case 2:
                cout << "Podaj tekst: "; cin >> text;
                RLEdecoding(text);
            default:
                ;
        }
    }
    return 0;
}
