#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int elem;
    cin >> elem;
    int* numbers = new int[elem]; // в нью инте длина массива, а массив динамиечский, длина меняется
    for (int i = 0; i <= elem - 1; ++i) 
    {
        *(numbers + i) = i * i;
    }

    for (int i = 0; i < elem; ++i)
    {
        sum += numbers[i];
        
    }
    cout << "Сумма " << sum << "\n";
    delete[] numbers;

}
