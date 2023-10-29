#include <iostream>
#include <iomanip>

using namespace std;

void przeliczFanC()
{

    float f, c;  
    cout << "Podaje temp. w st. Fahrenheita: ";
    cin >> f;
    if (f > - 459.68)
    {
        c = 5.0 / 9 * (f - 32);
        cout << fixed << setprecision(1);
        cout << f << " F = " << c << " C "; 
    }

    else
    {
        cout << "Na wejsciu temp. ponizej zera bezwzglednefo";
    }
}

void przeliczaCanF()
{

    float c, f;  
    cout << "Podaje temp. w st. Celcjusza: ";
    cin >> c;
    if (f > - 459.68)
    {
        f = c * 9 / 5 + 32; 
        cout << fixed << setprecision(1);
        cout << c << " C = " << f << " F "; 
    }

    else
    {
        cout << "Na wejsciu temp. ponizej zera bezwzglednefo";
    }
}



int main()
{
    int co;
    cout << "F -> C <1>, C -> F <2>: ";
    // cin >> f;
    cin >> co;

    if (co == 1) // == operator porówniania
    {
        
        /*
        cout << "Podaje temp. w st. Fahrenheita: ";
        cin >> f;
        if (f > - 459.68)
        {
            c = 5.0 / 9 * (f - 32);
            cout << f << "F = " << c << " C "; 
        }

        else
        {
        cout << "Na wejsciu temp. ponizej zera bezwzglednefo";
        }
        */
       przeliczFanC();
       
    }

    else if (co == 2)
    {
        przeliczaCanF();
    }
    
    else
    {
        cout << "zly wygbor" << endl;
    }

    return 0;
}