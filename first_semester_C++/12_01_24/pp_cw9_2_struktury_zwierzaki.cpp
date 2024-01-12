/*EF pp*/
#include<iostream>
using namespace std;

struct Zwierzak {
	char imie[10] ="";
	char gatunek[5] ="";
	int wiek;
	bool adoptowany = false;
};

Zwierzak wprowadz_dane_nowego_zwierzaka() {
	Zwierzak zwierzak;
	cout << "gatunek (pies/kot): "; cin >> zwierzak.gatunek;
	cout << "wiek: "; cin >> zwierzak.wiek;
	cout << "imie: "; cin >> zwierzak.imie;
	return zwierzak;
}
int zapisz_zwierzaka_w_bazie(const Zwierzak& zwierzak, Zwierzak zwierzaki[], int n) {
	zwierzaki[n] = zwierzak;
	n++;
	return n;
}
void pokaz_zwierzaka(const Zwierzak& zwierzak) {
	cout << zwierzak.imie << ", " << zwierzak.gatunek << ", " << zwierzak.wiek;
}
void pokaz_wszystkie_zwierzaki(const Zwierzak  zwierzaki[], int n) {
	for (int i = 0; i < n; i++) {
		pokaz_zwierzaka(zwierzaki[i]);
		cout << "\n";
	}
}

int main() {
	Zwierzak zwierzaki[100];
	int liczba_zwierzakow = 0;
	char czy_nowy_zwierzak = 'n';
	do {
		Zwierzak nowy_zwierzak = wprowadz_dane_nowego_zwierzaka();
		liczba_zwierzakow = zapisz_zwierzaka_w_bazie(nowy_zwierzak, zwierzaki, liczba_zwierzakow);
		cout << "nowy zwierzak (t/n)? "; 
		cin >> czy_nowy_zwierzak;
	} while (czy_nowy_zwierzak == 't');
	pokaz_wszystkie_zwierzaki(zwierzaki, liczba_zwierzakow);
}

