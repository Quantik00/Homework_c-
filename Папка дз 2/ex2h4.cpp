#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string str1;
    getline(cin, str1);

    string str2;
    getline(cin, str2);
    
    int l_str2 = str2.size(); 
    int index = str1.find(str2);
    int counter = 0;

    while (index != string::npos)  // при npos возвращении в find е цикл рвётся
    {
        counter += 1;
        str1.erase(0, index + l_str2); // удалили находку 
        index = str1.find(str2); // снова ищемщ

    }

    cout << counter << "\n";
}