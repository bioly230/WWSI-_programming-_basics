#include <iostream>

int coztojest(int a, int b) 
{
    if (b == 0)
        return 0;
    if (b % 2 == 0)
        return coztojest(a + a, b / 2);
    return coztojest(a + a, b / 2) + a;
}

int main() 
{
    // Przykładowe wywołania funkcji
    std::cout << "coztojest(2, 25): " << coztojest(2, 25) << std::endl;
    std::cout << "coztojest(3, 11): " << coztojest(3, 11) << std::endl;

    return 0;
}
