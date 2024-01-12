##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)

###  Two-dimensional arrays.
Two-dimensional arrays in C++ are data structures that store elements in a two-dimensional system, i.e. in the form of a table with two dimensions (rows and columns). Each element in a two-dimensional array is identified by two indexes: the row index (first index) and the column index (second index).

## Task:
Expand the `pp12_02_tablice_dwuwymiarowe_dynamiczne.cpp` 
```
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
```
program with the following functionalities:
• adding matrices stored in two-dimensional arrays;
• matrix multiplication;
• matrix transposition.
The program should check whether the execution of individual tasks is possible due to the number of rows and columns of the matrix.
# [My code:](/first_semester_C++/12_01_24/two_dimensional_arrays.cpp)
```
#include<iostream>

using namespace std;

float **utworz(int n, int m) 
{
    float **t = new float*[n];
    for (int i = 0; i < n; i++) 
    {
        t[i] = new float[m];
    }
    return t;
}

void wpisz(float **t, int n, int m) 
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
        {
            cout << "t[" << i << "][" << j << "] = ";
            cin >> t[i][j];
        }
}

void wypisz(float **t, int n, int m) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }
}

void usun(float **t, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        delete[] t[i];
    }
    delete[] t;
}

bool czyMozliweDodawanie(int n1, int m1, int n2, int m2) 
{
    return (n1 == n2 && m1 == m2);
}

bool czyMozliweMnozenie(int m1, int n2) 
{
    return m1 == n2;
}

float **dodajMacierze(float **A, float **B, int n, int m) 
{
    float **C = utworz(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

float **pomnozMacierze(float **A, int n1, int m1, float **B, int n2, int m2) 
{
    float **C = utworz(n1, m2);
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

float **transponujMacierz(float **A, int n, int m) 
{
    float **C = utworz(m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[j][i];
    return C;
}

int main() 
{
    int n1, m1, n2, m2;
    cout << "Podaj wymiary pierwszej macierzy:\n";
    cout << "liczba wierszy = "; cin >> n1;
    cout << "liczba kolumn = "; cin >> m1;

    float **tab1 = utworz(n1, m1);
    wpisz(tab1, n1, m1);

    cout << "Podaj wymiary drugiej macierzy:\n";
    cout << "liczba wierszy = "; cin >> n2;
    cout << "liczba kolumn = "; cin >> m2;

    float **tab2 = utworz(n2, m2);
    wpisz(tab2, n2, m2);

    if (czyMozliweDodawanie(n1, m1, n2, m2)) 
    {
        cout << "Wynik dodawania:\n";
        float **suma = dodajMacierze(tab1, tab2, n1, m1);
        wypisz(suma, n1, m1);
        usun(suma, n1);
    } else {
        cout << "Nie można dodać macierzy o podanych wymiarach.\n";
    }

    if (czyMozliweMnozenie(m1, n2)) 
    {
        cout << "Wynik mnożenia:\n";
        float **iloczyn = pomnozMacierze(tab1, n1, m1, tab2, n2, m2);
        wypisz(iloczyn, n1, m2);
        usun(iloczyn, n1);
    } 
    else 
    {
        cout << "Nie można pomnożyć macierzy o podanych wymiarach.\n";
    }

    cout << "Wynik transpozycji pierwszej macierzy:\n";
    float **transpozycja = transponujMacierz(tab1, n1, m1);
    wypisz(transpozycja, m1, n1);
    usun(transpozycja, m1);

    usun(tab1, n1);
    usun(tab2, n2);

    return 0;
}
```
### [Oryginal content of task.](/first_semester_C++/12_01_24/pp%20cw10%20tablice%20dwuwymiarowe.pdf)
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)