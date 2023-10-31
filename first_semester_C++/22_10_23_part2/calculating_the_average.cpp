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

double sr_k(double x, double y)
{
    return sqrt((x * y) / 2);
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
    cout << "\n\tk = sr. kwadratowa\n";
	cin >> wybor;

	switch (wybor)
	{
	case 'g':wynik = sr_g(liczba1, liczba2); break;
	case 'h':wynik = sr_h(liczba1, liczba2); break;
    case 'a':wynik = sr_a(liczba1, liczba2); break;
    case 'k':wynik = sr_k(liczba1, liczba2); break;
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
