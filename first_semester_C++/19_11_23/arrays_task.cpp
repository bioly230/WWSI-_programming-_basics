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