#include <iostream>

using namespace std; 

#define DYNAMIC_MEMORY 7 
#define ARRAY_SIZE 7

void fill(int* arr) 
{ 
    for (int i = 0; i < ARRAY_SIZE; ++i) 
    {
        arr[i] = i;
        cout << arr[i] << endl; 
    }
}

int main() {

#if DYNAMIC_MEMORY == 7 // #if -- препроцессинг
    int* dynamic_array = new int[ARRAY_SIZE]; 
    fill(dynamic_array);
    cout << "Наш динамический массив" << endl;
    delete[] dynamic_array; 
#else
    int static_array[ARRAY_SIZE]; 
    fill
    (static_array);
    cout << "Наш статический массив" << endl;
#endif

    return 0;
}
