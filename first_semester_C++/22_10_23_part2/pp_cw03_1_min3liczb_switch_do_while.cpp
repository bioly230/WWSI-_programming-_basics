/*(EF pp)*/
/*
Wyznacznie najmniejszej sposrod trzech liczb
Zastosowanie instrukcji if, switch oraz
instrukcji petli do-while()
*/
#include<iostream>
using namespace std;
double wyznacz_min(double x, double y, double z) {
	double min = x;
	if (y < min)
		min = y;
	if (z < min)
		min = z;
	return min;
}
double wyznacz_max(double x, double y, double z) {
	/*TODO*/  return 0;
}
int main() {
	double lb1, lb2, lb3;
	int co;
	char zakoncz;
	do { //poczatek instrukcji petli do-while: wykonuj
		cout << "\nmin <1>, max <2>:\n";
		cin >> co;
		cout << "\npodaj trzy liczby:\n";
		cin >> lb1 >> lb2 >> lb3;
		switch (co) {  //przelacz w zaleznosci od wartosci co
		case 1:  //w przypadku gdy co jest rowne 1
			cout << "\nmin = " << wyznacz_min(lb1, lb2, lb3);
			break; //przerywa instrukcje switch
		case 2:
			cout << "\nmax = " << wyznacz_max(lb1, lb2, lb3);
			break;
		default:
			cout << "\nzle wybrales";
			break;
		}//koniec switch
		cout << "\n\naby zakonczyc <z>\naby kontynuowac <k>\n";
		cin >> zakoncz;
	} while (zakoncz != 'z');//koniec instrukcji petli: dopoki(warunek jest spelniony)
	//!= operator rozny 
}


//wyniki z kolejnych obrotów petli
//
//min <1>, max <2>:
//1
//
//podaj trzy liczby :
//1 4 2
//
//min = 1
//
//aby zakonczyc <z>
//aby kontynuowac <k>
//k
//
//min <1>, max <2>:
//2
//
//podaj trzy liczby :
//4 6 3
//
//max = 0
//
//aby zakonczyc <z>
//aby kontynuowac <k>
//a
//
//min <1>, max <2>:
//7
//
//podaj trzy liczby :
//3 5 7
//
//zle wybrales
//
//aby zakonczyc <z>
//aby kontynuowac <k>
//z
