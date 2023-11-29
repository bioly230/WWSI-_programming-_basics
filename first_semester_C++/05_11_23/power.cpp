#include <iostream>

using namespace std;

double oblicz_potegowanie(double x, int p)
{
    if (p == 0)
    {
        return 1.0;
    }
    else if (p > 0)
    {
        double wynik = 1.0;
        for (int i = 0; i < p; i++)
        {
            wynik *= x;
        }
        return wynik;
    }
    else
    {
        double wynik = 1.0;
        for (int i = 0; i > p; i--)
        {
            wynik /= x;
        }
        return wynik;
    }
}

int main()
{
    double x;
    int p;

    cout << "Podaj liczbe ktora chcesz podniesc do potegi: ";
    cin >> x;
    cout << "Podaj potege: ";
    cin >> p;

    double wynik = oblicz_potegowanie(x, p);

    cout << "Wynik: " << wynik << endl;

    return 0;
}
