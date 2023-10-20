#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    cout << "Przeliczanie temperatury z stopni Celsiusza na Fahrenheita";
    cout << "\nPodaj temperature w stopniach Celsiusza: ";
    float c;
    cin >> c;
    float f;
    // f = 9 / 5 * c + 32; błędny wzór
    f = c * 9 / 5 + 32; // poprawny wzór na przeliczenie wybranych jednostek temperatury
    cout << fixed << setprecision(3);
    cout << c << " C = " << f << " F";

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

