#include <iostream>
#include <cmath>

using namespace std;

double oblicz_pierwiastek(double x, double epsilon)
{
    double w = 1;

    while (pow(w, 2) - x >= epsilon)
    {
        w = (x / w + w) / 2;
    }

    return w;
}

int main()
{
    double x;
    cout << "Podaj liczbe: ";
    cin >> x;

    double epsilon_values[] = {0.1, 0.01, 0.001, 0.0001};

    for (double epsilon : epsilon_values)
    {
        double wynik = oblicz_pierwiastek(x, epsilon);

        cout << "Dla epsilon = " << epsilon << ": ";
        cout << "Wynik = " << wynik << ", ";
        cout << "Ilosc iteracji = " << static_cast<int>((log(1 / epsilon) / log(2))) + 1 << endl;
    }

    return 0;
}
