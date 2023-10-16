/*
1. Wybierz rodzaj bryły (np. walec).
2. Zdefiniuj zmienne: promień (r), wysokość (h), objętość (V), pole powierzchni całkowitej (A).
3. Wprowadź wartości promienia (r) i wysokości (h) od użytkownika.
4. Oblicz objętość walca (V) używając wzoru: V = pi * r^2 * h.
5. Oblicz pole powierzchni całkowitej walca (A) używając wzoru: A = 2 * pi * r * (r + h).
6. Wyświetl obliczone wartości objętości (V) i pola powierzchni całkowitej (A).
7. Porównaj wyniki z obliczeniami wykonanymi za pomocą kalkulatora lub arkusza kalkulacyjnego.
8. Jeśli wyniki są zgodne, wygeneruj raport testowania i zapisz go.
9. Zakończ program.
*/

#include <iostream>
#include <iomanip>

using namespace std;

const double pi = 3.14; // Przybliżona wartość liczby Pi
double r, h, V, A;

int main() 
{
    cout << "Obliczanie objetosci o pola powierzchni calowitej Walca:" << endl;
    cout << "\nPodaj promien Walca (w cm): ";
    cin >> r;

    cout << "\nPodaj wysokosc Walca (w cm): ";
    cin >> h;

    
    // Obliczanie objętości i pola powierzchni całkowitej walca
    V = pi * r * r * h;
    A = 2 * pi * r * (r + h);

    cout << fixed << setprecision(2);
    cout << "Objetosc = " << V << " cm^3" << endl;
    cout << "Pole powierzchni calkowitej = " << A << " cm^2" << endl;



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

/*
W języku C++ używa się różnych typów zmiennych do przechowywania różnych rodzajów danych. Oto kilka podstawowych typów zmiennych:

1. int: Typ zmiennych całkowitych, używany do przechowywania liczb całkowitych, np. 1, -5, 100.

2. double: Typ zmiennych zmiennoprzecinkowych, używany do przechowywania liczb zmiennoprzecinkowych, np. 3.14, -0.5, 2.0.

3. char: Typ zmiennych znakowych, używany do przechowywania pojedynczych znaków, np. 'a', 'B', '$'.

4. bool: Typ zmiennych logicznych, używany do przechowywania wartości logicznych true (prawda) lub false (fałsz).

5. string: Typ zmiennych tekstowych, używany do przechowywania ciągów znaków, np. "Hello, World!".

6. float: Podobny do double, ale z mniejszą precyzją (mniej cyfr po przecinku).
*/