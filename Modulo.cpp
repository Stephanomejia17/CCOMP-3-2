#include <iostream>
using namespace std;

int main(){
    int a;
    int b;
    int c = 0;
    while(c < 12) {
        cout << "\n";
        cout << "Ingrese el primer numero: "; cin >> a;
        cout << "ingrese el segundo numero: "; cin >> b;

        cout << a << " mod " << b << " = " << a%b;
        c++;
    }
    
    return 0;
}