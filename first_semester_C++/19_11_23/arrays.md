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
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)