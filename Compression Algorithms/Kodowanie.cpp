// Kodowanie.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;

// KOD UNARNY
//
//void kodowanie(string number) {
//    string temp;
//    for (int i = 0; i < number.length(); i++) {
//        if (number[i] == '1') {
//            temp += "0";
//        }
//        else if (number[i] == '2') {
//            temp += "10";
//        }
//        else if (number[i] == '3') {
//            temp += "110";
//        }
//        else if (number[i] == '4') {
//            temp += "1110";
//        }
//        else if (number[i] == '5') {
//            temp += "11110";
//        }
//        else if (number[i] == '6') {
//            temp += "111110";
//        }
//        else if (number[i] == '7') {
//            temp += "1111110";
//        }
//        else if (number[i] == '8') {
//            temp += "11111110";
//        }
//        else if (number[i] == '9') {
//            temp += "111111110";
//        }
//
//        else if (number[i] == 'A') {
//            temp += "1111111110";
//        }
//        else if (number[i] == 'B') {
//            temp += "11111111110";
//        }
//        else if (number[i] == 'C') {
//            temp += "111111111110";
//        }
//        else if (number[i] == 'D') {
//            temp += "1111111111110";
//        }
//        else if (number[i] == 'E') {
//            temp += "11111111111110";
//        }
//        else if (number[i] == 'F') {
//            temp += "111111111111110";
//        }
//    }
//    cout << temp << endl;
//};
//
//void dekodowanie(string kod) {
//    string temp;
//    int d = 0;
//    int i = 0;
//    int koniec = kod.length();
//    while (i != koniec) {
//        for (i; i < kod.length(); i++) {
//            if (kod[i] == '1') {
//                d += 1;
//            }
//            if (kod[i] == '0') {
//                d += 1; 
//                i = i + 1;
//
//                if (d == 1) {
//                    temp += "1";
//                }
//                else if (d == 2) { temp += "2"; }
//                else if (d == 3) { temp += "3"; }
//                else if (d == 4) { temp += "4"; }
//                else if (d == 5) { temp += "5"; }
//                else if (d == 6) { temp += "6"; }
//                else if (d == 7) { temp += "7"; }
//                else if (d == 8) { temp += "8"; }
//                else if (d == 9) { temp += "9"; }
//                else if (d == 10) { temp += "A"; }
//                else if (d == 11) { temp += "B"; }
//                else if (d == 12) { temp += "C"; }
//                else if (d == 13) { temp += "D"; }
//                else if (d == 14) { temp += "E"; }
//                else if (d == 15) { temp += "F"; }
//
//                d = 0;
//                break;  
//            }
//        }
//    }
//        cout << temp << endl;
//}

// KOD BINARNY
//
//void kodowanie(string number) {
//    string temp;
//    for (int i = 0; i < number.length(); i++) {
//        if (number[i] == '1') {
//            temp += "0001";
//        }
//        else if (number[i] == '2') {
//            temp += "0010";
//        }
//        else if (number[i] == '3') {
//            temp += "0011";
//        }
//        else if (number[i] == '4') {
//            temp += "0100";
//        }
//        else if (number[i] == '5') {
//            temp += "0101";
//        }
//        else if (number[i] == '6') {
//            temp += "0110";
//        }
//        else if (number[i] == '7') {
//            temp += "0111";
//        }
//        else if (number[i] == '8') {
//            temp += "1000";
//        }
//        else if (number[i] == '9') {
//            temp += "1001";
//        }
//        else if (number[i] == 'A') {
//            temp += "1010";
//        }
//        else if (number[i] == 'B') {
//            temp += "1011";
//        }
//        else if (number[i] == 'C') {
//            temp += "1100";
//        }
//        else if (number[i] == 'D') {
//            temp += "1101";
//        }
//        else if (number[i] == 'E') {
//            temp += "1110";
//        }
//        else if (number[i] == 'F') {
//            temp += "1111";
//        }
//    }
//    cout << temp << endl;
//};
//
//void dekodowanie(string kod) {
//    string temp;
//    string abc;
//    int d = 0;
//    int koniec = kod.length();
//    for (int i = 0; i < kod.length(); i++) {
//        abc += kod[i];
//        d++;
//
//        if (d == 4) {
//            if (abc == "0001") {temp += "1"; }
//            else if (abc == "0010") { temp += "2"; }
//            else if (abc == "0011") { temp += "3"; }
//            else if (abc == "0100") { temp += "4"; }
//            else if (abc == "0101") { temp += "5"; }
//            else if (abc == "0110") { temp += "6"; }
//            else if (abc == "0111") { temp += "7"; }
//            else if (abc == "1000") { temp += "8"; }
//            else if (abc == "1001") { temp += "9"; }
//            else if (abc == "1010") { temp += "A"; }
//            else if (abc == "1011") { temp += "B"; }
//            else if (abc == "1100") { temp += "C"; }
//            else if (abc == "1101") { temp += "D"; }
//            else if (abc == "1110") { temp += "E"; }
//            else if (abc == "1111") { temp += "F"; }
//            d = 0;
//            abc = "";
//        }
//    }
//      
//    
//    cout << temp << endl;
//}
//-------------------------------------------------------------
// Gamma Elias
// void kodowanie(string number) {
//    string temp;
//    for (int i = 0; i < number.length(); i++) {
//        if (number[i] == '1') {
//            temp += "1";
//        }
//        else if (number[i] == '2') {
//            temp += "010";
//        }
//        else if (number[i] == '3') {
//            temp += "011";
//        }
//        else if (number[i] == '4') {
//            temp += "00100";
//        }
//        else if (number[i] == '5') {
//            temp += "00101";
//        }
//        else if (number[i] == '6') {
//            temp += "00110";
//        }
//        else if (number[i] == '7') {
//            temp += "00111";
//        }
//        else if (number[i] == '8') {
//            temp += "0001000";
//        }
//        else if (number[i] == '9') {
//            temp += "0001001";
//        }
//
//        else if (number[i] == 'A' || number[i] == 'a') {
//            temp += "0001010";
//        }
//        else if (number[i] == 'B' || number[i] == 'b') {
//            temp += "0001011";
//        }
//        else if (number[i] == 'C' || number[i] == 'c') {
//            temp += "0001100";
//        }
//        else if (number[i] == 'D' || number[i] == 'd') {
//            temp += "0001101";
//        }
//        else if (number[i] == 'E' || number[i] == 'e') {
//            temp += "0001110";
//        }
//        else if (number[i] == 'F' || number[i] == 'f') {
//            temp += "0001111";
//        }
//    }
//    cout << temp << endl;
//};
//
// void dekodowanie(string kod) {
//     string temp;
//     string wyn;
//     int pos = 0;
//     int i = 0, j;
//     bool koniec = false;
//     while (koniec == false) {
//         for (i; i < kod.length(); i++) {
//             if (kod[i] == '0') {
//                 pos++;
//                 temp += kod[i];
//             }
//             if (kod[i] == '1') {
//                 temp += kod[i];
//                 break;
//             }
//         }
//         for (j = 1; j <= pos; j++) {
//             temp += kod[i + j];
//         }
//        
//         if (temp == "1") { wyn += "1"; }
//         else if (temp == "010") { wyn += "2"; }
//         else if (temp == "011") { wyn += "3"; }
//         else if (temp == "00100") { wyn += "4"; }
//         else if (temp == "00101") { wyn += "5"; }
//         else if (temp == "00110") { wyn += "6"; }
//         else if (temp == "00111") { wyn += "7"; }
//         else if (temp == "0001000") { wyn += "8"; }
//         else if (temp == "0001001") { wyn += "9"; }
//         else if (temp == "0001010") { wyn += "A"; }
//         else if (temp == "0001011") { wyn += "B"; }
//         else if (temp == "0001100") { wyn += "C"; }
//         else if (temp == "0001101") { wyn += "D"; }
//         else if (temp == "0001110") { wyn += "E"; }
//         else if (temp == "0001111") { wyn += "F"; }
//         if (i + j == kod.length()) {
//             koniec = true;
//         }
//         i = i + pos + 1;
//         pos = 0;
//         temp = "";
//     }
//     cout << wyn << endl;
// }
//------------------------------------------------------------------
// Fraenkela–Kleina C1
void kodowanie(string number) {
    string temp;
        for (int i = 0; i < number.length(); i++) {
            if (number[i] == '1') {
                temp += "11";
            }
            else if (number[i] == '2') {
                temp += "011";
            }
            else if (number[i] == '3') {
                temp += "0011";
            }
            else if (number[i] == '4') {
                temp += "1011";
            }
            else if (number[i] == '5') {
                temp += "00011";
            }
            else if (number[i] == '6') {
                temp += "10011";
            }
            else if (number[i] == '7') {
                temp += "01011";
            }
            else if (number[i] == '8') {
                temp += "000011";
            }
            else if (number[i] == '9') {
                temp += "100011";
            }
            else if (number[i] == 'A') {
                temp += "010011";
            }
            else if (number[i] == 'B') {
                temp += "001011";
            }
            else if (number[i] == 'C') {
                temp += "101011";
            }
            else if (number[i] == 'D') {
                temp += "0000011";
            }
            else if (number[i] == 'E') {
                temp += "1000011";
            }
            else if (number[i] == 'F') {
                temp += "0100011";
            }
        }
        cout << temp << endl;
}

void dekodowanie(string kod) {
        string temp;
        string abc;
        int i = 0;
        for (i; i < kod.length() - 1; i++) {
            abc += kod[i];
            if (kod[i] == '1' && kod[i + 1] == '1') {
                abc += kod[i + 1];
                
                if (abc == "11") {temp += "1"; }
                else if (abc == "011") { temp += "2"; }
                else if (abc == "0011") { temp += "3"; }
                else if (abc == "1011") { temp += "4"; }
                else if (abc == "00011") { temp += "5"; }
                else if (abc == "10011") { temp += "6"; }
                else if (abc == "01011") { temp += "7"; }
                else if (abc == "000011") { temp += "8"; }
                else if (abc == "100011") { temp += "9"; }
                else if (abc == "010011") { temp += "A"; }
                else if (abc == "001011") { temp += "B"; }
                else if (abc == "101011") { temp += "C"; }
                else if (abc == "0000011") { temp += "D"; }
                else if (abc == "1000011") { temp += "E"; }
                else if (abc == "0100011") { temp += "F"; }

                abc = "";
                i++;
            } 
        }
          
        
        cout << temp << endl;
}


int main()
{
    string kod;
    string number;
    int abc = 0;
    while (true) {
        cout << "Jeśli chcesz zakonczyc program wybierz 9" << endl;
        cout << "dekodowanie czy kodowanie (0/1)" << endl;
        cin >> abc;
        if (abc == 9) {
            break;
        }
        if (abc == 0) {
            cout << "Wpisz kod" << endl;
            cin >> kod;
            dekodowanie(kod);
        }
        else {
            cout << "Wpisz liczbe dziesietna" << endl;
            cin >> number;
            kodowanie(number);
        }
    }
    return 0;
}
