##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)
# Recursive functions:
<!--
Funkcje rekurencyjne w języku C++ to funkcje, które wywołują same siebie w trakcie swojego wykonywania. To jest jeden z przykładów techniki programowania zwanej rekurencją.

Oto prosty przykład funkcji rekurencyjnej w C++, która oblicza silnię liczby całkowitej:
```
#include <iostream>

int silnia(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else 
    {
        return n * silnia(n - 1);
    }
}

int main()
{
    int liczba;
    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    int wynik = silnia(liczba);

    std::cout << "Silnia z " << liczba << " wynosi: " << wynik << std::endl;

    return 0;
}
```
W tej funkcji silnia jest wywoływana rekurencyjnie, ponieważ w jej definicji używamy samej siebie. Warto jednak pamiętać, że funkcje rekurencyjne powinny zawierać warunki zakończenia, aby uniknąć nieskończonych pętli rekurencyjnych. W powyższym przykładzie warunkiem zakończenia jest, gdy n przyjmuje wartość 0 lub 1.
-->
Recursive functions in C++ are functions that call themselves as they execute. This is one example of a programming technique called recursion.

Here is a simple example of a recursuve function in C++ that calculates the factorial of an interger:
```
#include <iostream>

int silnia(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else 
    {
        return n * silnia(n - 1);
    }
}

int main()
{
    int liczba;
    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    int wynik = silnia(liczba);

    std::cout << "Silnia z " << liczba << " wynosi: " << wynik << std::endl;

    return 0;
}
```
In this function, the factorial is called recursively because we use itself in its definition. However, it is worth remembering that recursive functions should include termination conditions to avoid infinite recursive loops. In the example above, the termination condition is when `n` becomes `0`or `1`.
## [Task 1](/first_semester_C++/19_11_23/najwiekszy_wspolny_dzielnik.cpp)
Write the recursive function gwd(a, b) to find the greatest common divisor of two numbers using Euclid's algorithm
shown below:
Let us assume that 𝒂≥𝒃>𝟎.
If 𝒂 𝒎𝒐𝒅 𝒃 ≠𝟎, then 𝒏𝒘𝒅(𝒂,𝒃) = 𝒏𝒘𝒅(𝒃,𝒂 𝒎𝒐𝒅 𝒃);
If 𝒂 𝒎𝒐𝒅 𝒃 = 𝟎, then 𝒏𝒘𝒅(𝒂,𝒃) = 𝒃;
 
where 𝒎𝒐𝒅 is the remainder operator of integer division.
 
a) Modify the nwd() function so that it displays the values ​​of its arguments in subsequent calls.
b) What is the greatest common divisor of the numbers 78 and 34, 7236485 and 40, 7250080 and 40? The number of times the nwd() function called itself in
these cases? Use a static variable to count the number of function calls.
```
#include <iostream>

using namespace std;

int nwd(int a, int b, int& ilosc)
{
    cout << "Wywolanie najwiekszego wspolnego dzielnika dwoch liczb:(" << a << ", " << b << ")" << endl;
    ilosc++;

    if (b == 0)
    {
        cout << "Najwiekszy wspolny dzielnik(" << a << ", " << b << ") = " << a << endl;
        return a;
    }
    else
    {
        return nwd(b, a % b, ilosc);
    }
}

int main()
{
    int ilosc1 = 0, ilosc2 = 0, ilosc3 = 0;

    int wynik1 = nwd(78, 34, ilosc1);
    cout << "Najwiekszy wspolny dzielnik(78, 34) = " << wynik1 << ", Liczba wywolan: " << ilosc1 << endl;

    int wynik2 = nwd(7236485, 40, ilosc2);
    cout << "Najwiekszy wspolny dzielnik(7236485, 40) = " << wynik2 << ", Liczba wywolan: " << ilosc2 << endl;

    int wynik3 = nwd(7250080, 40, ilosc3);
    cout << "Najwiekszy wspolny dzielnik(7250080, 40) = " << wynik3 << ", Liczba wywolan: " << ilosc3 << endl;

    return 0;
}
```
<!--
Wyjaśnienie:

1. Funkcja `nwd` jest rekurencyjna i używa algorytmu Euklidesa do wyznaczania największego wspólnego dzielnika.
2. Dodano argument `ilosc`, który zlicza liczbę wywołań funkcji.
3. W funkcji `main` wywołano funkcję `nwd` dla trzech różnych przypadków i wypisano wynik oraz liczbę wywołań dla każdego przypadku.

Wynik działania programu powinien być zgodny z oczekiwaniami, a liczba wywołań funkcji nwd została zliczona dla każdego przypadku.
-->
Explanation:

1. The `nwd` function is recursive and uses the Euclidean algorithm to find the greatest common divisor.
2. Added `ilosc` argument, which counts the number of function calls.
3. In the `main` function, the `nwd` function was called for three different cases and the result and the number of calls for each case were printed.

The program output should be as expected and the number of calls to the nwd function has been counted for each case.
![](/first_semester_C++/19_11_23/task1.png)

## [Task 2](/first_semester_C++/19_11_23/task2.cpp)
The following recursive function is given:
```
int coztojest(int a, int b){ 
if(b == 0)  
 return 0; 
if(b % 2 == 0)  
 return coztojest(a+a, b/2); 
return coztojest(a+a, b/2) +a; 
} 
``` 
a) What will be the results of the calls `coztojest(2, 25)` and `coztojest(3, 11)` ?
b) What does the function `coztojest(a, b)` calculate, assuming that `a` and `b` are positive integers?
c) What will the function `coztojest(a, b)` evaluate (assuming `a` and `b` are positive integers) when the + sign
will be replaced by `*` and `return 0` by `return 1`?
![](/first_semester_C++/19_11_23/task1.png)
<!--
Wyjaśnienie działania:

a) Rozwinięcie rekurencyjne wywołań funkcji coztojest(2, 25). Działa to na zasadzie rekurencyjnego podstawiania wartości i sumowania wyników.
* coztojest(64, 0) + 32 + 16 + 8 + 4 + 2
* 0 + 32 + 16 + 8 + 4 + 2
* 62
Podobnie możemy obliczyć `coztojest(3, 11)`

b) Funkcja coztojest(a, b) oblicza wartość a * b dla liczb całkowitych dodatnich. Działa to na zasadzie mnożenia a przez b, ale z wykorzystaniem operacji podwajania i dzielenia przez 2, co sprawia, że efektywne mnożenie odbywa się w czasie logarytmicznym względem wartości b.

c) Jeśli zmienimy znak + na * oraz return 0 na return 1, to funkcja będzie obliczać iloczyn a^b (a do potęgi b). Algorytm nadal będzie wykorzystywał operacje podwajania i dzielenia przez 2, co sprawi, że efektywne podnoszenie do potęgi będzie działać w czasie logarytmicznym względem wartości b.
-->
Operation explanation:

a) Recursive expansion of calls to the coztojest(2, 25) function. It works by recursively substituting values ​​and summing the results.
* coztojest(64, 0) + 32 + 16 + 8 + 4 + 2
* 0 + 32 + 16 + 8 + 4 + 2
* 62
Similarly, we can calculate `whatis(3, 11)`

b) The function coztojest(a, b) calculates the value of a * b for positive integers. This works by multiplying a by b, but using the operations of doubling and dividing by 2, which makes the effective multiplication take place in logarithmic time to the value of b.

c) If we change the + sign to * and return 0 to return 1, the function will calculate the product a^b (a to the power of b). The algorithm will still use doubling and dividing by 2 operations, making effective raising to a power run in logarithmic time with respect to the value of b.
### [Oryginal content of tasks.](/first_semester_C++/19_11_23/pp%20cw05%20rekursja.pdf)
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)