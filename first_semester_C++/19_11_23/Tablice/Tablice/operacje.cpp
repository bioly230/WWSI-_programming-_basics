/*EFigielska pp*/
#include "operacje.h"  
#include <random>     
#include<iomanip>
#include<iostream>
using namespace std;

float * utworz_tablice(int &n) {
	cout << "\npodaj n: ";
	cin >> n;
	float *tmp =new float[n];
	return tmp;
}
void wygeneruj_wartosci(float * t, int n, float d, float g) {
	default_random_engine generator(unsigned(time(0)));
	uniform_real_distribution<> losowa(d, g);
	for (int i = 0; i < n; i++)
		t[i] = losowa(generator);
}
void pobierz_wartosci(float * t, int n) {
	cout << "\npodaj " << n << " wartosci: ";
	for (int i = 0; i < n; i++)
		cin >> t[i];
}
void wypisz_tablice(const float * t, int n) {
	cout << "\n";
	for (int i = 0; i < n; i++)
		cout << fixed << setprecision(2) << t[i] << " ";
}
float wyznacz_min(const float * t, int n) {
	//zmienna min przechowuje aktualna najmniejsza wartosc
	float min = t[0];
	for (int i = 1; i < n; i++) {
		if (t[i] < min) { //aktualizacja zmiennej min
			min = t[i]; 
		}
	}
	return min;
}
int znajdz_wartosc(const float * t, int n, float x, float eps){
    //funkcja zwraca index elementu tablicy o wartosci x (z dokladnoscia do eps)
	//lub -1, jezeli x nie wystepuje w tablicy
	for (int i = 0; i < n; i++) {
		if (x - eps <= t[i] && t[i] <= x + eps) { 
			return i; //wartosc szukana zostala znaleziona
		}
	}
	return -1; //wartosc szukana nie zostala znaleziona
}
bool jest_scisle_rosnacy(const float * t, int n) {
	for (int i = 1; i < n; i++) {
		if (t[i - 1] >= t[i]) { 
			return false; //nie jest scisle rosnacy
		}
	}
	return true;  //jest scisle rosnacy
}
bool jest_arytmetyczny(const float * t, int n, float eps) {
	float r = t[1] - t[0];
	for (int i = 2; i < n; i++) {
		if ( t[i] - t[i - 1] < r - eps || r + eps < t[i] - t[i - 1]) {
			return false; //nie jest arytmetyczny
		}
	}
	return true;  //jest arytmetyczny
}
float oblicz_wartosc_wielomianu(const float * t, int n, float x){
	float w = t[0]; //wartosc wielomianu dla argumentu x
	for (int i = 1; i < n; i++) {
		w = w * x + t[i];
	}
	return w;
}
float oblicz_wartosc_wielomianu_rekurencyjnie(const float * t, int n, float x){
	if (n == 0)
		return t[0];
	return x * oblicz_wartosc_wielomianu_rekurencyjnie(t, n - 1, x) + t[n];
}
void posortuj(float * t, int n){
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j > i; j--) {
			if (t[j - 1] > t[j]) {
				float tmp = t[j];  //zamiana miejscami t[j-1] i t[j]
				t[j] = t[j - 1];
				t[j - 1] = tmp;
			}
		}
	}
}

