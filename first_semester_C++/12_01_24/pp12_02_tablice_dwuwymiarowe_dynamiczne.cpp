/*EFigielska pp*/
#include<iostream>
using namespace std;
float ** utworz(int n, int m) {
	float ** t = new float*[n];
	for (int i = 0; i < n; i++){
		t[i] = new float[m];
	}
	return t;
}
//
void wpisz(float ** t, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cout << "t[" << i << "][" << j << "] = ";
			cin >> t[i][j];
		}
}
void wypisz(float ** t, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
}

void usun(float ** t, int n) {
	for (int i = 0; i < n; i++) {
		delete [] t[i] ;
	}
	delete [] t;
}

int main() {
	int n, m;
	cout << "liczba wierszy = "; cin >> n;
	cout << "liczba kolumn = "; cin >> m;
	float ** tab = utworz(n, m);
	wpisz(tab, n, m);
	wypisz(tab, n, m);
	usun(tab, n);

}
