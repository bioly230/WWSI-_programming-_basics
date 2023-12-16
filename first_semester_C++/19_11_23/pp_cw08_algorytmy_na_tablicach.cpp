#include<iostream>
#include<random>
#include<ctime>
using namespace std;
float* utworz_tablice(int & n) {
	cout << "podaj liczbe danych: ";
	cin >> n;
	return new float[n]; //utworzenie tablicy w sposob dynamiczny - rozmiar dopasowany do potrzeb
}
void wygeneruj_wartosci(float t[],int n) {
	cout << "\npodaj zakres generowanych wartosci: ";
	float d, g;
	cin >> d >> g;
	default_random_engine generator(unsigned(time(0)));//utworzenie obiektu generatora i zainicjalizowanie go czasem systemowym
	uniform_real_distribution<float> losowa(d, g); //utworzenie obiektu reprezentujacego liczbe losowa z zakresu <d, g>
	for (int i = 0; i < n; i++) {
		t[i] = losowa(generator); //przypisanie elementowi t[i] wartosci losowej 
	}
}
float znajdz_najmniejsza_wartosc(const float t[], int n) {
	float min = t[0];
	for (int i = 1; i < n; i++) {
		if (t[i] < min) {
			min = t[i];
		}
	}
	return min;
}
bool jest_rosnacy(const float t[], int n) {
	for (int i = 1; i < n; i++) {
		if (t[i - 1] >= t[i]) { //warunek spelniony -> ciag nie jest scisle rosnacy
			return false;
		}
	}
	return true;
}
void wpisz_wartosci(float t[], int n) {
	cout << "podaj " << n << " wartosci danych: ";
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
}
void drukuj_wartosci(const float t[], int n) {
	cout << "\nwartosci w tablicy: ";
	for (int i = 0; i < n; i++) {
		cout << t[i] << " ";
	}
}

int main() {
	int n = 0; //liczba danych
	float* a = utworz_tablice(n);
	int wybor = 0;
	cout << "generowanie wartosci: losowo <1>, z klawiatury <0>: ";
	cin >> wybor;
	if (wybor) {
		wygeneruj_wartosci(a, n);
	}
	else {
		wpisz_wartosci(a, n);
	}
	drukuj_wartosci(a, n);
	cout << "\nnajmniejsza wartosc = " << znajdz_najmniejsza_wartosc(a, n);
	if (jest_rosnacy(a, n)) {
		cout << "\nciag jest scisle rosnacy";
	}
	else {
		cout << "\nciag NIE jest scisle rosnacy";
	}
	delete [] a; //usunięcie tablicy z pamięci 
}