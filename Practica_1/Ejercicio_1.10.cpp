#include <iostream>
using namespace std;

int main(){
    double a = 1;
	double & dr = a;
    dr++;
    cout<<dr;
    /*
    *   Primero sustituí el número 1 por mi 'a' que es igual a 1 porque no es correcto asignarle a una referencia un valor entero, sino,
    *   podemos hacerlo mediante una variable, de esta forma más abajo podemos sumarle más 1 a mi variable dr, y finalmente imprimimos mi
    *   valor sumado lo que nos resulta en 2.
    */

}