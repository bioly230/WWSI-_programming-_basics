/*(EF pp)*/
/*
Obliczanie wartosci n!
dla n z zakresu <a,b> podanego przez uzytkownika
*/
#include<iostream>
using namespace std;
long long oblicz_silnie(int n) {
	long long s = 1;
	for (int i = 2; i <= n; i++) {
		s = s * i;
	}
	return s;
}

int main() {
	long long s;
	int n = 0;
	//wyswietlenie wartosci silni dla n z zakresu <a,b> podanego przez uzytkownika  
	int a, b;
	cout << "podaj dla jakiego zakresu n chcesz obliczyc silnie (np. 2 8): ";
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		s = oblicz_silnie(i);
		cout <<"\n"<<((i<10)?" ":"")<< i << "! = " << s;
	}

}