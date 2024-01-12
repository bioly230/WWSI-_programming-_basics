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
