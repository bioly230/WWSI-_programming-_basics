##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)
# Structures in C++:
<!--
W C++, struktury są jednym z podstawowych elementów służących do definiowania własnych typów danych. Struktury umożliwia grupowanie różnych typów danych pod jednym nazwem, co pozwala na tworzenie bardziej złożonych struktur danych. Oto kilka kluczowych cech struktur w C++:

1. Definicja struktury:
* Struktury definiuje się za pomocą słowa kluczowego `struct`, po którym podaje się nazwę struktury. Struktura może zawierać różne rodzaje danych, takie jak liczby całkowite, liczby zmiennoprzecinkowe, znaki, wskaźniki, a nawet inne struktury.

2. Dostęp do elementów struktury:
* Do poszczególnych elementów struktury można uzyskać dostęp za pomocą operatora kropki `.`. Na przykład, aby uzyskać dostęp do pola `imie` struktury `Osoba`, używa się `osoba1.imie`, gdzie `osoba1` to zmienna typu `Osoba`.

3. Inicjalizacja struktury:
* Strukturę można zainicjować podczas jej deklaracji lub później, po utworzeniu zmiennej struktury. Inicjalizacja może obejmować ustawienie wartości dla każdego pola struktury.

4. Operacje na strukturach:
* Można wykonywać różne operacje na strukturach, takie jak przekazywanie ich jako argumenty do funkcji, zwracanie ich z funkcji, tworzenie tablic struktur, itp.

5. Struktury a klasy:
* W C++, struktury i klasy mają wiele wspólnych cech, ale istnieją różnice. Struktury domyślnie mają wszystkie elementy publiczne, podczas gdy klasy mają domyślnie elementy prywatne. W praktyce są pewne subtelne różnice w używaniu struktur i klas, ale obie mogą być używane do tworzenia złożonych typów danych.
-->
In C++, structures are one of the basic elements for defining your own data types. Structures allows you to group different types of data under one name, which allows you to create more complex data structures. Here are some key features of structures in C++:

1. Structure Definition:

* Structures are defined using the keyword `struct` followed by the name of the structure. A structure can contain various types of data, such as integers, floating-point numbers, characters, pointers, and even other structures.
```
struct Osoba 
{
    char imie[50];
    int wiek;
    float zarobki;
};
```

2. Access to structure elements:

* Individual elements of the structure can be accessed using the dot operator. For example, to access the name field of the `Osoba` structure, you use `osoba1.imie`, `osoba1` is a variable of type `Osoba`.
```
Osoba osoba1;
cout << "Imię: " << osoba1.imie << endl;
```

3. Structure initialization:

* A structure can be initialized during its declaration or later, after the structure variable has been created. Initialization may involve setting a value for each field of the structure.
```
Osoba osoba2 = {"Jan", 30, 5000.0};
```

4. Operations on structures:

* You can perform various operations on structures, such as passing them as arguments to functions, returning them from functions, creating arrays of structures, etc.
```
void wyswietlInformacje(Osoba osoba) 
{
    cout << "Imię: " << osoba.imie << ", Wiek: " << osoba.wiek << ", Zarobki: " << osoba.zarobki << endl;
}
```

5. Structures and classes:

* In C++, structures and classes have many things in common, but there are differences. Structures have all public members by default, while classes have private members by default. In practice, there are some subtle differences in the use of structures and classes, but both can be used to create complex data types.
```
class Klasa 
{
    ...
};
```
## Task:
Expand "program [pp_cw9_2_struktury_zwierzaki.cpp"](/first_semester_C++/12_01_24/pp_cw9_2_struktury_zwierzaki.cpp) 
```
#include<iostream>
using namespace std;

struct Zwierzak {
	char imie[10] ="";
	char gatunek[5] ="";
	int wiek;
	bool adoptowany = false;
};

Zwierzak wprowadz_dane_nowego_zwierzaka() {
	Zwierzak zwierzak;
	cout << "gatunek (pies/kot): "; cin >> zwierzak.gatunek;
	cout << "wiek: "; cin >> zwierzak.wiek;
	cout << "imie: "; cin >> zwierzak.imie;
	return zwierzak;
}
int zapisz_zwierzaka_w_bazie(const Zwierzak& zwierzak, Zwierzak zwierzaki[], int n) {
	zwierzaki[n] = zwierzak;
	n++;
	return n;
}
void pokaz_zwierzaka(const Zwierzak& zwierzak) {
	cout << zwierzak.imie << ", " << zwierzak.gatunek << ", " << zwierzak.wiek;
}
void pokaz_wszystkie_zwierzaki(const Zwierzak  zwierzaki[], int n) {
	for (int i = 0; i < n; i++) {
		pokaz_zwierzaka(zwierzaki[i]);
		cout << "\n";
	}
}

int main() {
	Zwierzak zwierzaki[100];
	int liczba_zwierzakow = 0;
	char czy_nowy_zwierzak = 'n';
	do {
		Zwierzak nowy_zwierzak = wprowadz_dane_nowego_zwierzaka();
		liczba_zwierzakow = zapisz_zwierzaka_w_bazie(nowy_zwierzak, zwierzaki, liczba_zwierzakow);
		cout << "nowy zwierzak (t/n)? "; 
		cin >> czy_nowy_zwierzak;
	} while (czy_nowy_zwierzak == 't');
	pokaz_wszystkie_zwierzaki(zwierzaki, liczba_zwierzakow);
}
```
as follows:
1. Add other attributes to the Pet structure;
2. Add new functionalities to the program:
1. Sorting animals by age;
2. Displaying pets that meet the criteria of a person considering adoption;
3. Updating the animal database after adoption.

<!--
Rozwinięty program uwzględnia dodatkowe atrybuty w strukturze Zwierzak, sortowanie ze względu na wiek, wyświetlanie zwierzaków spełniających kryteria adopcji oraz aktualizację bazy zwierząt po dokonaniu adopcji.
```
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct Zwierzak 
{
    char imie[10] = "";
    char gatunek[5] = "";
    int wiek;
    bool adoptowany = false;
    // Dodatkowe atrybuty
    string kolor_siersci;
    bool szczepiony;
};

Zwierzak wprowadz_dane_nowego_zwierzaka() 
{
    Zwierzak zwierzak;
    cout << "gatunek (pies/kot): "; cin >> zwierzak.gatunek;
    cout << "wiek: "; cin >> zwierzak.wiek;
    cout << "imie: "; cin >> zwierzak.imie;
    cout << "kolor siersci: "; cin >> zwierzak.kolor_siersci;
    cout << "czy szczepiony (1 - tak, 0 - nie): "; cin >> zwierzak.szczepiony;
    return zwierzak;
}

int zapisz_zwierzaka_w_bazie(Zwierzak& zwierzak, vector<Zwierzak>& zwierzaki) 
{
    zwierzaki.push_back(zwierzak);
    return zwierzaki.size();
}

void pokaz_zwierzaka(const Zwierzak& zwierzak) 
{
    cout << zwierzak.imie << ", " << zwierzak.gatunek << ", " << zwierzak.wiek
         << ", " << zwierzak.kolor_siersci << ", Szczepiony: " << (zwierzak.szczepiony ? "Tak" : "Nie");
}

void pokaz_wszystkie_zwierzaki(const vector<Zwierzak>& zwierzaki) 
{
    for (const auto& zwierzak : zwierzaki) {
        pokaz_zwierzaka(zwierzak);
        cout << "\n";
    }
}

void posortuj_zwierzaki_wg_wieku(vector<Zwierzak>& zwierzaki) 
{
    sort(zwierzaki.begin(), zwierzaki.end(), [](const Zwierzak& a, const Zwierzak& b) 
    {
        return a.wiek < b.wiek;
    });
}

void wyswietl_zwierzaki_do_adopcji(const vector<Zwierzak>& zwierzaki) 
{
    cout << "Zwierzaki do adopcji:\n";
    for (const auto& zwierzak : zwierzaki) 
    {
        if (!zwierzak.adoptowany) 
        {
            pokaz_zwierzaka(zwierzak);
            cout << "\n";
        }
    }
}

void aktualizuj_baze_po_adopcji(vector<Zwierzak>& zwierzaki, const string& imie) 
{
    auto it = find_if(zwierzaki.begin(), zwierzaki.end(), [imie](const Zwierzak& zwierzak) 
    {
        return zwierzak.imie == imie;
    });

    if (it != zwierzaki.end()) 
    {
        it->adoptowany = true;
        cout << "Adopcja zwierzaka o imieniu " << imie << " została zaktualizowana.\n";
    } 
    else 
    {
        cout << "Nie znaleziono zwierzaka o imieniu " << imie << ".\n";
    }
}

int main() 
{
    vector<Zwierzak> zwierzaki;
    char czy_nowy_zwierzak = 'n';

    do 
    {
        Zwierzak nowy_zwierzak = wprowadz_dane_nowego_zwierzaka();
        zwierzaki.push_back(nowy_zwierzak);

        cout << "Czy ten zwierzak został adoptowany (1 - tak, 0 - nie)? ";
        cin >> nowy_zwierzak.adoptowany;

        cout << "Czy chcesz dodać kolejnego zwierzaka (t/n)? ";
        cin >> czy_nowy_zwierzak;

    } 
    while (czy_nowy_zwierzak == 't');

    // Sortowanie zwierzaków ze względu na wiek
    posortuj_zwierzaki_wg_wieku(zwierzaki);

    // Wyświetlanie zwierzaków spełniających kryteria adopcji
    wyswietl_zwierzaki_do_adopcji(zwierzaki);

    // Aktualizacja bazy po adopcji
    string imie_adoptowanego;
    cout << "Podaj imię zwierzaka, który został adoptowany: ";
    cin >> imie_adoptowanego;
    aktualizuj_baze_po_adopcji(zwierzaki, imie_adoptowanego);

    // Wyświetlenie wszystkich zwierzaków po aktualizacji
    pokaz_wszystkie_zwierzaki(zwierzaki);

    return 0;
}
```
-->
1. New attributes added to the Pet structure:

* `string kolor_siersci` - an additional attribute specifying the color of the pet's fur.
* `bool szczepiony` - additional attribute informing whether the pet is vaccinated.
```
struct Zwierzak 
{
    char imie[10] = "";
    char gatunek[5] = "";
    int wiek;
    bool adoptowany = false;
    string kolor_siersci;
    bool szczepiony;
};
```
2. The way pets are stored has been changed:

* Instead of using an array, the program now uses a vector to dynamically store pets.
```
vector<Zwierzak> zwierzaki;
```
3. The `zapisz_zwierzeta_w_bazie` function has been updated:

* Changed the `zwierzeta` parameter to a vector to allow for dynamic addition of pets.
```
int zapisz_zwierzaka_w_bazie(Zwierzak& zwierzak, vector<Zwierzak>& zwierzaki) 
{
    zwierzaki.push_back(zwierzak);
    return zwierzaki.size();
}
```
4. The `posortuj_zwierzaki_wg_wieku` function has been added:

* A function that sorts pets by age.
```
void posortuj_zwierzaki_wg_wieku(vector<Zwierzak>& zwierzaki) 
{
    sort(zwierzaki.begin(), zwierzaki.end(), [](const Zwierzak& a, const Zwierzak& b) 
	{
        return a.wiek < b.wiek;
    });
}
```
5. The `wyswietl_zwierzaki_do_adaptacji` function has been added:

* A function that displays pets that have not been adopted yet.
```
void wyswietl_zwierzaki_do_adopcji(const vector<Zwierzak>& zwierzaki) 
{
    cout << "Zwierzaki do adopcji:\n";
    for (const auto& zwierzak : zwierzaki) 
	{
        if (!zwierzak.adoptowany) 
		{
            pokaz_zwierzaka(zwierzak);
            cout << "\n";
        }
    }
}
```
6. `aktualizuj_baze_po_adaptacji` function added:

* A function that updates information about the pet after adoption.
```
void aktualizuj_baze_po_adopcji(vector<Zwierzak>& zwierzaki, const string& imie) 
{
    auto it = find_if(zwierzaki.begin(), zwierzaki.end(), [imie](const Zwierzak& zwierzak) 
	{
        return zwierzak.imie == imie;
    });

    if (it != zwierzaki.end()) 
	{
        it->adoptowany = true;
        cout << "Adopcja zwierzaka o imieniu " << imie << " została zaktualizowana.\n";
    } 
	else 
	{
        cout << "Nie znaleziono zwierzaka o imieniu " << imie << ".\n";
    }
}
```
7. `pokaz_wszystkie_zwierzaki` function has been updated:

* The function now takes a pet vector.
```
void pokaz_wszystkie_zwierzaki(const vector<Zwierzak>& zwierzaki) 
{
    for (const auto& zwierzak : zwierzaki) 
	{
        pokaz_zwierzaka(zwierzak);
        cout << "\n";
    }
}
```
8. `main` function updated:

* Vector functions and new functions are used to support additional functionality.
```
int main() 
{
    vector<Zwierzak> zwierzaki;
    ...
}
```
![](/first_semester_C++/12_01_24/dzialanie_kodu_struktury.png)

```
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct Zwierzak 
{
    char imie[10] = "";
    char gatunek[5] = "";
    int wiek;
    bool adoptowany = false;
    string kolor_siersci;
    bool szczepiony;
};

Zwierzak wprowadz_dane_nowego_zwierzaka() 
{
    Zwierzak zwierzak;
    cout << "gatunek (pies/kot): "; cin >> zwierzak.gatunek;
    cout << "wiek: "; cin >> zwierzak.wiek;
    cout << "imie: "; cin >> zwierzak.imie;
    cout << "kolor siersci: "; cin >> zwierzak.kolor_siersci;
    cout << "czy szczepiony (1 - tak, 0 - nie): "; cin >> zwierzak.szczepiony;
    return zwierzak;
}

int zapisz_zwierzaka_w_bazie(Zwierzak& zwierzak, vector<Zwierzak>& zwierzaki) 
{
    zwierzaki.push_back(zwierzak);
    return zwierzaki.size();
}

void pokaz_zwierzaka(const Zwierzak& zwierzak) 
{
    cout << zwierzak.imie << ", " << zwierzak.gatunek << ", " << zwierzak.wiek
         << ", " << zwierzak.kolor_siersci << ", Szczepiony: " << (zwierzak.szczepiony ? "Tak" : "Nie");
}

void pokaz_wszystkie_zwierzaki(const vector<Zwierzak>& zwierzaki) 
{
    for (const auto& zwierzak : zwierzaki) {
        pokaz_zwierzaka(zwierzak);
        cout << "\n";
    }
}

void posortuj_zwierzaki_wg_wieku(vector<Zwierzak>& zwierzaki) 
{
    sort(zwierzaki.begin(), zwierzaki.end(), [](const Zwierzak& a, const Zwierzak& b) 
    {
        return a.wiek < b.wiek;
    });
}

void wyswietl_zwierzaki_do_adopcji(const vector<Zwierzak>& zwierzaki) 
{
    cout << "Zwierzaki do adopcji:\n";
    for (const auto& zwierzak : zwierzaki) 
    {
        if (!zwierzak.adoptowany) 
        {
            pokaz_zwierzaka(zwierzak);
            cout << "\n";
        }
    }
}

void aktualizuj_baze_po_adopcji(vector<Zwierzak>& zwierzaki, const string& imie) 
{
    auto it = find_if(zwierzaki.begin(), zwierzaki.end(), [imie](const Zwierzak& zwierzak) 
    {
        return zwierzak.imie == imie;
    });

    if (it != zwierzaki.end()) 
    {
        it->adoptowany = true;
        cout << "Adopcja zwierzaka o imieniu " << imie << " została zaktualizowana.\n";
    } 
    else 
    {
        cout << "Nie znaleziono zwierzaka o imieniu " << imie << ".\n";
    }
}

int main() 
{
    vector<Zwierzak> zwierzaki;
    char czy_nowy_zwierzak = 'n';

    do 
    {
        Zwierzak nowy_zwierzak = wprowadz_dane_nowego_zwierzaka();
        zwierzaki.push_back(nowy_zwierzak);

        cout << "Czy ten zwierzak został adoptowany (1 - tak, 0 - nie)? ";
        cin >> nowy_zwierzak.adoptowany;

        cout << "Czy chcesz dodać kolejnego zwierzaka (t/n)? ";
        cin >> czy_nowy_zwierzak;

    } 
    while (czy_nowy_zwierzak == 't');

    posortuj_zwierzaki_wg_wieku(zwierzaki);

    wyswietl_zwierzaki_do_adopcji(zwierzaki);

    string imie_adoptowanego;
    cout << "Podaj imię zwierzaka, który został adoptowany: ";
    cin >> imie_adoptowanego;
    aktualizuj_baze_po_adopcji(zwierzaki, imie_adoptowanego);

    pokaz_wszystkie_zwierzaki(zwierzaki);

    return 0;
}
```

### [Full code:](/first_semester_C++/12_01_24/structures_pp_cw9_2.cpp)
### [Oryginal content of task.](/first_semester_C++/12_01_24/pp%20cw09%20struktury.pdf)
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)