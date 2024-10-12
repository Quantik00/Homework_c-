#include <iostream> 
using namespace std;
 
int main() { 
    int x, y; 
    std::cin >> x; 
    y = 0; 
    for (int i = 2; i <= x/2 + 1; ++i) 
        { 
        if (x % i == 0) { 
            y = i; 
        } 
    } 
    if (y==0) 
    { 
        cout << " Оно простое " << "\n" ; 
    } 
    else
    { 
        cout << "Максимальный делитель " << y << "\n"; 
    } 
}