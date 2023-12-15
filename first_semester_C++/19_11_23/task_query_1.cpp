#include<iostream>
using namespace std;

void obliczParametryPacjenta(double w, double h, double a, char plec, double &ppm, double &imc, double &d) 
{
    if (a >= 0 && h >= 0 && w >= 0) 
    {
        // Obliczenia ppm, imc i d zgodnie z podanymi wzorami
        if (plec == 'M') {
            ppm = 10 * w + 6.25 * h - 5 * a + 5;
            imc = 50 + 0.9 * (h - 152);
        } 
        else if (plec == 'K') 
        {
            ppm = 10 * w + 6.25 * h - 5 * a - 161;
            imc = 45.5 + 0.9 * (h - 152);
        }

        // Zabezpieczenie przed dzieleniem przez zero
        if (imc != 0) {
            d = w - imc;
        } 
        else 
        {
            // Obsługa błędu dzielenia przez zero, np. ustawienie d na pewną wartość domyślną
            d = 0; // Tutaj możesz ustawić wartość domyślną
        }
    }
}

int main() 
{
    double waga, wzrost, wiek, ppm, imc, odchylenie;

    cout << "Podaj masę pacjenta [kg]: ";
    cin >> waga;

    cout << "Podaj wzrost pacjenta [cm]: ";
    cin >> wzrost;

    cout << "Podaj wiek pacjenta [lata]: ";
    cin >> wiek;

    char plec;
    cout << "Wybierz płeć pacjenta (M/K): ";
    cin >> plec;

    // Wywołaj funkcję, przekazując parametry przez referencję
    obliczParametryPacjenta(waga, wzrost, wiek, plec, ppm, imc, odchylenie);

    // Wyświetl obliczone wartości
    cout << "Wskaźnik podstawowej przemiany materii (ppm): " << ppm << endl;
    cout << "Idealna masa ciała (imc): " << imc << endl;
    cout << "Odstępstwo od idealnej masy (d): " << odchylenie << endl;

    return 0;
}
