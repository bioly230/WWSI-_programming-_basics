# Title: First Laboratories. (10/8/2023)

## [Task 1](/first_semester_C++/Converting_from_C_to_F_2.cpp)

Write a program to convert a temperature given in Celsius to Fahrenheit using the formula f=9/5c+32. Show the result accurate to the third decimal place and compare it with those obtained by using the [online calculator](http://www.onlineconversion.com/temperature.htm). Generate a testing report.

### Let's begin by writing pseudo-code for this task.

```
Pseudo-code is a method to describe algorithms and logical programming concepts in a way that is similar to natural language. It is a human-readable form used for planning and outlining algorithms before their implementation in a specific programming language. Pseudo-code is not a programming language itself but rather a tool for describing algorithmic steps.

Key characteristics of pseudo-code include:

1. Simplicity: Pseudo-code is usually simple to understand and doesn't involve complex syntax or programming language elements.

2. Informality: There is no strict syntax for pseudo-code. You can use natural language and logical diagrams to describe the algorithm.

3. Elaboration: Pseudo-code allows for a detailed description of the algorithm, its steps, and logic, making it helpful for analysis and solution development.

4. Clarity: Good pseudo-code should be clear and understandable to other programmers who may work on the project.

5. Non-Mandatory: Pseudo-code is an optional design tool and is not required to beable to write source code. It is a helpful tool for the planning phase.
```

1. Start the program.
2. Initialize a variable `celsius` for the temperature in Celsius.
3. Calculate the temperature in Fahrenheit using the formula 
`fahrenheit = (9/5) * celsius + 32`.
4. Display the result `fahrenheit` with a precision of three decimal places.
5. End the program.

### Next, I analyze the code written during the classes.

This program is a calculator. It is used for converting temperature given in Fahrenheit to temperature given in Celsius.

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
    cout << fixed << setprecision(3);
    cout << c << " C = " << f << " F";

    getchar();
    return 0;
}
```
![](/first_semester_C++/Converting_from_C_to_F.jpg)


While adding the "Windows.h" library and using the "getchar()" function, the programme is expected to wait until the user presses the "ENTER" key. Due to an incorrect assumption of the eneter key function (twofold function), the programme cloes itself automatically in this closes.

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
```
![](/first_semester_C++/Converting_from_C_to_F_2.jpg)


It was decided to change the code written during the classes. It was enough to change variable names, make adjustments to the mathematical formula, and edit the descriptions. It whas also added the 'iomanip' library and a 'while' loop from which the user can exit by pressing the 'q/Q' key.

After opening the application in the window (by double-clicking), It was noticed that there was an issue with Polish characters in the descriptions shown to the user. the characters were removed.

![](/first_semester_C++/Converting_from_C_to_F_2_double-click.jpg)

### Checking the results in an online calculator

![](/first_semester_C++/Converting_from_C_to_F_2_verification.png)


## [Task 2](/first_semester_C++/calculating_the_volume_of_the_cylinder_area.cpp)

Write a program to calculate the volume and total surface area of a selected geometric solid, such as a right triangular prism, a right triangular pyramid, or a cylinder. Determine which parameters of the solid will be provided by the user and which ones will be calculated as auxiliary values. 

Verify the correctness of the calculations by comparing the results obtained through the program with those obtained using a calculator or spreadsheet. Generate a testing report.

### Pseudo-code for this task.

1. Choose the type of geometric solid (e.g., cylinder).
2. Define variables: radius (r), height (h), volume (V), total surface area (A).
3. Input values for radius (r) and height (h) from the user.
4. Calculate the volume of the cylinder (V) using the formula: V = pi * r^2 * h.
5. Calculate the total surface area of the cylinder (A) using the formula: A = 2 * pi * r * (r + h).
6. Display the calculated values of volume (V) and total surface area (A).
7. Compare the results with calculations performed using a calculator or spreadsheet.
8. If the results match, generate a testing report and save it.
9. End the program.

### Common Variables in C++

In C++, various variable types are used to store different types of data. Here are some basic variable types explained in simple terms:

1. int: An integer variable type used to store whole numbers, e.g., 1, -5, 100.
2. double: A floating-point variable type used to store decimal numbers, e.g., 3.14, -0.5, 2.0.
3. char: A character variable type used to store single characters, e.g., 'a', 'B', '$'.
4. bool: A boolean variable type used to store logical values, true (true) or false (false).
5. string: A string variable type used to store sequences of characters, e.g., "Hello, World!".
5. float: Similar to double, but with less precision (fewer decimal places).

These types allow programmers to store and manipulate different kinds of data depending on the program's requirements. For example, if you want to store a person's age, you would use int, and if you want to store a floating-point value like average temperature, you would use double or float.

### I analyze the code written during the task 1

```
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
```
In my application, I'm using the "double" and a "const double" variables. 

![](/first_semester_C++/calculating_the_volume_of_the_cylinder_area.jpg)

![](/first_semester_C++/calculating_the_volume_of_the_cylinder_area_double-click.jpg)


## [Task 3](/first_semester_C++/Projectile_height_calculator.cpp)

We throw a ball with an initial velocity v_0 at an angle ∝ relative to the horizontal from the point (x=0, y=y_0). The ball's trajectory is a parabola (neglecting air resistance) given by the following equation:

y = x∙tan(α) - (1/2v_0^2) * (g*x^2)/cos^2(α) + y_0

You need to write a program that calculates the value of y for user-provided values of x, y_0, v_0, and ∝. Perform the calculations with one decimal place of precision. Verify the correctness of the calculations.

Variables:

y: the height of the ball after traveling a horizontal distance x.
y_0: the initial height from which the ball is thrown, provided in meters.
v_0: the initial velocity, provided in km/h (requires conversion to m/s; 1 km/h = 1000 m/3600 s).
∝: the angle in degrees (requires conversion to radians; α[rad]=α^o π/180^o).
g: 9.81 m/s², the gravitational acceleration, declared as a constant.
Mathematical functions for calculating tan(α): tan(α) and cos(α): cos(α).
Your program should take the user's input for x, y_0, v_0, and ∝, convert the units, perform the calculation, and display the result with one decimal place of precision.

### Pseudo-code for this task:

1. Declare and initialize the constants:
    g = 9.81 m/s²
2. Prompt the user for input:
    Enter the value for x (horizontal distance): x_input
    Enter the initial height (y_0) in meters: y_0_input
    Enter the initial velocity in km/h: v_0_input
    Enter the angle in degrees: angle_degrees
3. Convert user inputs to suitable units:
    Convert v_0_input from km/h to m/s: v_0_mps = v_0_input * (1000 m/3600 s)
    Convert angle_degrees to radians: angle_radians = angle_degrees * π/180
4. Calculate the height y using the provided formula:
    Calculate x_term = x_input * tan(angle_radians)
    Calculate y_term = (1/(2 * v_0_mps^2)) * (g * x_input^2)/(cos(angle_radians))^2
    Calculate y = x_term - y_term + y_0_input
5. Display the result:
    Print "The height of the ball at x =", x_input, "is y =", y, "meters."
6. End the program.

### Editing the code from the previous task:

```
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
```

During the modification of the code written for the last task, I added the "cmath" library. This library enables the use of more advanced mathematical functions in C++. For example, it allows the use of mathematical functions like tan() and cos().

![](/first_semester_C++/Projectile_height_calculator.jpg)

![](/first_semester_C++/Projectile_height_calculator_double-click.jpg)

### [Oryginal content of tasks](/first_semester_C++/pp%20cw01%20wyrazenia%20arytmetyczne.pdf)

