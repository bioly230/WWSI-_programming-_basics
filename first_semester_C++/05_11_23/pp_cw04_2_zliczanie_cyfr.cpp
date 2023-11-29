//EF PP(lab)
//zliczanie cyfr liczby calkowitej
// 87639 div 10 = 8763    (div = dzielenie calkowite) 
// 8763  div 10 = 876

#include<iostream>
using namespace std;

int zlicz_cyfry(long long a) {
	int licznik_cyfr = 0;
	while (a > 0) {
		a = a / 10; //dzielenie calkowite, bo a i 10 sa calkowite
		licznik_cyfr++;
	}
	return licznik_cyfr;
}

int main() {
	long long a;
	cout << "podaj liczbe: ";
	cin >> a;
	cout << "liczba cyfr w " << a << " = " << zlicz_cyfry(a);
}
