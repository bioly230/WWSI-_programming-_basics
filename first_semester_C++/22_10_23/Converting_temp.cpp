#include <iostream>
#include <iomanip>


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
    int co;
    cout << "K -> C <1>, C -> K <2>, C -> F <3>, F -> C <4>, K -> F <5>, F -> K <6>";
    
    cin >> co;

    if (co == 1)
    {
        przeliczKnaC();  
    }

    else if (co == 2)
    {
        przeliczCnaK();
    }
    
    else if (co == 3)
    {
        przeliczaCanF();
    }
    
    else if (co == 4)
    {
        przeliczFanC();
    }
    
    else if (co == 5)
    {
        przeliczKnaF();
    }
    
    else if (co == 6)
    {
        przeliczFnaK();
    }
    
    else
    {
        cout << "zly wygbor" << endl;
    }

    return 0;
}