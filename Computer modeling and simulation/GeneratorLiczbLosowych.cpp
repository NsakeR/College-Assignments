#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long int m = 2000;
	int tabX[10000], a = 3, c = 21;
	double mom1 = 0.0, mom2 = 0.0, mom3 = 0.0;
	tabX[0] = 4;
	for (int i = 0; i < m; i++) {
		tabX[i + 1] =  ((a * tabX[i] + c) % m); 
		cout << tabX[i] << endl;

		mom1 += 1.0 * tabX[i] /(static_cast<__int64>(m)-1) * 1.0;
		mom2 += 1.0 * pow(tabX[i], 2) /(static_cast<__int64>(m) - 1) * 1.0;
		mom3 += 1.0 * pow(tabX[i], 3) /(static_cast<__int64>(m) - 1) * 1.0;

	}

	mom1 = mom1 / m * 1.0;
	mom2 = mom2 / pow(m, 2) * 1.0;
	mom3 = mom3 / pow(m, 3) * 1.0;

	cout << "mom1 wynosi: " << mom1 << endl;
	cout << "mom1 wynosi: " << mom2 << endl;
	cout << "mom1 wynosi: " << mom3 << endl;
	
   return 0;
}

