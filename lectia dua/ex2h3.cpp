#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void find(int *arr, int elem, int N) { //ищем в int
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (arr[i] == elem) {
            cout << "нашел";
            flag = true;
        }
    }
    if (!flag) {
        cout << "не нашел";
    }
}

void find(char *arr, char elem, int N) { // ищём в char
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (arr[i] == elem) {
            cout << "нашел";
            flag = true;
        }
    }
    if (!flag) {
        cout << "не нашел";
    }
}

void find(float *arr, float elem, int N) { // ищем в  float
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (arr[i] == elem) {
            cout << "нашел";
            flag = true;
        }
    }
    if (!flag) {
        cout << "не нашел";
    }
}

int main() {
    cout << "Типа " << '\n';
    string str1;
    cin >> str1;
    cout << "Сколько элементов?" << '\n';
    int N;
    cin >> N;
    cout << "Вввод данных " << '\n';

    if (str1 == "int") {  // Создаём и заполняем int
        int massiv[N];
        for (int i = 0; i < N; i++) {
            cin >> massiv[i];
        }
        cout << "Что ищем?" << '\n';
        int y;
        cin >> y;

        find(massiv, y, N);
    }
    else if (str1 == "char") { // Создаём и заполняем char
        char massiv[N];
        for (int i = 0; i < N; i++) {
            cin >> massiv[i];
        }
        cout << "Что ищем?" << '\n';
        char y;
        cin >> y;

        find(massiv, y, N);
    }
    else if (str1 == "float") { // Создаём и заполняем float
        float massiv[N];
        for (int i = 0; i < N; i++) {
            cin >> massiv[i];
        }
        cout << "Что ищем?" << '\n';
        float y;
        cin >> y;

        find(massiv, y, N);
    }
    else {
        cout << "Invalid type!";
    }

    return 0;
}
