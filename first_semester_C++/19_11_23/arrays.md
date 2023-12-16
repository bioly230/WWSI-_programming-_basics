##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)
# Arrays:
<!--
W języku C++, tablice są strukturą danych, która umożliwia przechowywanie wielu elementów tego samego typu w jednym obszarze pamięci. Tablice pozwalają na efektywne zarządzanie danymi, zwłaszcza gdy mamy do czynienia z większą ilością informacji tego samego typu.

Tablice w C++ są definiowane za pomocą następującej składni:

`typ nazwa_tablicy[rozmiar];`

gdzie:

1. typ to typ danych przechowywanych w tablicy,
2. nazwa_tablicy to nazwa tablicy,
3. rozmiar to liczba elementów w tablicy.

Przykład definicji tablicy przechowującej 5 liczb całkowitych:
```
int liczby[5];
```
Tablice w C++ są indeksowane od zera, co oznacza, że pierwszy element tablicy ma indeks 0, drugi element ma indeks 1, itd.
Przykład użycia tablicy:
```
#include <iostream>

int main() {
    int liczby[5] = {1, 2, 3, 4, 5};

    // Wyświetlanie elementów tablicy
    for (int i = 0; i < 5; ++i) {
        std::cout << "liczby[" << i << "] = " << liczby[i] << std::endl;
    }

    return 0;
}
```
W przykładowym kodzie powyżej, liczby to tablica przechowująca pięć liczb całkowitych, które są następnie wyświetlane na ekranie.
-->
In C++, arrays are a fundamental data structure used to store a collection of elements of the same data type. They provide a way to organize and access data in a contiguous memory block. Each element in an array is identified by an index, starting from zero.

Arrays in C++ can be of various types, such as arrays of integers, characters, floating-point numbers, or seven custom data types. They are declared using the following syntax:
```
dataType arrayName[arraySize];
```
Here, dataType specifies the type of elements that the array will hold, arrayName is the name given to the array, and arraySize represents the number of elements in the array.

For example, an array of integers named myArray with a size of 5 would be declared as follows:
```
int myArray[5];
```
Individual elements in the array can be accessed using their indices. The first element is at index 0, the second at index 1, and so on. The syntax for accessing an element is:
```
arrayName[index];
```
Arrays are particularly useful when dealing with a collection of data that can be processed iteratively, such as in loops. They provide an efficient way to manage and manipulate data in a structured manner.

It's worth noting that C++ also supports more advanced features like multidimensional arrays and dynamic arrays using pointers. Additionally, there are standard library containers, such as std::vector, which offer dynamic arrays with additional functionality.
## [Task](/first_semester_C++/19_11_23/arrays_task.cpp)
Write a pogram that:
1. Will create an array with 10 elements of integer type;
2. Assign values to the elements of the array, e.g. by retrieving data from the user;
3. Print the values of the array elements;
4. Count the number of elements with even values;
5. Determine the sum of the values of elements with odd indexes.
#### [Code written in class:](/first_semester_C++/19_11_23/tablice.cpp)
```
#include <iostream>

using namespace std;

void wpisz_wartości(float t[], int n)
{
    cout << "podaj " << n << " wartosci: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
}
void drukuj_wartosci(float t[], int n)
{
    cout << "\nwartosci w tablicy: ";
    for (int i = 0; i < n; i++)
    {
        cout << t[i];
    }
}
float suma_wartosci(float t[], int n)
{
    float suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += t[i];
    }
    
}
bool odweoc_wartosci_elementow_o_indeksie_parzystych(float t[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (t[i] == 0)
        {
            return false;
        }
        t[i] = 1 / t[i];
    }
    return true;
}
int zlicz_elementy_o_wartosciach_ujemnych(float t[], int n)
{
    int licznik = 0;
    for (int i = 0; i < n; i++)
    {
       if (t[i] < 0)
       {
        licznik += t[i];
       }
        
    }
    return licznik;
}

const int N = 100;
int main()
{
    float a[N];
    int n;
    cout << "podaj liczbe danych: ";
    cin >> n;
    wpisz_wartości(a, n);
    drukuj_wartosci(a, n);
    cout << "\nsuma wartosci = " << suma_wartosci(a, n);
    cout << "\nliczba elementow o wartosciach ujemnych = ";
    cout << zlicz_elementy_o_wartosciach_ujemnych(a, n);
    if (odweoc_wartosci_elementow_o_indeksie_parzystych(a, n))
    {
        drukuj_wartosci(a, n);
    }
    else
    {
        cout << "\nUpss... dzielenie przez 0";
    }
}
```
#### Solving the task:
```
#include <iostream>

using namespace std;

void wpisz_wartosci(float t[], int n)
{
    cout << "Podaj " << n << " wartosci: ";
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
}

void drukuj_wartosci(float t[], int n)
{
    cout << "\nWartosci w tablicy: ";
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }
}

int zlicz_elementy_parzyste(int t[], int n)
{
    int licznik = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] % 2 == 0)
        {
            licznik++;
        }
        
    }
    return licznik;
}

int suma_elementow_nieparzystych(int t[], int n)
{
    int suma = 0;
    for (int i = 1; i < n; i += 2)
    {
        suma += t[i];
    }
    return suma;
}

const int N = 10;

int main()
{
    int a[N];
    int n;

    cout << "Podaj liczbe danych (max do 10): ";
    cin >> n;

    if (n > N)
    {
        cout << "Podano zbyt duza liczbe danych!";
        return 1;
    }
    
    wpisz_wartosci(a, n);
    drukuj_wartosci(a, n);

    int liczba_parzystych = zlicz_elementy_parzyste(a, n);
    int suma_nieparzystych = suma_elementow_nieparzystych(a, n);

    cout << "\nLiczba elementow o wartosciach parzystych: " << liczba_parzystych;
    cout << "\nSuma wartosci elementow nieparzystych: " << suma_nieparzystych << endl;

    return 0;
}
```
### [Oryginal content of tasks.](/first_semester_C++/19_11_23/pp%20cw07%20tablice%20wprowadzenie.pdf)

# Algorithms on arrays:
<!--
W języku C++, algorytmy na tablicach odnoszą się do zestawu funkcji i procedur, które umożliwiają przetwarzanie danych w tablicach. Te funkcje są częścią biblioteki standardowej C++, a głównym nagłówkiem, w którym są zdefiniowane, jest `<algorithm>`. Biblioteka ta dostarcza gotowych algorytmów, które można używać do różnych operacji na kontenerach, takich jak tablice, wektory czy listy.

Przykładowe algorytmy dostępne w bibliotece <algorithm> obejmują:
1. `sort()` służy do sortowania elementów w określonym zakresie.
```
#include <algorithm>
#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> numbers = {5, 2, 8, 1, 7};
    std::sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```
2. `find()` znajduje pierwsze wystąpienie określonego elementu w danym zakresie.
```
#include <algorithm>
#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> numbers = {5, 2, 8, 1, 7};
    auto it = std::find(numbers.begin(), numbers.end(), 8);

    if (it != numbers.end()) 
    {
        std::cout << "Element found at index: " << std::distance(numbers.begin(), it);
    } else {
        std::cout << "Element not found";
    }

    return 0;
}
```
3. `accumulate()` sumuj e elementy w danym zakresie.
```
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

int main() 
{
    std::vector<int> numbers = {5, 2, 8, 1, 7};
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "Sum: " << sum;

    return 0;
}
```
4. `for_each()` wykonuje określoną operację dla każdego elementu w zakresie.
```
#include <algorithm>
#include <iostream>
#include <vector>

void printSquare(int x) 
{
    std::cout << x * x << " ";
}

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 7};
    std::for_each(numbers.begin(), numbers.end(), printSquare);

    return 0;
}
```
Te są tylko przykłady; biblioteka <algorithm> dostarcza szereg innych algorytmów, które ułatwiają operacje na danych w tablicach i innych kontenerach. Algorytmy te są często wydajne i ogólnie zalecane ze względu na ich gotowość, czytelność i możliwość wielokrotnego użycia.
-->
In C++, array algorithms refer to a set of functions and procedures that enable processing data in arrays. These functions are part of the C++ Standard Library, and the main header in which they are defined is `<algorithm>`. This library provides ready-made algorithms that can be used for various operations on containers, such as arrays, vectors and lists.

Sample algorithms available in the <algorithm> library include:
1. `sort()` is used to sort elements within a specified range.
```
#include <algorithm>
#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> numbers = {5, 2, 8, 1, 7};
    std::sort(numbers.begin(), numbers.end());

    for (int num : numbers) {
        std::cout << num << " ";
    }

    return 0;
}
```
2. `find()` finds the first occurrence of a specified element in a given range.
```
#include <algorithm>
#include <iostream>
#include <vector>

int main() 
{
    std::vector<int> numbers = {5, 2, 8, 1, 7};
    auto it = std::find(numbers.begin(), numbers.end(), 8);

    if (it != numbers.end()) 
    {
        std::cout << "Element found at index: " << std::distance(numbers.begin(), it);
    } else {
        std::cout << "Element not found";
    }

    return 0;
}
```
3. `accumulate()` sums the elements in a given range.
```
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

int main() 
{
    std::vector<int> numbers = {5, 2, 8, 1, 7};
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    std::cout << "Sum: " << sum;

    return 0;
}
```
4. `for_each()` performs the specified operation for each element in the range.
```
#include <algorithm>
#include <iostream>
#include <vector>

void printSquare(int x) 
{
    std::cout << x * x << " ";
}

int main() {
    std::vector<int> numbers = {5, 2, 8, 1, 7};
    std::for_each(numbers.begin(), numbers.end(), printSquare);

    return 0;
}
```
These are just examples; the <algorithm> library provides a number of other algorithms that facilitate operations on data in arrays and other containers. These algorithms are often efficient and generally recommended due to their readiness, readability, and reusability.
## [Task](/first_semester_C++/19_11_23/analiza_tablicy.cpp)
Based on the program [pp_cw08_algorytmy_na_tablicach.cpp](/first_semester_C++/19_11_23/pp%20cw08%20algorytmy%20na%20tablicach.pdf)
`operacje.cpp`:
```
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
``` 
`przyklad.cpp`:
```
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
```
and the project from the lecture materials [pp10_tablice](/first_semester_C++/19_11_23/Tablice/Tablice.sln)
```
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
```
`operacje.h`:
```
/*EFigielska pp*/
#pragma once
//dla tablic o elementach rzeczywistych
float * utworz_tablice(int &n);
void wygeneruj_wartosci(float *t, int n, float d = 0, float g = 10);
void pobierz_wartosci(float *t, int);
void wypisz_tablice(const float *t, int n);
float wyznacz_min(const float *t, int n);
int znajdz_wartosc(const float * t, int n, float x, float eps);
bool jest_scisle_rosnacy(const float *t, int n);
bool jest_arytmetyczny(const float *t, int n, float eps);
float oblicz_wartosc_wielomianu(const float* t, int n, float x);
float oblicz_wartosc_wielomianu_rekurencyjnie(const float* t, int n, float x);
void posortuj(float* t, int n);
```
write a program with the following functionality:
1. Creating an array of the size provided by the user, containing integer elements;
2. Entering data values ​​into the array:

    a) Randomly generated;

    b) Entered from the keyboard;
3. Displaying the values ​​in the array;
4. Finding the largest value in a sequence of numbers stored in an array;
5. Checking whether subsequent elements of the array form a strictly descending sequence;
6. Checking whether subsequent elements of the array form a geometric sequence;
7. Finding the first element in an array with a value divisible by the number entered by the user –
this function is to pass outside (to the main function) information about the value and position of such an element or
information that such an element is not in the array (tip: pass one of the results as a parameter via
reference).

Each functionality should be implemented in a separate function. Most functions should accept
an array as a parameter and pass the result(s) of your operation to the main function as a return value.
```
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int* utworz_tablice(int & n)
{
    cout << "Podaj liczbe danych: ";
    cin >> n;
    return new int[n];  
}

void wygeneruj_wartosci(int t[], int n)
{
    cout << "\nPodaj zakres generowanych wartosci: ";
    int d, g;
    cin >> d >> g;
    default_random_engine generator(unsigned(time(0)));
    uniform_int_distribution<int> losowa(d, g); 
    for (int i = 0; i < n; i++)
    {
        t[i] = losowa(generator);
    }
}

void wpisz_wartosci(int t[], int n)
{
    cout << "\nWartosci tablicy: ";
    for (int i = 0; i < n ; i++)
    {
        cin >> t[i];
    }
}

void drukuj_wartosci(const int t[], int n)
{
    cout << "\nWartosci w tablicy: ";
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }
}

int znajdz_najwieksza_wartosc(const int t[], int n)
{
    int max = t[0];
    for (int i = 0; i < n; i++)
    {
        if (t[i] > max)
        {
            max = t[i];
        }
    }
    return max;
}

bool jest_geometryczny(const int t[], int n)
{
    if (n < 2)
    {
        return false;
    }

    int iloraz = t[1] / t[0];
    for (int i = 2; i < n; i++)
    {
        if (t[i] != iloraz * t[i -1])
        {
            return false;
        } 
    }
    return true;
}

bool znajdz_podzielna(const int t[], int n, int k, int & wartosc, int & indeks)
{
    for (int i = 0; i < n; i++)
    {
        if (t[i] % k == 0)
        {
            wartosc = t[i];
            indeks = i;
            return true;
        }
    }
    return false;
}


int main()
{
    int n = 0;
    int * a = utworz_tablice(n);
    int wybor = 0;
    int k, wartosc, indeks;

    cout << "Generowanie wartosci: losowo <1>, wprowadz dane <0>: ";
    cin >> wybor;

    if (wybor)
    {
        wygeneruj_wartosci(a, n);
    }
    else
    {
        wpisz_wartosci(a, n);
    }

    drukuj_wartosci(a, n);

    int maksimum = znajdz_najwieksza_wartosc(a, n);
    cout << "\n\nNajwieksza wartosc: " << maksimum;

    if (jest_geometryczny(a, n))
    {
        cout << "\nCiag jest malejacy.";
    }
    else
    {
        cout << "\nCiag NIE jest malejacy.";
    }

    if (znajdz_podzielna(a, n, k, wartosc, indeks))
    {
        cout << "\nPierwszy element podzielny przez " << k << " to " << wartosc << " na pozycji " << indeks;
    }
    else
    {
        cout << "\nBrak elementu podzielnego przez " << k << " w tablicy";
    } 

    delete[] a;    
}
```
The program consists of several functions, each of which is responsible for one of the functionalities defined in the command. It is worth noting that the `znajdz_podzielna` function passes results by reference (`wartosc` and `indeks`). The program loads the cardinality of the array and then allows the user to choose whether they want to enter the data from the keyboard or generate it randomly. At the end, the program prints the results of the analyzes performed.
### [Oryginal content of task.](/first_semester_C++/19_11_23/pp%20cw08%20algorytmy%20na%20tablicach.pdf)
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)