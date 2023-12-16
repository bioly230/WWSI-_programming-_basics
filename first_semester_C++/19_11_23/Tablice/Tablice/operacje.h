/*EFigielska pp*/
#pragma once
//dla tablic o elementach rzeczywistych
float * utworz_tablice(int &n);
void wygeneruj_wartosci(float *t, int n, float d = 0, float g = 10);
void pobierz_wartosci(float *t, int);
void wypisz_tablice(const float *t, int n);
float wyznacz_min(const float *t, int n);
int znajdz_wartosc(const float * t, int n, float x, float eps);
bool jest_scisle_rosnacy(const float *t, int n);
bool jest_arytmetyczny(const float *t, int n, float eps);
float oblicz_wartosc_wielomianu(const float* t, int n, float x);
float oblicz_wartosc_wielomianu_rekurencyjnie(const float* t, int n, float x);
void posortuj(float* t, int n);
