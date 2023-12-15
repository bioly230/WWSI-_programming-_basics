##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)
# References and pointers as function parameters:
<!--
W języku C++, referencje i wskaźniki mogą być używane jako parametry funkcji w celu przekazania danych dco funkcji.
#### Referencje jako parametry funkcji:
* Referencje to alternatywny sposób przekazywania danych do funkcji, umożliwiający bezpośredni dostęp do oryginalnych danych. Na przykład:
```
void zmodyfikujWartosc(int &x)
{
    x = x * 2;
}

int main()
{
    int wartosc = 5;
    zmodyfikujWartosc(wartosc);
    //po tej funkcji 'wartosc' będzie wynosić 10
    return 0;
}
```
#### Wskaźniki jako parametry funkcji:
* Wskaźniki to zmienne, które przechowują adresy pamięci innych zmiennych. Mogą być używane do przekazywania adresów do funkcji. Na przykład:
```
void zmodyfikujWartosc(int *ptr)
{
    (*ptr) = (*ptr) * 2;
}

int main()
{
    int wartsc = 5;
    int *ptr = &wartosc;
    zmodyfikujWartosc(ptr);
    //po tej funkcji 'wartosc' będzie wynosić 10.
    return 0;
}
```
W obu przypadkach, zmiany wprowadzone w funkcji mają wpływ na oryginalne dane. Wybór między referencjami a wskaźnikami zależy od potrzeb i preferancji programisty. Referencje są bardziej zwięzłe i bardziej przypominają korzystamie z oryginalnych zmiennych, podczas gdy wskaźniki oferują większą kontrolę nad adresami pamięci.
-->
### [Oryginal content of tasks.](/first_semester_C++/19_11_23/pp%20cw06%20referencje%20i%20wskazniki.pdf)
In C++, references and pointers can be used as function parameters to pass data to the function.
#### References as function parameters:
* References are an alternative way to pass data to a function, allowing direct access to the original data. For example:
```
void zmodyfikujWartosc(int &x)
{
    x = x * 2;
}

int main()
{
    int wartosc = 5;
    zmodyfikujWartosc(wartosc);
    //po tej funkcji 'wartosc' będzie wynosić 10
    return 0;
}
```
#### Pointers as function parameters:
* Pointers are variables that hold the memory addresses of other variables. They can be used to pass addresses to functions. For example:
```
void zmodyfikujWartosc(int *ptr)
{
    (*ptr) = (*ptr) * 2;
}

int main()
{
    int wartsc = 5;
    int *ptr = &wartosc;
    zmodyfikujWartosc(ptr);
    //po tej funkcji 'wartosc' będzie wynosić 10.
    return 0;
}
```
In both cases, changes made to the function affect the original data. The choice between references and pointers depends on the developer's needs and preferences. References are more concise and more like using original variables, while pointers offer more control over memory addresses.
## Task:
Write a function that, based on information provided to it about the patient such as age, height and gender, will calculate: index
basal metabolic rate (𝑝𝑝𝑚), ideal body weight (𝑖𝑚𝑐) and deviation from ideal body weight (𝑑) according to
the following designs:
![](/first_semester_C++/19_11_23/task1_cw06_description.png)
where 𝑤 – patient's body weight [kg], ℎ – patient's height [cm], 𝑎 – patient's age [years].
Make two versions of the function based on the examples from the exercises:
 
[pp_cw06_2_referencje_przekazywane_do_funkcji.cpp](/first_semester_C++/19_11_23/pp_cw06_2_referencje_przekazywane_do_funkcji.cpp) 
```
#include<iostream>
using namespace std;
bool iloraz_i_reszta(int dzielna, int dzielnik, int & iloraz, int & reszta) {
	if (dzielnik == 0) {
		return false;
	}
	iloraz = dzielna / dzielnik;
	reszta = dzielna % dzielnik;
	return true;
}

int main() {
	int a, b;
	cout << "podaj dwie liczby: ";
	cin >> a >> b;
	int wynik_dzielenia = 0, reszta_z_dzielenia = 0;
	bool policzone = iloraz_i_reszta(a, b, wynik_dzielenia, reszta_z_dzielenia);
	if (policzone) {
		cout << "iloraz = " << wynik_dzielenia << " reszta = " << reszta_z_dzielenia;
	}
	else {
		cout << "dzielenie przez 0";
	}
}
```
and 

[pp_cw06_3_wskazniki_przekazywane_do_funkcji.cpp](/first_semester_C++/19_11_23/pp_cw06_3_wskaźniki_przekazywane_do_funkcji.cpp)
```
#include<iostream>
using namespace std;
bool iloraz_i_reszta(int dzielna, int dzielnik, int* iloraz, int* reszta) {
	if (dzielnik == 0) {
		return false;
	}
	*iloraz = dzielna / dzielnik;
	*reszta = dzielna % dzielnik;
	return true;
}

int main() {
	int a, b;
	cout << "podaj dwie liczby: ";
	cin >> a >> b;
	int wynik_dzielenia = 0, reszta_z_dzielenia = 0;
	bool policzone = iloraz_i_reszta(a, b, &wynik_dzielenia, &reszta_z_dzielenia);
	if (policzone) {
		cout << "iloraz = " << wynik_dzielenia << " reszta = " << reszta_z_dzielenia;
	}
	else {
		cout << "dzielenie przez 0";
	}
}
```
1. [Parameters 𝑝𝑝𝑚, 𝑖𝑚𝑐, 𝑑 are passed to the function by reference:]()
```
#include<iostream>
using namespace std;

void obliczParametryPacjenta(double w, double h, double a, char plec, double &ppm, double &imc, double &d) 
{
    if (a >= 0 && h >= 0 && w >= 0) 
    {
        if (plec == 'M') 
        {
            ppm = 10 * w + 6.25 * h - 5 * a + 5;
            imc = 50 + 0.9 * (h - 152);
        }
        else if (plec == 'K') 
        {
            ppm = 10 * w + 6.25 * h - 5 * a - 161;
            imc = 45.5 + 0.9 * (h - 152);
        }

        if (imc != 0) 
        {
            d = w - imc;
        } 
        else 
        {
            d = 0; // Tutaj możesz ustawić wartość domyślną
        }
    }
}

int main() 
{
    double waga, wzrost, wiek, ppm, imc, odchylenie;

    cout << "Podaj masę pacjenta [kg]: ";
    cin >> waga;

    cout << "Podaj wzrost pacjenta [cm]: ";
    cin >> wzrost;

    cout << "Podaj wiek pacjenta [lata]: ";
    cin >> wiek;

    char plec;
    cout << "Wybierz płeć pacjenta (M/K): ";
    cin >> plec;

    obliczParametryPacjenta(waga, wzrost, wiek, plec, ppm, imc, odchylenie);

    cout << "Wskaźnik podstawowej przemiany materii (ppm): " << ppm << endl;
    cout << "Idealna masa ciała (imc): " << imc << endl;
    cout << "Odstępstwo od idealnej masy (d): " << odchylenie << endl;

    return 0;
}
```
<!--
Funkcja `obliczParametryPacjenta` przyjmuje parametry i oblicza wskaźnik podstawowej przemiany materii (ppm), idealną masę ciała (imc) oraz odstępstwo od idealnej masy ciała (d). Parametry te są przekazywane do funkcji przez referencję.
-->
The `calculatePatientParameters` function accepts and calculates the basal metabolic rate (ppm), ideal body weight (imc) and deviation from ideal body weight (d). These parameters are passed to the function by reference.
2. [Parameters 𝑝𝑝𝑚, 𝑖𝑚𝑐, 𝑑 are passed to the function through the pointer:](/first_semester_C++/19_11_23/task_query_2.cpp)
```
#include<iostream>
using namespace std;

void obliczParametryPacjenta(double w, double h, double a, char plec, double *ppm, double *imc, double *d) 
{
    if (a >= 0 && h >= 0 && w >= 0) 
    {
        if (plec == 'M') 
        {
            *ppm = 10 * w + 6.25 * h - 5 * a + 5;
            *imc = 50 + 0.9 * (h - 152);
        } 
        else if (plec == 'K') 
        {
            *ppm = 10 * w + 6.25 * h - 5 * a - 161;
            *imc = 45.5 + 0.9 * (h - 152);
        }

        if (*imc != 0) 
        {
            *d = w - *imc;
        } else 
        {
            *d = 0; 
        }
    }
}

int main() 
{
    double waga, wzrost, wiek, ppm, imc, odchylenie;

    cout << "Podaj masę pacjenta [kg]: ";
    cin >> waga;

    cout << "Podaj wzrost pacjenta [cm]: ";
    cin >> wzrost;

    cout << "Podaj wiek pacjenta [lata]: ";
    cin >> wiek;

    char plec;
    cout << "Wybierz płeć pacjenta (M/K): ";
    cin >> plec;

    obliczParametryPacjenta(waga, wzrost, wiek, plec, &ppm, &imc, &odchylenie);

    cout << "Wskaźnik podstawowej przemiany materii (ppm): " << ppm << endl;
    cout << "Idealna masa ciała (imc): " << imc << endl;
    cout << "Odstępstwo od idealnej masy (d): " << odchylenie << endl;

    return 0;
}
```
<!--
Funkcja `obliczParametryPacjenta` przyjmuje i oblicza wskaźnik podstawowej przemiany materii (ppm), idealną masę ciała (imc) oraz odstępstwo od idealnej masy ciała (d). Parametry te są przekazywane do funkcji przez wskaźnik.
-->
The `calculatePatientParameters` function accepts and calculates the basal metabolic rate (ppm), ideal body weight (imc) and deviation from ideal body weight (d). These parameters are passed to the function via a pointer.
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)