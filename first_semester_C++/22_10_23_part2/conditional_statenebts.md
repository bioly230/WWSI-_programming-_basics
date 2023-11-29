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
    return pow(pow(x, k) * pow(y, k), 1.0 / k);
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

## Third class (11.05.2023):
## [Task 1:](/first_semester_C++/05_11_23/calculate_strong.cpp)
<!--
Zmodyfikować funkcję oblicz_silnie() (program pp_cw04_1_silnia.cpp)tak, aby zwracała:
• wartość 𝑛! ,jeżeli 0 ≤ 𝑛 ≤ 20
• wartość -1, jeżeli 𝑛 < 0;
• wartość -2, jeżeli 𝑛 > 20;
A więc funkcja oblicz_silnie() ma być sama odpowiedzialna za swoje działania w zależności od przekazanej do niej 
wartości parametru 𝑛 .
Wywołać funkcję oblicz_silnie() w funkcji main() wykorzystując wartość przez nią zwracaną w następujący sposób:
s = oblicz_silnie(n);
if(s == -1) //jeżeli nie wykonano obliczeń z powodu ujemnej wartosci n
//TODO: wyświetl komunikat o ujemnej wartości n
else if(s == -2) //jeżeli nie wykonano obliczeń z powodu za dużej wartosci n
//TODO: wyświetl komunikat o za dużej wartości n
else //w pozostałych przypadkach (tzn. jeżeli obliczenia zostały wykonane)
//TODO: wyświetl wartość n!
-->
Modify the calculate_factoria() function (program [pp_cw04_1_silnia.cpp](/first_semester_C++/05_11_23/pp_cw04_1_silnia.cpp)) so that it returns:
1. value of m! if 0 ≤ 𝑛 ≤ 20
2. value -1 if < 0;
3. value -2 if 𝑛 > 20;

So the calculate_strong() function is to be responsible for its own actions depending on the information passed to it parameter values 𝑛. Call the calculate_strong() function in the main() function using its return value as follows:

`calculate_strong(n);
if (s == -1) //if no calculated was performed due to a negative n value
//TODO: display message about negative n value
else //in other cases (i.e. if the calculations have been performed)
//TODO: display the value of n!`
<!--
kod napisany na zajęciach:
-->

Code written in class:
```
Obliczanie wartosci n!
dla n z zakresu <a,b> podanego przez uzytkownika
*/
#include<iostream>
using namespace std;
long long oblicz_silnie(int n) {
	long long s = 1;
	for (int i = 2; i <= n; i++) {
		s = s * i;
	}
	return s;
}

int main() {
	long long s;
	int n = 0;
	//wyswietlenie wartosci silni dla n z zakresu <a,b> podanego przez uzytkownika  
	int a, b;
	cout << "podaj dla jakiego zakresu n chcesz obliczyc silnie (np. 2 8): ";
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		s = oblicz_silnie(i);
		cout <<"\n"<<((i<10)?" ":"")<< i << "! = " << s;
	}

}
```
Solving the task:
```
#include <iostream>

using namespace std;

long long silnia(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n > 20)
    {
        return -2;
    }
    else
    {
        long long s = 1;
        for (int i = 2; i <= n; i++)
        {
            s *= i;
        }
        return s;
    }
}

int main()
{
    int n, m;
    cout << "podaj zakresu 0 - 20: ";
    cin >> n >> m;

    for (int i = n; i <= m; i++)
    {
        long long s = silnia(i);

        if (s == -1)
        {
            cout << "Silnia z licznika " << i << " nie jest zdafiniowana dla liczb ujemnych!" << endl;
        }
        else if (s == -2)
        {
            cout << "Silnia z licznika " << i << " jest zbyt duza, aby ja obliczyc!" << endl;
        }
        else
        {
            cout << (i < 10?" ":"") << i << "! = " << s << endl;
        }
    }
    return 0;
}
```
![](/first_semester_C++/05_11_23/calculate_strong.jpg)

## [Task 2:](/first_semester_C++/05_11_23/5-11-23_petla_wihile.cpp)
Extend the `zalicz_cyfry(a)` function (example 3 of lecture PP05, program [pp_cw04_2_zliczanie_cyfr.cpp](/first_semester_C++/05_11_23/pp_cw04_2_zliczanie_cyfr.cpp)) determinig the number of digits integer a so that it works according to the block diagram below.

![](/first_semester_C++/05_11_23/block_diagram_task2.jpg)

Comments:

1. the div operation in the flowchart means integer division;
2. a number with the value 0 consists of one digit;
3. a negative number, e.g. -7624 consists of four digits (we only count the digits, we forget about the sign).

Code written in class:
```
#include<iostream>
using namespace std;

int zlicz_cyfry(long long a) {
	int licznik_cyfr = 0;
	while (a > 0) {
		a = a / 10;
		licznik_cyfr++;
	}
	return licznik_cyfr;
}

int main() {
	long long a;
	cout << "podaj liczbe: ";
	cin >> a;
	cout << "liczba cyfr w " << a << " = " << zlicz_cyfry(a);
}
```
Solving the task:
```
#include <iostream>

using namespace std;

int zlicz_cyfry(long long a)
{
    int licznik_cyfr = 0; 
    if (a == 0)
    {
        return 1;
    }
    else if (a < 0)
    {
        a = -a;
    }
    else
    {
        licznik_cyfr = 1;
    }
    
    while (a > 0)
    {
        a = a / 10;
        licznik_cyfr++;
    }
    return licznik_cyfr;
}

int main()
{
    long long a;
    cout << "podaj liczbe: ";
    cin >> a;
    
    cout << "ilosc cyfr liczby calkowitej w liczbie " << a << " wynosi: " << zlicz_cyfry(a) << endl;

    return 0;
}
```
![](/first_semester_C++/05_11_23/task2.jpg)
## [Task 3:](/first_semester_C++/05_11_23/calculate_the_square_root.cpp)
Write a function calculate_root(x,ε) that calculates and returns the value of the square root of x according to
algorithm (Babylonian method) presented in the block diagram below. The variable ε is a parameter
representing the accuracy of the calculations performed, the variable w stores the result of calculating the square root of x.
 
Check what w values ​​will be obtained with different values ​​of the ε parameter: ε = 0.1, 0.01, 0.001, 0.0001.
How many iterations (loop revolutions) will be performed at ε = 0.1, 0.01, 0.001 and 0.0001.
 
Display the result with an accuracy of 8 decimal places.
You should use an iterative while statement.
![](/first_semester_C++/05_11_23/calculate_the_square_root_unit.jpg)
```
#include <iostream>
#include <cmath>

using namespace std;

double oblicz_pierwiastek(double x, double epsilon)
{
    double w = 1;

    while (pow(w, 2) - x >= epsilon)
    {
        w = (x / w + w) / 2;
    }

    return w;
}

int main()
{
    double x;
    cout << "Podaj liczbe: ";
    cin >> x;

    double epsilon_values[] = {0.1, 0.01, 0.001, 0.0001};

    for (double epsilon : epsilon_values)
    {
        double wynik = oblicz_pierwiastek(x, epsilon);

        cout << "Dla epsilon = " << epsilon << ": ";
        cout << "Wynik = " << wynik << ", ";
        cout << "Ilosc iteracji = " << static_cast<int>((log(1 / epsilon) / log(2))) + 1 << endl;
    }

    return 0;
}
```
![](/first_semester_C++/05_11_23/calculate_the_square_root_test.jpg)
## [Task 4:](/first_semester_C++/05_11_23/power.cpp)
Write and test a function that calculates and returns the value of ![](/first_semester_C++/05_11_23/task4_power.jpg), defined as follows:

![](/first_semester_C++/05_11_23/task4_pattern.jpg)

where 𝑥 is a real number and 𝑝 is an integer (negative or positive).
Display the result with an accuracy of 3 decimal places.
An iterative for statement should be used (DO NOT use library functions, e.g. pow() - in the task we create our own
its own "library-like" function).
Draw a block diagram of the implemented algorithm.
```
#include <iostream>

using namespace std;

double oblicz_potegowanie(double x, int p)
{
    if (p == 0)
    {
        return 1.0;
    }
    else if (p > 0)
    {
        double wynik = 1.0;
        for (int i = 0; i < p; i++)
        {
            wynik *= x;
        }
        return wynik;
    }
    else
    {
        double wynik = 1.0;
        for (int i = 0; i > p; i--)
        {
            wynik /= x;
        }
        return wynik;
    }
}

int main()
{
    double x;
    int p;

    cout << "Podaj liczbe ktora chcesz podniesc do potegi: ";
    cin >> x;
    cout << "Podaj potege: ";
    cin >> p;

    double wynik = oblicz_potegowanie(x, p);

    cout << "Wynik: " << wynik << endl;

    return 0;
}
```
![](/first_semester_C++/05_11_23/power_test.jpg)
![](/first_semester_C++/05_11_23/Flowchart%20(1).jpg)
### [Oryginal content of tasks.](/first_semester_C++/05_11_23/pp%20cw04%20instrukcje%20iteracyjne.pdf)
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)