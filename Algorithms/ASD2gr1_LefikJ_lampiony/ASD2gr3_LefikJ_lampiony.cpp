//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Program znajduje ilość małych lampionów w otoczce zewnętrznej tworzonej algorytmem Grahama.
//  
//  Autor: Jakub Lefik      Data utworzenia: 15.06.2021
//  
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class Coords {
private:
    long long x; 
    long long y;
public: 
    Coords();
    Coords(long long x, long long y);
    Coords(const Coords& Kop);
    Coords& operator=(const Coords& R);
    bool operator<(const Coords& f);
    ~Coords();
    //gettery i settery
    long long getX();
    void setX(long long x);
    long long getY();
    void setY(long long y);
};

// Zmienna globalna używana przy przeciążeniu operatora<
Coords p;

long long distance(Coords p1, Coords p2)
{
    return (p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) + (p1.getY() - p2.getY()) * (p1.getY() - p2.getY());
}

long long angle(Coords f, Coords q, Coords r)
{
    long long val = (q.getY() - f.getY()) * (r.getX() - q.getX()) - (q.getX() - f.getX()) * (r.getY() - q.getY());

    // jeżeli val = 0, to znaczy że jest na linii/ jej przedłużeniu 
    // val < 0 to wyrzuć 2 i punkty idą wbrew ruchowi wskazówek zegara, jeśli val > 0 to wyrzuć 1 i punkty idą zgodnie z ruchem wskazówek zegara
    // (Na przyszłość: nie, 1 i 2 nie ma nic wspólnego z wartością sinusa, równie dobrze to mogą być 3 i 4, just zmienne "logiczne" dzięki którym potem możesz dać warunek o == 0/1/2)

    if (val == 0) {
        return 0;
    }
    return (val > 0) ? 1 : 2;
}

// Funkcja pomocnicza do wyświetlenia vectora z danymi

void show(std::vector<Coords>& vec) {
    for (unsigned int i = 0; i < vec.size(); i++) {
        std::cout << "x: " << vec[i].getX() << " y: " << vec[i].getY() << std:: endl;
    }
}

// Funkcja pomocnicza zwracająca element "2" ze stosu

Coords nextToTop(std::stack<Coords>& S)
{
    Coords u = S.top();             // Przechowaj wartość z góry stosu 
    S.pop();                        // Usuń ją
    Coords res = S.top();           // Pobierz pod byłym indeksem "2" 
    S.push(u);                      // Wrzuć z powrotem na wierzch u
    return res;
}

// Funkcja która tworzy otoczke zewnętrzną

void graham(std::vector<Coords> &cc, Coords &p, std::vector<Coords> &results) {
    long long min = cc[0].getY();
    int ad = 0;
    
    // Wyznaczanie punktu o najmniejszym Y

    for (unsigned int i = 1; i < cc.size(); i++) {
        if (cc[i].getY() < min || (min == cc[i].getY() && cc[i].getX() < cc[ad].getX())) {
            ad = i;
            min = cc[i].getY();
        }
    }

    std::swap(cc[0], cc[ad]);
    p = cc[0];

    // Dzięki przeciążonemu operatorowi< porównuje nam na podstawie kąta, a jeśli są takie same to po odległości
    std::sort(cc.begin(), cc.end());
    int m = 1; 
    for (unsigned int i = 1; i < cc.size(); i++)
    {
        while (i < cc.size() - 1 && angle(p, cc[i], cc[i + 1]) == 0) {
            i++;
        }

        cc[m] = cc[i];
        m++; 
    }

    if (m < 3) return;

    std::stack<Coords> S;
    S.push(cc[0]);
    S.push(cc[1]);
    S.push(cc[2]);
// https://en.wikipedia.org/wiki/Graham_scan

    for (int i = 3; i < m; i++)
    {
        while (S.size() > 1 && angle(nextToTop(S), S.top(), cc[i]) != 2) {
            S.pop();
        }
        S.push(cc[i]);
    }

    while (!S.empty()) {
        Coords k = S.top();
        results.push_back(k);
        S.pop();
    }
}

bool isInside(std::vector<Coords>& otoZew, Coords& pkt) {
    
    // Nie da się zrobić figury geom. z 2 wierzchołków 
    if (otoZew.size() < 3) {
        return false;
    }
    else {
        int right = 0;
        int left = 0;

        for (unsigned int i = 0; i < otoZew.size(); i++) {
            if (pkt.getX() == otoZew[i].getX() && pkt.getY() == otoZew[i].getY()) {
                return true;
            }

            int nextWierz = 0;
            long long x1 = 0, y1 = 0, x2 = 0, y2 = 0;
            x1 = otoZew[i].getX();
            y1 = otoZew[i].getY();

            if (i < otoZew.size() - 1) {
                nextWierz = i + 1;
            }
            else {
                nextWierz = 0;
            }

            x2 = otoZew[nextWierz].getX();
            y2 = otoZew[nextWierz].getY();

            long long check = (pkt.getX() - x1) * (y2 - y1) - (pkt.getY() - y1) * (x2 - x1);
                  
            if (check < 0) {
                left++;
            }
            if (check > 0) {
                right++;
            }

            // Jeżeli znak obu się zmieni, wtedy punkt znajduje się zewnątrz

            if (right > 0 && left > 0) {
                return false;
            }
        }
        // Jeżeli nie ma zmiany kierunku, to znaczy że punkt jest w środku
        return true;
    }

    return true;
}

int main()
{
    int bigLanterns = 0, smallLanterns = 0;
    std::cin >> bigLanterns;

    std::vector<Coords> coordB;
    std::vector<Coords> coordS;
    std::vector<Coords> results;

    // Zaciąganie danych

    for (int i = 0; i < bigLanterns; i++) {
        long long a, b; 
        std::cin >> a >> b;
        Coords C(a, b);
        coordB.push_back(C);
    }

    std::cin >> smallLanterns;

    for (int i = 0; i < smallLanterns; i++) {
        long long a, b;
        std::cin >> a >> b;
        Coords S(a, b);
        coordS.push_back(S);
    }

    // Tworzenie otoczki wypukłej

    graham(coordB, p, results);
    show(results);
    unsigned int rSize = results.size();
    unsigned int pSize = coordS.size();
    int pointsInside = 0;

    // Sprawdzenie ile punktów jest w środku
    for (unsigned int i = 0; i < coordS.size(); ++i) {
        if (isInside(results, coordS[i])) {
            pointsInside++;
        }
    }
    std::cout << pointsInside;
 ////////////////////    Czyszczenie pamięci   ////////////////////
    
    coordB.clear();
    coordS.clear();
    results.clear();

    return 0;
}

Coords::Coords() : x(0), y(0)
{
}

Coords::Coords(long long x, long long y) : x(x), y(y)
{
}

Coords::~Coords()
{
}

long long Coords::getX()
{
    return x;
}

void Coords::setX(long long x)
{
    this->x = x;
}

long long Coords::getY()
{
    return y;
}

void Coords::setY(long long y)
{
    this->y = y;
}

Coords::Coords(const Coords& Kop) : x(Kop.x), y(Kop.y)
{
}

Coords& Coords::operator=(const Coords& R)
{
    this->x = R.x;
    this->y = R.y;
    return *this;
}

bool Coords::operator<(const Coords& f)
{
    long long o = angle(p, *this, f);
    if (o == 0) {
        return (distance(p, f) >= distance(p, *this));
    }
    return (o == 2); 
}
