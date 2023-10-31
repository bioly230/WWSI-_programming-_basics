#include <iostream>
#include <iomanip>
#include <conio.h> // potrzebne do automatycznego zatrzymania wyboru w MENU
#include <stdint.h> // potrzebne do dzałania funkcji "exit"
#include <cstdlib>


using namespace std;

void przeliczKnaC()
{
    float k, c;
    cout << "Podaj temp. w st. Kelwina: ";
    cin >> k;
    if (k > 0) // temp. w Kelwinach nie może być poniżej 0
    {
        c = k - 273.15;
        cout << fixed << setprecision(2);
        cout << k << " K = " << c << " C ";
    }
    else
    {
        cout << "Blendna temperatura w Kelwinach.";
    }
}

void przeliczCnaK()
{
    float c, k;
    cout << "Podaj temp. w st. Celcjusza: ";
    cin >> c;
    if (c > -273.15)
    {
        k = c + 273.15;
        cout << fixed << setprecision(2);
        cout << c << " C = " << k << " K ";
    }
    else
    {
        cout << "Bledna temp. w Celcjuszach.";
    }
}

void przeliczaCanF()
{
    float c, f;  
    cout << "Podaje temp. w st. Celcjusza: ";
    cin >> c;
    if (c > -273.15)
    {
        f = (c * (9.0 / 5)) + 32; 
        //  °F = (°C * 9/5) + 32
        cout << fixed << setprecision(1);
        cout << c << " C = " << f << " F "; 
    }
    else
    {
        cout << "Bledna temp. w Celcjuszach.";
    }
}

void przeliczFanC()
{
    float f, c;  
    cout << "Podaje temp. w st. Fahrenheita: ";
    cin >> f;
    if (f > -459.67)
    {
        c = (5.0 / 9) * (f - 32); // Dodanioe .0 w dzieleniu powie zmusi C++ do dokonania obliczeń jako wartyości zmiennoprzecinkowej, a nie jako wartości całkowitej.
        // °C = (°F - 32) * 5/9)
        cout << fixed << setprecision(1);
        cout << f << " F = " << c << " C "; 
    }

    else
    {
        cout << "Bledna temp. w Fahrenheita.";
    }
}

void przeliczKnaF()
{
    float k, f;
    cout << "Podaj temp. w st. Kelwina: ";
    cin >> k;
    if (k > 0)
    {
        f = (k - 273.15) * (9.0 / 5) + 32;
        cout << fixed << setprecision(1);
        cout << k << " K = " << f << " F ";
    }
    else
    {
        cout << "Bledna temp. w Kelwinach.";
    }
}

void przeliczFnaK()
{
    float f, k;
    cout << "Podaj temp. w st. Fahrenheita: ";
    cin >> f;
    if (f > -459.67)
    {
        k = ((f - 32) * (5.0 / 9)) + 273.15;
        cout << fixed << setprecision(2);
        cout << f << " F = " << k << " K ";
    }
    else
    {
        cout << "Bledna temp. w Fahrenheita.";
    }
}


int main()
{

    for (;;) // zamknięcie w pustej pentli pozwoli użytkownikowi zdacydować kiedy chce zakończyć prace aplikacji
    {
        char wybor; // typ zmiennej "char" oznacza, że jest to znak z klawiatury
        
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
        wybor = getch(); // funkcja z biblioteki conio.h nie czeka na naciśnięcie klawisza ENTER po dokonaniu wybou w naszym MENU

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
                cout << "Nie ma takiej opcji w MENU!" << endl;
        }
        cout << "\nNacisnij ENTER, aby kontyuowac!";
        /*cin.ignore(); // do oczyszecznia bufora wejści po wczytaniu znaku z klawiatury za pomocą funkcji "getch()"
        system("cls");*/
        cout << endl;
    }
    return 0;
}