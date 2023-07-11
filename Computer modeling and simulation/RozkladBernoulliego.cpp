#include <iostream>
#include <cmath>
#include <random>

using namespace std;


int main()
{
    const int n = 1000;

    std::default_random_engine generator;
    std::binomial_distribution<int> distribution(9, 0.6);

    int p[10] = {};

    for (int i = 0; i < n; ++i) {
        int number = distribution(generator);
        ++p[number];
    }

    std::cout << "binomial_distribution (9,0.6):" << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << i << ": " << p[i] << std::endl;

    return 0;
}

