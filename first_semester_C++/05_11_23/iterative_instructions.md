##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)

# Input/output instructions instructions:
<!--

-->
## [Task 1:](/first_semester_C++/05_11_23/factorial_calculation.cpp)
<!--
Zmodyfikować funkcję oblicz_silnie() (program pp_cw04_1_silnia.cpp)tak, aby zwracała:
• wartość 𝑛! ,jeżeli 0 ≤ 𝑛 ≤ 20
• wartość -1, jeżeli 𝑛 < 0;
• wartość -2, jeżeli 𝑛 > 20;
A więc funkcja oblicz_silnie() ma być sama odpowiedzialna za swoje działania w zależności od przekazanej do niej 
wartości parametru 𝑛 .
Wywołać funkcję oblicz_silnie() w funkcji main() wykorzystując wartość przez nią zwracaną w następujący sposób:
s = oblicz_silnie(n);
if(s == -1) //jeżeli nie wykonano obliczeń z powodu ujemnej wartosci n
//TODO: wyświetl komunikat o ujemnej wartości n
else if(s == -2) //jeżeli nie wykonano obliczeń z powodu za dużej wartosci n
//TODO: wyświetl komunikat o za dużej wartości n
else //w pozostałych przypadkach (tzn. jeżeli obliczenia zostały wykonane)
//TODO: wyświetl wartość n!
-->
<!--
kod napisany na zajęciach:
-->
```
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
```
```
#include <iostream>

using namespace std;

long long silnia(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n > 20)
    {
        return -2;
    }
    else
    {
        long long s = 1;
        for (int i = 2; i <= n; i++)
        {
            s *= i;
        }
        return s;
    }
}

int main()
{
    int n, m;
    cout << "podaj zakresu 0 - 20: ";
    cin >> n >> m;

    for (int i = n; i <= m; i++)
    {
        long long s = silnia(i);

        if (s == -1)
        {
            cout << "Silnia z licznika " << i << " nie jest zdafiniowana dla liczb ujemnych!" << endl;
        }
        else if (s == -2)
        {
            cout << "Silnia z licznika " << i << " jest zbyt duza, aby ja obliczyc!" << endl;
        }
        else
        {
            cout << (i < 10?" ":"") << i << "! = " << s << endl;
        }
    }
    return 0;
}
```
## [Task 2:]()
## [Task 3:]()
## [Task 4:]()
## [Task 5:]()
### [Oryginal content of tasks.](/first_semester_C++/05_11_23/pp%20cw04%20instrukcje%20iteracyjne.pdf)
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)