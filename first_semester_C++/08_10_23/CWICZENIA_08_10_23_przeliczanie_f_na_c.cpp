//podstawy programowania 08.10/23 CWICZENIA
// c = 5/9(f-32) 

#include<iostream>
#include<iomanip>
using namespace std;
int main() {
    cout << "przeliczanie tremperatury";
    cout << "\npodaj temp. w st. F: ";
    float f;
    cin >> f;
    float c;
    c = 5.0 / 9 * (f - 32);
    cout << fixed << setprecision(2);
    cout << f << " F = " << c << " C";
}