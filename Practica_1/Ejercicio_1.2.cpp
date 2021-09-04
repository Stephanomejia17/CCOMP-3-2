#include <iostream>
using namespace std;

int main(){
    int x = 5;
    int * p = &x; // Direcci´on asignada a p 200
    int * & q = p;
    cout<< *q <<"\n";
    cout<<&*(q+1) <<"\n";

    /*
    *   En este ejercicio nos daba error un pequeño detalle, este era que cuando tenemos un alias a un puntero no podemos "apuntar" hacia un valor entero,
    *   sino debemos apuntar hacia un puntero a entero. En la primera impresión nos da el valor de 5, que es el valor que tiene x, en la siguiente impresion
    *   simplemente nos da la dirección en memoria de q aumentado en 1.
    */


    return 0;
}