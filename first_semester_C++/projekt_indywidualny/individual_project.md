##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)
## BLACKJACK GAME.
<!--
### Wprowadzenie do gry Blackjack
Zasady gry: Graczom są rozdawane karty o pewnych wartościach punktowych.
Każdy gracz stara się uzyskać sumę 21 punktów, tak aby jej nie przekroczyć. Karty
numerowane (2 – 10) są liczone zgodnie z wartością widniejącą na ich licu. As ma
wartość 1 albo 11 (w zależności od tego, co jest dla gracza korzystniejsze), a każdy walet,
dama i król ma wartość 10 punktów.
Komputer rozdaje karty i współzawodniczy z graczami w liczbie od jednego do
siedmiu. Otwierając rundę, komputer rozdaje wszystkim uczestnikom gry (nie wyłączając
samego siebie) po dwie karty. Gracze widzą wszystkie swoje karty, a komputer wyświetla
nawet ich sumę. Jedna z kart rozdającego pozostaje jednak tymczasowo ukryta.
Następnie gracz otrzymuje szansę dobrania dodatkowych kart. Każdy z graczy może
jednorazowo dobrać jedną kartę i powtarzać tę czynność tak długo, jak chce. Lecz kiedy
suma punktów gracza przekroczy 21 (jest to tak zwana „fura”), gracz przegrywa. Jeśli
każdy z graczy dostanie furę, komputer odsłania swoją pierwszą kartę i runda się kończy.
W przeciwnym wypadku gra toczy się dalej. Komputer musi dobierać dodatkowe karty,
dopóki suma jego punktów jest mniejsza niż 17. Jeśli komputer dostanie furę, wszyscy
gracze, którzy sami jej nie dostali, zostają zwycięzcami. W przeciwnym razie suma
punktów każdego z graczy pozostających w grze jest porównywana z sumą uzyskaną
przez komputer. Jeśli suma punktów uzyskana przez gracza jest większa, gracz wygrywa.
Jeśli jest mniejsza, przegrywa. Jeśli obie sumy są jednakowe, gracz remisuje
z komputerem.
-->
### Task
The program should implement at least 7 functionalities:
• 2 functionalities related to data entry:
• the user can enter data from the keyboard,
• data (part of the data) is generated randomly.
• 1 functionality related to printing data;
• 4 functionalities related to the processing of information contained in the table(s).
• A block diagram should be drawn for one of the functionalities.
• Tests performed should be documented for at least one of the functionalities.
Each functionality should be implemented in a separate function. Functions should take an array as an argument,
and, at least some, return values. The program should not contain global variables.


#### Introduction to Blackjack
Rules of the game: Players are dealt cards with certain point values.
Each player tries to get a total of 21 points without exceeding it. Cards
numbered (2 - 10) are counted according to the value shown on their face. Ace has it
value 1 or 11 (depending on what is more advantageous for the player), and each jack,
queen and king is worth 10 points.
The computer deals cards and competes with players numbering from one to
seven. When opening a round, the computer deals to all participants (including
yourself) two cards each. Players see all their cards and the computer displays them
even their sum. However, one of the dealer's cards remains temporarily hidden.
The player then gets a chance to draw additional cards. Any player can
draw one card at a time and repeat this action for as long as he wants. But when
the sum of the player's points exceeds 21 (this is the so-called "rollout"), the player loses. If
each player gets a cart, the computer reveals its first card and the round ends.
Otherwise, the game continues. The computer must draw additional cards,
as long as his total points are less than 17. If the computer gets a beating, everyone
players who didn't get it themselves become winners. Otherwise sum
points of each player remaining in the game is compared with the total obtained
via computer. If the sum of points obtained by the player is greater, the player wins.
If it is smaller, it loses. If both totals are the same, the player draws
with computer.

[Blackjack.cpp](/projekt_indywidualny/blackjack.cpp)
```
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

const int BLACKJACK = 21;

enum RangaKarty
{
    AS = 1, DWA, TRZY, CZTERY, PIEC, SZESC, SIEDEM, OSIEM, DZIEWIEC, DYCHA, WALET, DAMA, KROL 
};

enum KolorKarty
{
    KIER, KARO, TREFL, PIK
};

struct Karta
{
    RangaKarty ranga;
    KolorKarty kolor;
};

struct  Gracz
{
    string imie;
    vector<Karta> reka;
};

vector<Karta> rekaKrupiera;

string zaczynajOdWielkiejLitery(const string& slowo)
{
    string wynik = slowo;
    if (!wynik.empty())
    {
        wynik[0] = toupper(wynik[0]);
    }
    return wynik;
}

void drukowanieDanych(const Karta& karta)
{
    switch (karta.ranga)
    {
    case AS:
        cout << "As";
        break;
    case DWA:
    case TRZY:
    case CZTERY:
    case PIEC:
    case SZESC:
    case SIEDEM:
    case OSIEM:
    case DZIEWIEC:
        cout << karta.ranga;
        break;
    case DYCHA:
        cout << "10";
        break;
    case WALET:
        cout << "Walet";
        break;
    case DAMA:
        cout << "Dama";
        break;
    case KROL:
        cout << "Krol";
        break;
    default:
        cout << "Nieznana";
        break;
    }

    switch (karta.kolor)
    {
    case KIER:
        cout << " kier";
        break;
    case KARO:
        cout << " karo";
        break;
    case TREFL:
        cout << " trefl";
        break;
    case PIK:
        cout << " pik";
        break;
    default:
        cout << " nieznany";
        break;
    }
}

void drukowanieZasadGry() 
{
    cout << "Wprowadzenie do gry Blackjack" << endl;
    cout << "Zasady gry: Graczom są rozdawane karty o pewnych wartościach punktowych." << endl;
    cout << "Każdy gracz stara się uzyskać sumę 21 punktów, tak aby jej nie przekroczyć. Karty" << endl;
    cout << "numerowane (2 – 10) są liczone zgodnie z wartością widniejącą na ich licu. As ma" << endl;
    cout << "wartość 1 albo 11 (w zależności od tego, co jest dla gracza korzystniejsze), a każdy walet," << endl;
    cout << "dama i król ma wartość 10 punktów." << endl;
    cout << "Komputer rozdaje karty i współzawodniczy z graczami w liczbie od jednego do" << endl;
    cout << "siedmiu. Otwierając rundę, komputer rozdaje wszystkim uczestnikom gry (nie wyłączając" << endl;
    cout << "samego siebie) po dwie karty. Gracze widzą wszystkie swoje karty, a komputer wyświetla" << endl;
    cout << "nawet ich sumę. Jedna z kart rozdającego pozostaje jednak tymczasowo ukryta." << endl;
    cout << "Następnie gracz otrzymuje szansę dobrania dodatkowych kart. Każdy z graczy może" << endl;
    cout << "jednorazowo dobrać jedną kartę i powtarzać tę czynność tak długo, jak chce. Lecz kiedy" << endl;
    cout << "suma punktów gracza przekroczy 21 (jest to tak zwana „fura”), gracz przegrywa. Jeśli" << endl;
    cout << "każdy z graczy dostanie furę, komputer odsłania swoją pierwszą kartę i runda się kończy." << endl;
    cout << "W przeciwnym wypadku gra toczy się dalej. Komputer musi dobierać dodatkowe karty," << endl;
    cout << "dopóki suma jego punktów jest mniejsza niż 17. Jeśli komputer dostanie furę, wszyscy" << endl;
    cout << "gracze, którzy sami jej nie dostali, zostają zwycięzcami. W przeciwnym razie suma" << endl;
    cout << "punktów każdego z graczy pozostających w grze jest porównywana z sumą uzyskaną" << endl;
    cout << "przez komputer. Jeśli suma punktów uzyskana przez gracza jest większa, gracz wygrywa." << endl;
    cout << "Jeśli jest mniejsza, przegrywa. Jeśli obie sumy są jednakowe, gracz remisuje" << endl;
    cout << "z komputerem." << endl;
}

int obliczeniePunktow(const vector<Karta>& reka)
{
    int punkty = 0;
    int liczbaAsow = 0;

    for (const auto& karta : reka)
    {
        if (karta.ranga == AS)
        {
            liczbaAsow++;
        }
        punkty += (karta.ranga > 10) ? 10 : karta.ranga;
    }
    
    while (liczbaAsow > 0 && punkty + 10 <= BLACKJACK)
    {
        punkty += 10;
        liczbaAsow --;
    }
    return punkty;
}

void przetwarzanieDanychGry(vector<Gracz>& gracze, vector<Karta>& talia, vector<Karta>& rekaKrupiera)
{
    for (const auto& gracz : gracze)
    {
        cout << "\nReka gracza " << zaczynajOdWielkiejLitery(gracz.imie) << ":\t";
        for (const auto& karta : gracz.reka)
        {
            drukowanieDanych(karta);
            cout << "\t";
        }
        cout << "Laczna liczba punktow: " << obliczeniePunktow(gracz.reka) << endl;
    }

    cout << "\nReka krupiera:\t";
    for (const auto& karta : rekaKrupiera)
    {
        drukowanieDanych(karta);
        cout << "\t";
    }
    cout << "Laczna liczba punktow: " << obliczeniePunktow(rekaKrupiera) << endl;

    int punktyKrupiera = obliczeniePunktow(rekaKrupiera);
    cout << "Laczna liczba punktow krupiera: " << punktyKrupiera << endl;

    for (auto& gracz : gracze)
    {
        while (true)
        {
            char decyzja;
            cout << "Gracz " << zaczynajOdWielkiejLitery(gracz.imie) << ", czy chcesz dobrac karte? (t/n): ";
            cin >> decyzja;

            if (decyzja == 't' || decyzja == 'T')
            {
                gracz.reka.push_back(talia.back());
                talia.pop_back();
                cout << "Twoja nowa karta to: ";
                drukowanieDanych(gracz.reka.back());
                cout << endl;

                if (obliczeniePunktow(gracz.reka) > BLACKJACK)
                {
                    cout << "Masz fure! Przegrywasz." << endl;
                }
                break;
            }
            else if (decyzja == 'n' || decyzja == 'N')
            {
                break;
            }
            else
            {
                cout << "Nieprawidlowy wybor. Wprowadz ponownie." << endl;
            }
        }
    }

    for (auto& gracz : gracze)
    {
        if (obliczeniePunktow(gracz.reka) > BLACKJACK)
        {
            cout << "Gracz " << zaczynajOdWielkiejLitery(gracz.imie) << " ma fure!" << endl;
        }
    }

    while (obliczeniePunktow(rekaKrupiera) < 17)
    {
        rekaKrupiera.push_back(talia.back());
        talia.pop_back();
    }

    cout << "\nReka krupiera po dobieraniu:\t";
    for (const auto& karta : rekaKrupiera)
    {
        drukowanieDanych(karta);
        cout << "\t";
    }
    cout << "Laczna liczba punktow krupiera: " << obliczeniePunktow(rekaKrupiera) << endl;

    for (const auto& gracz : gracze)
    {
        int punktyGracza = obliczeniePunktow(gracz.reka);

        if (punktyGracza > BLACKJACK)
        {
            cout << "Gracz " << zaczynajOdWielkiejLitery(gracz.imie) << " przegrywasz. Masz fure!" << endl;
        }
        else if (punktyKrupiera > BLACKJACK)
        {
            cout << "Gracz " << zaczynajOdWielkiejLitery(gracz.imie) << " gratulacje, wygrywasz. Krupier ma fure!" << endl;
        }
        else if (punktyGracza == punktyKrupiera)
        {
            cout << "Remis!" << endl;
        }
        else if (punktyGracza > punktyKrupiera)
        {
            cout << "Gracz " << zaczynajOdWielkiejLitery(gracz.imie) << " wygrales!" << endl;
        }
        else
        {
            cout << "Gracz " << zaczynajOdWielkiejLitery(gracz.imie) << " przegrales :( Krupier wygral!" << endl;
        }
    }   
}

int main()
{
    srand(static_cast<unsigned>(time(0)));

    int liczbaGraczy;
    cout << "Podaj liczbe graczy (1 - 7): ";
    cin >> liczbaGraczy;

    if (liczbaGraczy < 1 || liczbaGraczy > 7)
    {
        cout << "Zly wybor co do liczby graczy! Do zobaczenia następnym razem." << endl;
        return 1;
    }

    vector<Gracz> gracze;
    for (int i = 0; i < liczbaGraczy; ++i)
    {
        Gracz gracz;
        cout << "Podaj imie gracza " << (i + 1) << ": ";
        cin >> gracz.imie;
        gracz.imie = zaczynajOdWielkiejLitery(gracz.imie);
        gracze.push_back(gracz);
    }
    
    drukowanieZasadGry();

    vector<Karta> talia;
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Karta karta;
            karta.ranga = static_cast<RangaKarty>(i);
            karta.kolor = static_cast<KolorKarty>(j);
            talia.push_back(karta);
        }
    }
    
    shuffle(talia.begin(), talia.end(), default_random_engine{random_device{}()});

    for (auto& gracz : gracze)
    {
        gracz.reka.push_back(talia.back());
        talia.pop_back();
        gracz.reka.push_back(talia.back());
        talia.pop_back();
    }
    
    vector<Karta> rekaKrupiera;
    rekaKrupiera.push_back(talia.back());
    talia.pop_back();
    rekaKrupiera.push_back(talia.back());
    talia.pop_back();

    for (const auto& gracz : gracze)
    {
        cout << "Reka gracza " << zaczynajOdWielkiejLitery(gracz.imie) << ":\t";
        drukowanieDanych(gracz.reka[0]);
        cout << "\t###" << endl;
    }

    cout << "\nReka krupiera:\t";
    drukowanieDanych(rekaKrupiera[0]);
    cout << "\t###" << endl;

    przetwarzanieDanychGry(gracze, talia, rekaKrupiera);

    return 0;
}
```
### Program operation (several functionalities):

![](/projekt_indywidualny/dzialanie_programu_blackjack.png)

<!--
1. Kontrola wyboru liczby graczy (kolor zielony):
-->
1. Number of players selection control (green):
```
int liczbaGraczy;
cout << "Podaj liczbe graczy (1 - 7): ";
cin >> liczbaGraczy;

if (liczbaGraczy < 1 || liczbaGraczy > 7)
{
    cout << "Zly wybor co do liczby graczy! Do zobaczenia następnym razem." << endl;
    return 1;
}
```
<!-->
2. Wyświetlanie imion graczy z dużej litery (kolor żółty):
-->
2. Displaying players' names in capital letters (yellow):
```
string zaczynajOdWielkiejLitery(const string& slowo)
{
    string wynik = slowo;
    if (!wynik.empty())
    {
        wynik[0] = toupper(wynik[0]);
    }
    return wynik;
}
```
<!--
* Ta funkcja przyjmuje ciąg znaków `slowo`, tworzy kopię tego ciągu w zmiennej `wynik` i następnie zamienia pierwszą literę `wynik` na dużą literę, jeśli ciąg `wynik` nie jest pusty. Funkcja zwraca ciąg znaków `wynik`. Stosuje się ją do imion graczy, aby zapewnić, że są one wyświetlane zaczynając od dużej litery. Na przykład, gdy imię gracza jest wprowadzane, używane jest wywołanie tej funkcji, jak w poniższym fragmencie kodu:
-->
* This function takes the string `slowo`, creates a copy of the string in the variable `wynik`, and then capitalizes the first letter of `wynik` if the string `wynik` is not empty. The function returns the string `wynik`. It is applied to player names to ensure that they are displayed starting with a capital letter. For example, when a player's name is entered, a call to this function is used, as in the following code snippet:
```
gracz.imie = zaczynajOdWielkiejLitery(gracz.imie);
```
<!--
3. Możliwość dokonywania decyzji przez gracza z małej i dużej litery (kolor niebieski):
-->
3. The player can make decisions using lowercase and uppercase letters (blue):
```
while (true)
{
    char decyzja;
    cout << "Gracz " << zaczynajOdWielkiejLitery(gracz.imie) << ", czy chcesz dobrac karte? (t/n): ";
    cin >> decyzja;

    if (decyzja == 't' || decyzja == 'T')
    {
        // ...
    }
    else if (decyzja == 'n' || decyzja == 'N')
    {
        // ...
    }
    else
    {
        cout << "Nieprawidlowy wybor. Wprowadz ponownie." << endl;
    }
}
```
<!--
4. Lolsowe wydawanie kart:
* Losowe wydawanie kart jest kontrolowane przez kilka fragmentów kodu w głównej funkcji `main` oraz w funkcji `przetwarzanieDanychGry`. Poniżej przedstawiam istotne fragmenty kodu związane z losowym wydawaniem kart:

    W głównej funkcji `main`:
-->
4. Lols card issuing:
* Random card dispensing is controlled by several pieces of code in the `main` function and in the `przetwarzanieDanychGry` function. Below are important code fragments related to random card issuing:

    In the main `main` function:
```
shuffle(talia.begin(), talia.end(), default_random_engine{random_device{}()});

for (auto& gracz : gracze)
{
    gracz.reka.push_back(talia.back());
    talia.pop_back();
    gracz.reka.push_back(talia.back());
    talia.pop_back();
}

vector<Karta> rekaKrupiera;
rekaKrupiera.push_back(talia.back());
talia.pop_back();
rekaKrupiera.push_back(talia.back());
talia.pop_back();
```
<!--
* W funkcji `przetwarzanieDanychGry`:
-->
* In function `przetwarzanieDanychGry`:
```
for (auto& gracz : gracze)
{
    while (true)
    {
        char decyzja;
        cout << "Gracz " << zaczynajOdWielkiejLitery(gracz.imie) << ", czy chcesz dobrac karte? (t/n): ";
        cin >> decyzja;

        if (decyzja == 't' || decyzja == 'T')
        {
            gracz.reka.push_back(talia.back());
            talia.pop_back();
            cout << "Twoja nowa karta to: ";
            drukowanieDanych(gracz.reka.back());
            cout << endl;

            if (obliczeniePunktow(gracz.reka) > BLACKJACK)
            {
                cout << "Masz fure! Przegrywasz." << endl;
            }
            break;
        }
        else if (decyzja == 'n' || decyzja == 'N')
        {
            break;
        }
        else
        {
            cout << "Nieprawidlowy wybor. Wprowadz ponownie." << endl;
        }
    }
}

while (obliczeniePunktow(rekaKrupiera) < 17)
{
    rekaKrupiera.push_back(talia.back());
    talia.pop_back();
}
```
<!--
* Te fragmenty kodu odpowiadają za tasowanie talii kart i ich rozdanie graczom oraz krupierowi. Funkcja `shuffle` jest używana do losowego tasowania kart w talii. Następnie karty są rozdawane graczom i krupierowi zgodnie z zasadami gry w blackjacka.
-->
* These pieces of code that are responsible for shuffling the cards and dealing them to the players and the dealer. The `shuffle` function is used to randomly shuffle the cards in the solution. Cards are dealt to players and the dealer according to the blackjack game.
### [Oryginal content of task.](/first_semester_C++/projekt_indywidualny/Uwagi%20na%20temat%20zadan%20indywidualnych.pdf)
##### [Back to topic list.](/first_semester_C++/first_semester_C++.md)