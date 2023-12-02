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

### [Oryginal content of tasks.](/first_semester_C++/19_11_23/pp%20cw05%20rekursja.pdf)
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)