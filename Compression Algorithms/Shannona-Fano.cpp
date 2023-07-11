#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// declare structure node
struct node {

    // for storing symbol
    string sym;

    // for storing probability or frequency
    float pro;
    int arr[20];
    int top;
} p[20];

typedef struct node node;

// function to find shannon code
void shannon(int l, int h, node p[])
{
    float pack1 = 0, pack2 = 0, diff1 = 0, diff2 = 0;
    int i, d, k, j;
    if ((l + 1) == h || l == h || l > h) {
        if (l == h || l > h)
            return;
        p[h].arr[++(p[h].top)] = 0;
        p[l].arr[++(p[l].top)] = 1;
        return;
    }
    else {
        for (i = l; i <= h - 1; i++)
            pack1 = pack1 + p[i].pro;
        pack2 = pack2 + p[h].pro;
        diff1 = pack1 - pack2;
        if (diff1 < 0)
            diff1 = diff1 * -1;
        j = 2;
        while (j != h - l + 1) {
            k = h - j;
            pack1 = pack2 = 0;
            for (i = l; i <= k; i++)
                pack1 = pack1 + p[i].pro;
            for (i = h; i > k; i--)
                pack2 = pack2 + p[i].pro;
            diff2 = pack1 - pack2;
            if (diff2 < 0)
                diff2 = diff2 * -1;
            if (diff2 >= diff1)
                break;
            diff1 = diff2;
            j++;
        }
        k++;
        for (i = l; i <= k; i++)
            p[i].arr[++(p[i].top)] = 1;
        for (i = k + 1; i <= h; i++)
            p[i].arr[++(p[i].top)] = 0;

        // Invoke shannon function
        shannon(l, k, p);
        shannon(k + 1, h, p);
    }
}

// Function to sort the symbols
// based on their probability or frequency
void sortByProbability(int n, node p[])
{
    int i, j;
    node temp;
    for (j = 1; j <= n - 1; j++) {
        for (i = 0; i < n - 1; i++) {
            if ((p[i].pro) > (p[i + 1].pro)) {
                temp.pro = p[i].pro;
                temp.sym = p[i].sym;

                p[i].pro = p[i + 1].pro;
                p[i].sym = p[i + 1].sym;

                p[i + 1].pro = temp.pro;
                p[i + 1].sym = temp.sym;
            }
        }
    }
}

void display(int n, node p[], vector<pair<char, int>> vec)
{
    int i, j, g;
    cout << "\n  Letter\tQuantity\tCode";
    for (i = n - 1, g = 0; i >= 0, g < vec.size(); i--, g++) {
        cout << "\n  " << p[i].sym << "\t\t" << vec[g].second << "\t";
        for (j = 0; j <= p[i].top; j++)
            cout << p[i].arr[j];
    }
}

bool sortbysec(const pair<char, int>& a,
	const pair<char, int>& b)
{
	return (a.second > b.second);
}

// Driver code
int main()
{
    int i, j;
    float total = 0;
    string ch;
    node temp;

    string mess; 
	map<int, char> counter;
	vector<pair<char, int>> vec;

	cout << "Kodowanie Shannona-Fano" << endl;
	cout << "Podaj tekst" << endl;
	cin >> mess;

	for (char i : mess)
		if (i != ' ')
			counter[i]++;

	for (auto i : counter) {
		vec.push_back(i);
	}

	counter.clear();

	sort(vec.begin(), vec.end(), sortbysec);

    // Wpisz symbole
    for (i = 0; i < vec.size(); i++) {
        p[i].sym += vec[i].first;
    }

    for (i = 0; i < vec.size(); i++) {

        // Ustaw wartość prawdopodobienstwa
        p[i].pro = vec[i].second / (float)mess.length();
        total = total + p[i].pro;

        // checking max probability
        if (total > 1) {
            cout << "Za duze prawd.";
            total = total - p[i].pro;
            i--;
            break;
        }
    }

    p[i].pro = 1 - total;

    sortByProbability(vec.size(), p);

    for (i = 0; i < vec.size(); i++)
        p[i].top = -1;

    shannon(0, vec.size() - 1, p);

    display(vec.size(), p, vec);
    return 0;
}
