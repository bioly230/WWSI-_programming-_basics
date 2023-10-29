
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdint.h>
#include <cstdlib>

using namespace std;

void przeliczKnaC()
{
    // ...
}

void przeliczCnaK()
{
    // ...
}

void przeliczaCanF()
{
    // ...
}

void przeliczFanC()
{
    // ...
}

void przeliczKnaF()
{
    // ...
}

void przeliczFnaK()
{
    // ...
}

char wybor;

int main()
{
    for (;;)
    {
        cout << "MENU GLOWNE:" << endl;
        cout << "------------" << endl;
        cout << "1. Przeliczanie st. Kelwina na st. Celciusze" << endl;
        cout << "2. Przeliczanie st. Celcjusza na st. Kelwina" << endl;
        cout << "3. Przeliczanie st. Celcjusza na st. Fahrenheita" << endl;
        cout << "4. Przeliczanie st. Fahrenhita na st. Celcjusza" << endl;
        cout << "5. Przeliczanie st. Kelwina na st. Fahrenhita" << endl;
        cout << "6. Przeliczanie st. Farenhita na st. Kelwina" << endl;
        cout << "7. Koniec programu" << endl;

        cout << endl;
        wybor = getch();

        switch (wybor)
        {
            case '1':
                przeliczKnaC();
                break;
            case '2':
                przeliczCnaK();
                break;
            case '3':
                przeliczaCanF();
                break;
            case '4':
                przeliczFanC();
                break;
            case '5':
                przeliczKnaF();
                break;
            case '6':
                przeliczFnaK();
                break;
            case '7':
                exit(0);
                break;
            default:
                cout << "Nie ma takiej opcji w MENU!";
        }
        cout << "Naciśnij Enter, aby kontynuować...";
        cin.ignore();
        system("cls");
    }
    return 0;
}
