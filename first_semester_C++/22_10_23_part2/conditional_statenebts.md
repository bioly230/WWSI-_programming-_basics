##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)

# Conditional statements:
<!--
W języku C++, "conditional statements" to instrukcje warunkowe, które pozwalają na wykonywanie różnych bloków kodu w zależności od spełnienia określonych warunków. Istnieją trzy podstawowe instrukcje warunkowe w języku C++:

1. Instrukcja warunkowa "if": Instrukcja ta pozwala na wykonanie bloku kodu tylko wtedy, gdy podany warunek jest spełniony. Jeśli warunek nie jest spełniony, to kod wewnątrz bloku "if" jest pomijany.
2. Instrukcja warunkowa "if-else": Instrukcja ta pozwala na wykonanie jednego bloku kodu, gdy warunek jest spełniony, i innego bloku, gdy warunek nie jest spełniony.
3. Instrukcja warunkowa "if-else if-else": Instrukcja ta pozwala na sprawdzanie wielu warunków sekwencyjnie i wykonanie odpowiedniego bloku kodu na podstawie pierwszego spełnionego warunku.

Te instrukcje warunkowe pozwalają na tworzenie różnych przepływów programu w zależności od warunków, co jest kluczowe w wielu aplikacjach, gdzie zachowanie programu musi reagować na zmienne warunki lub dane wejściowe.
-->
In C++, `conditional statements` are used to execute different blocks of code based on specified conditions. There are three fundamental conditional statements in C++:

1. [if statement:](/first_semester_C++/22_10_23_part2/example_conditional_if.pdf) The `if` statement allows you to execute a block of code only when a specified condition is `true`. If the condition is not met, the code inside the `if` block is skipped.
```
if (condition)
{
    // code block to execute when the condition is "true"
}
```
2. [if-else statement:](/first_semester_C++/22_10_23_part2/example_conditional_if-else.pdf) The `if-else` statement enables you to execute one block of code when a condition is true and another block when the condition is false.
```
if (condition)
{
    // code block to execute when the condition is "true" 
}
else
{
    // code block to execute when the condition is false
}
```
3. [if-else if-else statement:](/first_semester_C++/22_10_23_part2/example_conditional_if-else_if-else.pdf) The `if-else if-else` statement allows you to squentially check multiple conditions and execute the code block associated with the first condition that is true.
```
if (condition1)
{
    // code block when condition1 is "true"
}
else if (condition2)
{
    // code block when condition2 is "true"
}
else
{
    // code block when none of the conditions are true
}
```
These conditional statements are essential for creating different program flows based on conditions, which is crucial in many applications where program needs to respond to changing conditions or input data.


## [Task 1:](/first_semester_C++/22_10_23_part2/22_10_23_przyklad2.cpp)

Complete the ["pp_cw03_1_min3liczb_switch_do_while.cpp"](/first_semester_C++/22_10_23_part2/pp_cw03_1_min3liczb_switch_do_while.cpp) program code with the definition of the determin_max() function. Run and test the program.
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
    int wybor;
    char zakoncz = 'z';

    do // wykonuj
    {
        cout << "Podaj trzy liczby: ";
        cin >> lb1 >> lb2 >> lb3;
    
        cout << "min <1>, max <2>: ";
        cin >> wybor;

        if (wybor == 1)
        {
            cout << "Min = " << wyznacz_min(lb1, lb2, lb3);
        }
        else if (wybor == 2)
        {
            cout << "Max = " << wyznacz_max(lb1, lb2, lb3);
        }
        else
        {
            cout << "W menu nie ma takiego przełącznika!";
        }
        
        cout << "\nAby zakonczyc <z>, aby kontynuowac <k>";
        cin >> zakoncz;
    } while (zakoncz != 'z');
}
```
![](/first_semester_C++/22_10_23_part2/task1.jpg)
## [Task 2:](/first_semester_C++/22_10_23_part2/calculating_the_average.cpp)
Extend the ["pp_cw03_3_wyznaczanie_srednich.cpp"](/first_semester_C++/22_10_23_part2/pp_cw03_3_wyznaczanie_srednich.cpp) program with implementations of functions calculating the average arithmetic and power mean. Carry out program testing.
```
#include<iostream>
#include <cmath>

using namespace std;

double sr_g(double x, double y) 
{
	return sqrt(x * y);
}

double sr_h(double x, double y) 
{
	return 2 * x * y / (x + y);
}

double sr_a(double x, double y)
{
    return (x +y) / 2;
}

double sr_p_k(double x, double y, int k)
{
    return pow(pow(x, y) * pow(y, k), 1.0 / k);
}

int main() 
{
	double liczba1, liczba2, wynik;
	char wybor;
	bool flaga = true;
	cout << "podaj dwie liczby: ";
	cin >> liczba1 >> liczba2;
	cout << "jaka srednia obliczyc?";
	cout << "\n\tg = sr. geometryczna";
	cout << "\n\th = sr. harmoniczna";

    cout << "\n\ta = sr. artmetyczna";
    cout << "\n\tk = sr. potegowa rzedu \"k\"\n";
	cin >> wybor;

	switch (wybor)
	{
	case 'g':wynik = sr_g(liczba1, liczba2); break;
	case 'h':wynik = sr_h(liczba1, liczba2); break;
    case 'a':wynik = sr_a(liczba1, liczba2); break;
    case 'k': 
		int k;
		cout << "Podaj rzad k: ";
		cin >> k;
		wynik = sr_p_k(liczba1, liczba2, k);
		break;
	default: flaga = false;
	}

	if (flaga == false) 
	{
		cout << "niepoprawny wybor sredniej";
	}
	else 
	{
		if (isnan(wynik) || isinf(wynik)) 
		{
			cout << "bledne dane - nie mozna wykonac obliczen";
		}
		else 
		{
			cout << "wynik = " << wynik;
		}
	}
}
```
`pow(pow(x, k) * pow(y, k), 1.0 / k);`
<!--
Ten zapis oblicza średnią potęgową rzędu "k" dwóch liczb "x" i "y". Teraz omówmy go krok po kroku:

1. `pow(x, k)` podnosi liczbę "x" do potęgi "k". W tym przypadku podnosimy "x" do potęgi "k".

2. `pow(y, k)` podnosi liczbę "y" do potęgi "k". W tym przypadku podnosimy "y" do potęgi "k".

3. Następnie obie te wartości są pomnożone: `pow(x, k) * pow(y, k)`.

4. Wynik tego mnożenia jest podniesiony do potęgi odwrotnej do "k", co jest reprezentowane jako `1.0 / k`. Dla przykładu, jeśli "k" wynosi 2, to 1.0/2 to 0.5, co oznacza pierwiastek kwadratowy.

6. Ostatecznie całe wyrażenie jest zwracane jako wynik obliczeń.

Podsumowując, ten zapis wykonuje operacje podnoszenia "x" i "y" do potęgi "k", a następnie oblicza "k"-tą pierwiastek z wyniku mnożenia tych potęg, co jest równoznaczne ze średnią potęgową rzędu "k".
-->
This notation calculates the power mean of order "k" of two numbers "x" and "y". Let's discuss it step by step:

1. `pow(x, k)` raises the number "x: to the power "k". In this case we raise "y" to the power of "k".
2. `pow(y, k)` raises the number "y" to the power "k". In this case we raise "y" to the power of "k".
3. Then both values are multiplied: `pow(x, k) * pow(y, k)`.
4. The result of this multiplication is raised to the inverse power of "k", which is represented as `1.0 / k`. For example, if "k" is 2, then 1.0 / 2 is 0.5, which is the square root.
6. The entire expression is returned as the result of the calculation.

In summary, this notation performs the operations of raising "x" and "y" to the "k" power, and then calculates the "k"th root of the result of multiplying these powers, which is equivalent to a power-law average of order "k".

![](/first_semester_C++/22_10_23_part2/task2.jpg)
## [Task 3:](/first_semester_C++/22_10_23_part2/income_and_taxes.cpp)
According to the block diagram below, write a program that calculates the tax amout for the given income. Carry out program tests.

```
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
        double podatek = 0.19 * dochod - 483.32;
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
```
![](/first_semester_C++/22_10_23_part2/task3.jpg)
The program asks the user for income in a `do-while` loop and calls the calculate tax based on the provided income.
### [Oryginal content of tasks.](/first_semester_C++/22_10_23_part2/pp%20cw03%20instrukcje%20warunkowe.pdf)
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)