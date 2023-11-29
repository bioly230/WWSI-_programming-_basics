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
