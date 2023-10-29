<!-- komentarz -->
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)

# Functions with elements of conditional instructions:

In C++, "Functions with elements of conditional instructions" refers to functions that contain conditional statements or instructions. Conditional statements allow you to execute different blocks of code based on certain conditions. In C++, the primary conditional statements are:

1. `if Statement:` It's used to execute a block of code if a specified condition is true. If the condition is false, the code inside the `if` block is skipped.
2. `if-else Statement:` It's an extension of the `if` statement. If the condition is true, one block of code is executed; otherwise, another block of code is executed.
3. `switch Statement:` It's used to select one of many code blocks to be executed. It's based on the value of an expression.

### [Temperature conversion:](/first_semester_C++/22_10_23/22_10_23_przyklad1.cpp)
<!--
Na zajęciach został rozwinięty kod z poprzednich zajęć. Została dodana funkcjonalność wyboru przeliczania stopni z Fahrenheita na Celsjusze i na odwrót. Zostało to osiągnięte dzięki dodaniu `procedur: przeliczFnaC i przeliczCnaF`. Są to bloki kodu, które wykonują konkretne operacje lub obliczenia w programie. Dzięki zastosowaniu procedur kod programu jest bardziej czytelny i zrozumiały. Za pomocą `instrukcji warunkowej if` został również wprowadzony mechanizm informujący o błędnych danych podawanych przez użytkownika.
-->
During the classes, the code from previous classes was developed. The functionality of selecting the option to convert degrees from Fahrenheit to Celsius and to vice versa has been added. This was achieved by adding procedures: `przeliczFnaC` and `przeliczCnaF`. These are blocks pf code that perform specific operations or calculations in a program. Thanks to the use of procedures, the program code is more readable and understandable. Using the `conditional if` statemant, a mechanism has also been interoduced to inform about incorrect data provided by the user.
```
#include <iostream>
#include <iomanip>

using namespace std;

void przeliczFanC()
{

    float c, f;  
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
}

void przeliczaCanF()
{

    float c, f;  
    cout << "Podaje temp. w st. Celcjusza: ";
    cin >> c;
    if (f > - 459.68)
    {
        f = c * 9 / 5 + 32; 
        cout << fixed << setprecision(2);
        cout << c << "C = " << f << " F "; 
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
```

![](/first_semester_C++/22_10_23/dvelop_on_class_calculator_temp.jpg)

### [Determining the smallest and largest number:](/first_semester_C++/22_10_23/22_10_23_przyklad2.cpp)
<!--
W celu zaprezentowania instrukcji warunkowej `switch` na zajęciach został napisany kolejny program. Ma on na celu pobrać od użytkownika trzy liczby i zgodnie z wyborem użytkownika wyznaczyć najmniejszą lub największą z nich. Dodatkowo użytkownik ma wpływ na zakończenie lub kontynłowania działania programu.
-->
Another program was written in order to present the `conditional switch` instruction during the classes. Its purose is to collect three numbers from the user and, according to the user's choice, determine the smallest or largest of them. Additionally, the user cam influence the end or continuation of the program.
```
#include <iostream>

using namespace std;

int wyznacz_min(int x, int y, int z)
{
    int min = x;
    if (y  < min)
        min = y;
    if (z < min)
        min = z;
    return min;       
}

int wyznacz_max(int x, int y, int z)
{
    int max = x;
    if (y  > max)
        max = y;
    if (z > max)
        max = z;
    return max; 
}

int main()
{
    int lb1, lb2, lb3;
    int wybur;
    char zakoncz = 'z';

    do // wykonuj
    {
        cout << "Podaj trzy liczby: ";
        cin >> lb1 >> lb2 >> lb3;
    
        cout << "min <1>, max <2>: ";
        cin >> wybur;

        switch (wybur)
        {
        case 1: cout << "Min = " << wyznacz_min(lb1, lb2, lb3);
            break;
        case 2: cout << "Max = " << wyznacz_max(lb1, lb2, lb3); 
            break;
        default: cout << "Zly wybor";
            break;
        }

        cout << "\naby zakonczyc <z>, aby kontynuowac <k>";
        cin >> zakoncz;
    } while (zakoncz != 'z'); // dopuki warunek jest spełniony
}
```
![](/first_semester_C++/22_10_23/determining_the_smallest_and_largest_number.jpg)

## [Task 1:](/first_semester_C++/22_10_23/Converting_temp.cpp)

In the `class_file_name.cpp` program, there is a code completion function called convertCnaF(), which is used to convert temperature from degrees Celsius to degrees Fahrenheit 𝑓 = 9 / 5 * 𝑐 + 32, and it also includes regulations for two other conversions, such as Kelvin to Celsius, and so on. Each conversion operation should be supported by a dedicated function that ensures the correctness of the data collected from the user. You should run and test the program, with testing being an essential part of this task.

```
#include <iostream>
#include <iomanip>


using namespace std;

void przeliczKnaC()
{
    float k, c;
    cout << "Podaj temp. w st. Kelwina: ";
    cin >> k;
    if (k > 0) 
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
    if (f > - 459.67)
    {
        c = (5.0 / 9) * (f - 32); 
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
```
![](/first_semester_C++/22_10_23/converting_temp.jpg)

Poprawność obliczeń wykonywana przez wyżej umieszczony kod została sprawdzona za pomocą [aplikacji online](https://www.digikey.pl/pl/resources/conversion-calculators/conversion-calculator-temperature).
<!--
Następnie zostały sprawdzone parametry bezpieczeństwa.
-->
Then the safety parameters were checked.
![](/first_semester_C++/22_10_23/converting_temp_test_safe_parameters.jpg)

[Code after modification using the "switch statement.](/first_semester_C++/22_10_23/converting_temp_use_switch.cpp)


```
#include <iostream>
#include <iomanip>
#include <conio.h>  
#include <stdint.h> 
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
        c = (5.0 / 9) * (f - 32); 
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

char wybor;

int main()
{

    for (;;)
    {
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
        wybor = getch();

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
        cin.ignore();
        system("cls");
        cout << endl;
    }
    return 0;
}
```
## [Task 2:](/first_semester_C++/22_10_23/valume_and_total_surface_area_calculator_for_3_solids.cpp)

Expand the program from task 2 of the previous execises so that it determines the total surface area and calume 3 solids, and calculations for individual solids should be carried out by 3 different functions (you can also separate functions for calculating the total surface area and volume). Additionally, the program should check the correctness of the entered data (i.e. do not perform calculations if the user will provide negative edge langths). Check the correctness of the obtained results; document the check.

```
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdint.h>

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
        cout << "############" << endl;
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
```

### [Oryginal content of tasks.](/first_semester_C++/22_10_23/pp%20cw02%20funkcje%20+%20elementy%20warunkow%20.pdf)
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)