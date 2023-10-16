#include <iostream>
#include <iomanip>
#include <cmath> // aby używać matematycznych funkcji takich jak tan() i cos(), które są potrzebne do przeliczenia kąta z stopni na radiany.


using namespace std;

// stałe
const double pi = 3.14; 
const double g = 9.81; // wartość przyspieszenia ziemskiego w m/s^2
// zmienne
double x;
double y_0;
double v_0;
double alpha;
double y;

int main() 
{
    // dane od użytkownika
    cout << "Podaj odleglosc (w metrach): ";
    cin >> x;

    cout << "Podaj wysokosc poczatkowa (w metrach): ";
    cin >> y_0;

    cout << "Podaj kat alfa (w stopniach): ";
    cin >> alpha;

    cout << "Podaj predkosc poczatkowa (w m/s): ";
    cin >> v_0;
    
    // przeliczanie kąta ze stopni na radiany
    double alpha_rad = alpha * pi / 180.0;

    y = x * tan(alpha_rad) - (1.0 / (2.0 * pow(v_0, 2))) * (g * pow(x, 2) / pow(cos(alpha_rad), 2)) + y_0;

    cout << fixed << setprecision(1);
    cout << "Wysokosc po przebyciu " << x << " metrow wynosi " << y << " metrow." << endl;

    cout << "\nNacisnij 'q', aby zakonczyc program...";

    while (true) 
    {
        char key = getchar(); // Oczekuj na pojedynczy znak
        if (key == 'q' || key == 'Q') 
        {
            break; // Wyjście z pętli po naciśnięciu "q" lub "Q"
        }
    }

    return 0;
}