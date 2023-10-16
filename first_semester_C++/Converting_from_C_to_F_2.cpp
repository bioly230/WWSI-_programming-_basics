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
    f = 5.0 / 9 * (c + 32);
    cout << fixed << setprecision(2);
    cout << c << " C = " << f << " F";

    cout << "\nNaciśnij 'q', aby zakonczyc program...";

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

