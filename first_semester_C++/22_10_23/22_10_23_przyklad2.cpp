// Należy wyznaczyć najmniejszą z trzech podanych liczby przez użytkownika

#include <iostream>

using namespace std;

int wyznacz_min(int x, int y, int z)
{
    int min = x;
    if (y  < min)
        min = y;
    if (z < min)
        min = z;
    return min;       
}

int wyznacz_max(int x, int y, int z)
{
    int max = x;
    if (y  > max)
        max = y;
    if (z > max)
        max = z;
    return max; 
}

int main()
{
    int lb1, lb2, lb3;
    int wybur;
    char zakoncz = 'z';

    do // wykonuj
    {
        cout << "Podaj trzy liczby: ";
        cin >> lb1 >> lb2 >> lb3;
    
        cout << "min <1>, max <2>: ";
        cin >> wybur;

        switch (wybur)
        {
        case 1: cout << "Min = " << wyznacz_min(lb1, lb2, lb3);
            break;
        case 2: cout << "Max = " << wyznacz_max(lb1, lb2, lb3); 
            break;
        default: cout << "Zly wybor";
            break;
        }

        cout << "\naby zakonczyc <z>, aby kontynuowac <k>";
        cin >> zakoncz;
    } while (zakoncz != 'z'); // dopuki warunek jest spełniony
}
