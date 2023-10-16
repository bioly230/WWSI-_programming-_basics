# Title: First Laboratories. (10/8/2023)

## Task 1
Write a program to convert a temperature given in Celsius to Fahrenheit using the formula f=9/5c+32. Display the result with a precision of the calculations by comparing the results obtained the program with those obtained using an [online calculator](http://www.onlineconversion.com/temperature.htm). Generate a testing report.

### Let's begin by writing pseudo-code for this task.

```
Pseudo-code is a method for describing algorithms and logical programming concepts in a way that is similar to natural language. It is a human-readable form used for planning and outlining algorithms before their implementation in a specific programming language. Pseudo-code is not a programming language itself but rather a tool for describing algorithmic steps.

Key characteristics of pseudo-code include:

1. Simplicity: Pseudo-code is typically simple to understand and doesn't involve complex syntax or programming language elements.

2. Informality: There is no strict syntax for pseudo-code. You can use natural language and logical diagrams to describe the algorithm.

3. Elaboration: Pseudo-code allows for a detailed description of the algorithm, its steps, and logic, making it helpful for analysis and solution development.

4. Clarity: Good pseudo-code should be clear and understandable to other programmers who may work on the project.

5. Non-Mandatory: Pseudo-code is an optional design tool and is not required to write source code in a particular programming language. It is a helpful tool for the planning phase.
```

1. Start the program.
2. Initialize a variable `celsius` for the temperature in Celsius.
3. Calculate the temperature in Fahrenheit using the formula 
`fahrenheit = (9/5) * celsius + 32`.
4. Display the result `fahrenheit` with a precision of three decimal places.
5. End the program.

### Next, I analyze the code written during the classes.

This program is a calculator. It is used for converting temperature given in degrees Fahrenheit to temperature given in degrees Celsius.

```
//podstawy programowania 08.10/23 CWICZENIA
// c = 5/9(f-32) 

#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    cout << "przeliczanie tremperatury";
    cout << "\npodaj temp. w st. F: ";
    float f;
    cin >> f;
    float c;
    c = 5.0 / 9 * (f - 32);
    cout << fixed << setprecision(2);
    cout << f << " F = " << c << " C";
}
```
![](/first_semester_C++/C++Lab10-8-2023.jpg)

```
/*
Converting from Celsius to Fahrenheit
*/

#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

int main() 
{
    cout << "przeliczanie tremperatury ze stopni Celsiusza na Fahrenhita";
    cout << "\npodaj temp. w st. Celsiusza: ";
    float c;
    cin >> c;
    float f;
    f = 5.0 / 9 * (c + 32);
    cout << fixed << setprecision(2);
    cout << c << " C = " << f << " F";

    getchar();
    return 0;
}
```
![](/first_semester_C++/Converting_from_C_to_F.jpg)

Adding the "Windows.h" library and using the "getchar()" function, I wanted it to wait for closure until the user presses the "ENTER" key. Unfortunately, I made a logical mistake in the application's operation. After opening the application in the window (double-clicking) and confirming the data, the application closes.

### Next verssion:

```
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
```
![](/first_semester_C++/Converting_from_C_to_F_2.jpg)

I decided to edit the code written during the classes. It was enough to change variable names, make adjustments to the mathematical formula, and edit the descriptions. I also added the 'iomanip' library and a 'while' loop from which you can exit by pressing the 'q/Q' key.

After opening the application in the window (by double-clicking), I noticed an issue with Polish characters in the descriptions displayed for the user. I removed the Polish characters from the descriptions shown to the user.

![](/first_semester_C++/Converting_from_C_to_F_2_double-click.jpg)