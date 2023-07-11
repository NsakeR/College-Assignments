#include <iostream>

using namespace std;

int main()
{ 
    int x1[7] = { 2, 2, 0, -2, -2, 0, 4 };
    int x2[7] = { 1, 2, 6, 10, 0, 0, -20 };
    int D[7] = { 1, 1, 1, -1, -1, -1, -1 };
    int w[3]{ 0 };
    int zz, y;
    int s = 0;
    bool modification = false;
    
    for (zz = 0; zz < 1000; zz++) {
        modification = false;
        for (int i = 0; i < 7; i++) {
            s = x1[i] * w[1] + x2[i] * w[2] + w[0];
            if (s > 0) {
                y = 1;
            }
            else { y = -1; }
            
            if (y != D[i]) {
                w[0] = w[0] + D[i];
                w[1] = w[1] + D[i] * x1[i];
                w[2] = w[2] + D[i] * x2[i];
                modification = true;
            } 
        }
        if (modification == false) {
            break;
        }
    }
    cout << "Ilosc iteracji: " << zz << endl;
    cout << "Wagi: " << w[0] << " " << w[1] << " " << w[2] << endl;
    return 0;
}