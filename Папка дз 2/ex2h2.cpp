#include <iostream> 
using namespace std;

int main()
{ 
    int sum = 0; 
    int elem; 
    while (cin >> elem)
    { 
        if (elem > 0)
        { 
            sum += elem; 
            cout << sum << "\n";     
        }  
        else if (elem == 0) 
        { 
            break; 
        } 
    } 
 
}