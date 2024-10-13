#include <iostream>
#define N 7 
using namespace std;

struct vector { // Вектор + умножение на число
    float vec[N];

    void multiply(float k) 
    {
        for (int i = 0; i < N; i++)
        {
            vec[i] *= k;
        }
    }
};

struct vector summ(struct vector v1, struct vector v2)
{ 
    struct vector v_new{};
    for (int i = 0; i < N; i++) {
        v_new.vec[i] = v1.vec[i] + v2.vec[i];
    }
    return v_new;
}

float scalar(struct vector v1, struct vector v2) { 
    float answer = 0;
    for (int i = 0; i < N; i++) {
        answer += v1.vec[i] * v2.vec[i];
    }
    return answer;
}

int main() 
{
    struct vector v1 {};
    struct vector v2 {};
    
    cout << "Координаты вектора 1" << '\n';
    for (int i = 0; i < N; i++) 
    {
        float x;
        cin >> x;
        v1.vec[i] = x;
    }
    cout << "Координаты вектора  2" << '\n';
    for (int j = 0; j < N; j++) 
    {
        float x;
        cin >> x;
        v2.vec[j] = x;
    }
    cout << "Чиселко для умножения" << '\n';
    float k;
    cin >> k;
    
    v1.multiply(k); 
    struct vector v3 = summ(v1, v2); 
    float sc = scalar(v1, v2); 
    cout << "Скалярное " << sc << '\n';

    return 0;
}
