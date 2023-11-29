
#include <iostream>

using namespace std;

int zlicz_cyfry(long long a)
{
    int licznik_cyfr = 0; 
    if (a == 0)
    {
        return 1;
    }
    else if (a < 0)
    {
        a = -a;
    }
    else
    {
        licznik_cyfr = 1;
    }
    
    while (a > 0)
    {
        a = a / 10;
        licznik_cyfr++;
    }
    return licznik_cyfr;
}

int main()
{
    long long a;
    cout << "podaj liczbe: ";
    cin >> a;
    
    cout << "ilosc cyfr liczby calkowitej w liczbie " << a << " wynosi: " << zlicz_cyfry(a) << endl;

    return 0;
}
