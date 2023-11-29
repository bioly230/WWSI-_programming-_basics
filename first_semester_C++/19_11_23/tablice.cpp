#include <iostream>

using namespace std;

void wpisz_wartości(float t[], int n)
{
    cout << "podaj " << n << " wartosci: ";
    cin >> n;
    cout << "podaj " << n << " wartosci: ";
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
    /* pierwsza wersja przed rozwinięciem kodu o funkcję "wpisz_wartości"
    cout << "podaj liczbe danych: ";
    cin >> n;
    cout << "podaj " << n << " wartosci: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    */
    cout << "podaj liczbe danych: ";
    cin >> n;
    wpisz_wartości(a, n);

    /*
    cout << "\nwartosci w tablicy: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    */
    /*
    float suma =0;
    for (int i = 0; i < n; i++)
    {
        suma += a[i];
    }
    cout << "\nsuma wartosci = " << suma;
    
    //zliczanie elenentów o wartościach ujemnych
    */
   drukuj_wartosci(a, n);
   cout << "\nsuma wartosci = " << suma_wartosci(a, n);
   /*
   int licznik = 0;
   for (int i = 0; i < n; i++)
   {
    if (a[i] < 0)
    {
        licznik++;
    }
    */
    cout << "\nliczba elementow o wartosciach ujemnych = ";
    cout << zlicz_elementy_o_wartosciach_ujemnych(a, n);
   /*
   cout << "\nliczba elementow o wartosciach ujemnych = " << licznik;
   */
    if (odweoc_wartosci_elementow_o_indeksie_parzystych(a, n))
    {
        drukuj_wartosci(a, n);
    }
    else
    {
        cout << "\nUpss... dzielenie przez 0";
    }

}