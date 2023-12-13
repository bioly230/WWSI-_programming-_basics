#include <iostream>

using namespace std;

int nwd(int a, int b, int& ilosc)
{
    cout << "Wywolanie najwiekszego wspolnego dzielnika dwoch liczb:(" << a << ", " << b << ")" << endl;
    ilosc++;

    if (b == 0)
    {
        cout << "Najwiekszy wspolny dzielnik(" << a << ", " << b << ") = " << a << endl;
        return a;
    }
    else
    {
        return nwd(b, a % b, ilosc);
    }
}

int main()
{
    int ilosc1 = 0, ilosc2 = 0, ilosc3 = 0;

    int wynik1 = nwd(78, 34, ilosc1);
    cout << "Najwiekszy wspolny dzielnik(78, 34) = " << wynik1 << ", Liczba wywolan: " << ilosc1 << endl;

    int wynik2 = nwd(7236485, 40, ilosc2);
    cout << "Najwiekszy wspolny dzielnik(7236485, 40) = " << wynik2 << ", Liczba wywolan: " << ilosc2 << endl;

    int wynik3 = nwd(7250080, 40, ilosc3);
    cout << "Najwiekszy wspolny dzielnik(7250080, 40) = " << wynik3 << ", Liczba wywolan: " << ilosc3 << endl;

    return 0;
}
