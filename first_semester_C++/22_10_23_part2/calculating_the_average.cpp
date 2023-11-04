#include<iostream>
#include <cmath>

using namespace std;

double sr_g(double x, double y) 
{
	return sqrt(x * y);
}

double sr_h(double x, double y) 
{
	return 2 * x * y / (x + y);
}

double sr_a(double x, double y)
{
    return (x +y) / 2;
}

double sr_p_k(double x, double y, int k)
{
    return pow(pow(x, k) * pow(y, k), 1.0 / k);
}

int main() 
{
	double liczba1, liczba2, wynik;
	char wybor;
	bool flaga = true;
	cout << "podaj dwie liczby: ";
	cin >> liczba1 >> liczba2;
	cout << "jaka srednia obliczyc?";
	cout << "\n\tg = sr. geometryczna";
	cout << "\n\th = sr. harmoniczna";

    cout << "\n\ta = sr. artmetyczna";
    cout << "\n\tk = sr. potegowa rzedu \"k\"\n";
	cin >> wybor;

	switch (wybor)
	{
	case 'g':wynik = sr_g(liczba1, liczba2); break;
	case 'h':wynik = sr_h(liczba1, liczba2); break;
    case 'a':wynik = sr_a(liczba1, liczba2); break;
    case 'k': 
		int k;
		cout << "Podaj rzad k: ";
		cin >> k;
		wynik = sr_p_k(liczba1, liczba2, k);
		break;
	default: flaga = false;
	}

	if (flaga == false) 
	{
		cout << "niepoprawny wybor sredniej";
	}
	else 
	{
		if (isnan(wynik) || isinf(wynik)) 
		{
			cout << "bledne dane - nie mozna wykonac obliczen";
		}
		else 
		{
			cout << "wynik = " << wynik;
		}
	}
}
