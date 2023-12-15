/*EFigielska pp*/
/*
funkcje: przekazywanie parametrów przez wskaźnik
*/
#include<iostream>
using namespace std;
bool iloraz_i_reszta(int dzielna, int dzielnik, int* iloraz, int* reszta) {
	if (dzielnik == 0) {
		return false;
	}
	*iloraz = dzielna / dzielnik;
	*reszta = dzielna % dzielnik;
	return true;
}

int main() {
	int a, b;
	cout << "podaj dwie liczby: ";
	cin >> a >> b;
	int wynik_dzielenia = 0, reszta_z_dzielenia = 0;
	bool policzone = iloraz_i_reszta(a, b, &wynik_dzielenia, &reszta_z_dzielenia);
	if (policzone) {
		cout << "iloraz = " << wynik_dzielenia << " reszta = " << reszta_z_dzielenia;
	}
	else {
		cout << "dzielenie przez 0";
	}
}


