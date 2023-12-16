/*EFigielska pp*/
#include "operacje.h" 
#include<iostream>
using namespace std;
int main() {
	int n = 0;
	float x, eps;
	float * a = utworz_tablice(n);
	wygeneruj_wartosci(a, n);
	//pobierz_wartosci(a, n);
	wypisz_tablice(a, n);
	
	float min = wyznacz_min(a, n);
	cout << "\n\nnajmniejsza wartosc = " << min;
	
	cout << "\n\npodaj wartosc szukana i dokladnosc: "; cin >> x >> eps;
	int indeks = znajdz_wartosc(a, n, x, eps);
	if (indeks < 0) 
		cout << "\nwartosc " << x << " nie wystepuje w tablicy";
	else
		cout << "\nwartosc " << x << " zostala znaleziona na pozycji o indeksie "<<indeks;

	if (jest_scisle_rosnacy(a, n))
		cout << "\n\nciag liczb w tablicy jest scisle rosnacy";
	else
     	cout << "\n\nciag liczb w tablicy nie jest scisle rosnacy";

	if (jest_arytmetyczny(a, n, 0.0001))
		cout << "\nciag liczb jest ciagiem arytmetycznym";
	else
		cout << "\nciag liczb NIE jest ciagiem arytmetycznym";

	cout << "\n\npodaj x: ";
	cin >> x;
	float wartosc_wielomianu = oblicz_wartosc_wielomianu(a, n, x);
	cout << "\nwartosc wielomianu = " << wartosc_wielomianu;
	wartosc_wielomianu = oblicz_wartosc_wielomianu_rekurencyjnie(a, n-1, x);
	cout << "\nwartosc wielomianu = " << wartosc_wielomianu;

	posortuj(a, n);
	cout << "\nciag posortowany: ";
	wypisz_tablice(a, n);

	delete[] a;
}
