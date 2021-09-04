#include <iostream>
using namespace std;

int main(){
    int x = 10;
    int * p = &x; // Direcci´on asignada a p 200
    cout<< *p <<"\n";
    cout<< &p <<"\n";

    /*
    *   En este ejercicio creamos un entero x que contiene el valor de 10, después creamos un puntero a entero p que apunta a la dirección de memoria de mi variable x,
    *   después, estamos imprimiendo el valor entero al que apunta p, o sea, 10, una línea más abajo imprimimos la dirección de memoria de p, la cual es distinta a la
    *   dirección de x.
    */

   return 0;
}


