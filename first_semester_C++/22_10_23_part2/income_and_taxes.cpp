#include <iostream>

using namespace std;

double dochod;

void oblicz_podatek()
{
    if (dochod >= 74048)
    {
        double podatek = 0.4 * (dochod - 74048);
        cout << "Podatek = " << podatek << endl;
    }
    else if (dochod >= 37024 && dochod < 74048)
    {
        double podatek = 0.3 * (dochod - 37024);
        cout << "Podatek = " << podatek << endl;
    }
    else 
    {
        double podatek = (0.19 * dochod) - 483.32;
        cout << "Podatek = " << podatek << endl;
    }
}

int main()
{
    char zakoncz = 'k';
    cout << "Program sluzy do obliczania podatku po podaniu dochodu." << endl;
    do
    {    
        cout << "\nPodaj dochod: ";
        cin >> dochod;
        oblicz_podatek();

        cout << "\nAby zakonczyc <z>, aby kontynowac <k>";
        cin >> zakoncz;
    } while (zakoncz != 'z');
}