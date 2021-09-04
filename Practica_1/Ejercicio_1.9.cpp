#include <iostream>
using namespace std;

int main(){
	int a = 15;
    int b = 20;
    int&q = b;
    q = a;
    q++;
    cout<<q;
    /*
    *   Primero veo que q es una referencia de b, una línea más abajo nos dice que q = a, por lo tanto b también es igual a 'a',
    *   luego le sumamos 1 a mi 'q' y una línea más abajo imprimimos mi q, lo que nos da como resultado 16
    *
    */

}