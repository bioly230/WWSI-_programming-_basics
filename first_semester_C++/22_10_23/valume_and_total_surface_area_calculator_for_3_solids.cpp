#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdint.h>
#include <cmath>
#include <cstdlib>

using namespace std;

void pp_objetosc_walca()
{
    const double pi = 3.14; // Przybliżona wartość liczby Pi
    double r, h, V, A;
    cout << "Obliczanie objetosci i pola powierzchni calkowitej Walca:" << endl;
    cout << "\nPodaj promien Walca (w cm): ";
    cin >> r;

    cout << "\nPodaj wysokosc Walca (w cm): ";
    cin >> h;

    if (r && h > 0)
    {
        V = pi * r * r * h;
        A = 2 * pi * r * (r + h);

        cout << fixed << setprecision(2);
        cout << "Objetosc = " << V << " cm^3" << endl;
        cout << "Pole powierzchni calkowitej = " << A << " cm^2" << endl;
    }
    else
    {
        cout << "\nPodane wartości muszą być wartościami dodatnimi różnymi od 0!" << endl;
    }
}
void graniastosłup_prostokatny_o_podstawie_trapezu_rownoramiennego()
{
    double a, b, h, L, S, H, V;

    cout << "Obliczanie objetosci i pola powierzchni calkowitej Graniastoslupa prostokatnego o podstawie trapezu rownoramiennego:" << endl;
    cout << "\nPodaj dlugosc krotszej podstawy trapezu (w cm): " ;
    cin >> a;

    cout << "\nPodaj dlgosc dluzszej podstawy trapezu (w cm): ";
    cin >> b;

    cout << "\nPodaj wysokosc trapezu (w cm): ";
    cin >> h;

    cout << "\nPodaj dlugosc boku graniastoslupa (w cm): ";
    cin >> L;

    cout << "\nPodaj wysokosc graniastoslupa (w cm): ";
    cin >> H;

    if (a && b && h && L && H > 0)
    {
        S = a + b + 2 * sqrt((0.25 * (b - a) * (b - a)) + h * h) + 2 * L; // obliczanie pola powierzchni całkowitej graniastosłuma
        V = (1.0 / 2) * (a + b) * h * H; // obliczanie ojętości

        cout << fixed << setprecision(2);
        cout << "Objetosc = " << V << " cm^3" << endl;
        cout << "Pole powierzchni calkowitej = " << S << " cm^2" << endl;
    }
    else
    {
        cout << "\nPodane wartości muszą być wartościami dodatnimi różnymi od 0!" << endl;
    }
}
void ostrosłup_prosty_o_podstawie_prostokata()
{
    double a, b, h, P, V;

    cout << "Obliczam pole powierzchni calkowitej i objetosc Ostroslupa prostego o podstawie prostokata:" << endl;
    cout << "\nPodaj dlugosc boku a (w cm): ";
    cin >> a;

    cout << "\nPlodaj dlugosc boku b (w cm): ";
    cin >> b;

    cout << "\nPodaj wysokosc graniastoslupa (w cm): ";
    cin >> h;

    if (a && b && h > 0)
    {
        P = 2 * a * b + 2 * a * h + b * h; // obliczanie pola powierzchni
        V = (1.0 / 3) * a * b * h; // obliczanie objętości

        cout << fixed << setprecision(2);
        cout << "Objetosc = " << V << " cm^3" << endl;
        cout << "Pole powierzchni calkowitej = " << P << " cm^2" << endl;
    }
    else
    {
        cout << "\nPodane wartości muszą być wartościami dodatnimi różnymi od 0!" << endl;
    }
    
}

int main() 
{
    for (;;)
    {
        char wybor;

        cout << "Aplikacja sluzy do obliczania pola powierzchni calkowitej i objetosci nastepujacych figur:" << endl;

        cout << "\nMENU GLOWNE:" << endl;
        cout << "################################################################" << endl;
        cout << "1. Walec" << endl;
        cout << "2. Graniastoslup prostokatny o podstawie trapezu rownoramiennego" << endl;
        cout << "3. Ostroslup prostokatny o podstawie prostokata" << endl;
        cout << "4. Koniec programu" << endl;

        cout << endl;
        wybor = getch();

        switch (wybor)
        {
        case '1':
            pp_objetosc_walca();
            break;
        case '2':
            graniastosłup_prostokatny_o_podstawie_trapezu_rownoramiennego();
            break;
        case '3':
            ostrosłup_prosty_o_podstawie_prostokata();
            break;
        case '4':
            exit(0);
            break;
        default:
            cout << "Nie ma takiej opcji w MENU!";
            break;
        }
        getchar(); getchar();
        system("cls");
    }
    return 0;
}
