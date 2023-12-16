#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int* utworz_tablice(int & n)
{
    cout << "Podaj liczbe danych: ";
    cin >> n;
    return new int[n]; //utworzenie tablicy w sposób dynamiczny 
}

void wygeneruj_wartosci(int t[], int n)
{
    cout << "\nPodaj zakres generowanych wartosci: ";
    int d, g;
    cin >> d >> g;
    default_random_engine generator(unsigned(time(0))); //generowanie losowe i zainicjowanie go czasem systemowym
    uniform_int_distribution<int> losowa(d, g); //obiekt reprezentuyjący liczby losowe a, g
    for (int i = 0; i < n; i++)
    {
        t[i] = losowa(generator); //przypisanie do t[] wartosci losowej
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
        return false; //ciąg o dł. mniejszej niż 2 nie może być geometryczny
    }

    int iloraz = t[1] / t[0];
    for (int i = 2; i < n; i++)
    {
        if (t[i] != iloraz * t[i -1])
        {
            return false; //ciąg nie jest geometryczny jeżeli warunek nie zostanie spełniony
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
    int n = 0; //liczba danych
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

    delete[] a; //usunięcie tablicy z pamięci      
}


