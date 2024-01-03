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

vector<Karta> rekaKrupiera; // def. ręki krupiera

// drukowanie imienia gracza zawsze z wielkiej litery
string zaczynajOdWielkiejLitery(const string& slowo)
{
    string wynik = slowo;
    if (!wynik.empty())
    {
        wynik[0] = toupper(wynik[0]);
    }
    return wynik;
}

// drukowanie danych
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

// drukowanie zasad gry po wprowadzeniu imion graczy
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

// obliczanie sumy punktów krupiera
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

// przetwarzanie inf. w tablicy
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
    // punktowanie po doberaniu karty
    for (auto& gracz : gracze)
    {
        if (obliczeniePunktow(gracz.reka) > BLACKJACK)
        {
            cout << "Gracz " << zaczynajOdWielkiejLitery(gracz.imie) << " ma fure!" << endl;
        }
    }
    // ruch krupiera
    while (obliczeniePunktow(rekaKrupiera) < 17)
    {
        rekaKrupiera.push_back(talia.back());
        talia.pop_back();
    }
    // wyświetlenie kart krupiera po dobieraniu
    cout << "\nReka krupiera po dobieraniu:\t";
    for (const auto& karta : rekaKrupiera)
    {
        drukowanieDanych(karta);
        cout << "\t";
    }
    cout << "Laczna liczba punktow krupiera: " << obliczeniePunktow(rekaKrupiera) << endl;

    //sprawdzenie wynikow
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

    //tasowanie kart
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

    //rozdanie początkowe - po dwie karty dla graczy
    for (auto& gracz : gracze)
    {
        gracz.reka.push_back(talia.back());
        talia.pop_back();
        gracz.reka.push_back(talia.back());
        talia.pop_back();
    }
    
    //dwie pierwsze karty dla krupiera
    vector<Karta> rekaKrupiera;
    rekaKrupiera.push_back(talia.back());
    talia.pop_back();
    rekaKrupiera.push_back(talia.back());
    talia.pop_back();

    //gracze pokazują swoje karty
    for (const auto& gracz : gracze)
    {
        cout << "Reka gracza " << zaczynajOdWielkiejLitery(gracz.imie) << ":\t";
        drukowanieDanych(gracz.reka[0]);
        cout << "\t###" << endl;
    }

    //krupier pokazuje pierwszą karte
    cout << "\nReka krupiera:\t";
    drukowanieDanych(rekaKrupiera[0]);
    cout << "\t###" << endl;

    //start gry
    przetwarzanieDanychGry(gracze, talia, rekaKrupiera);

    return 0;
}