#include <iostream>
using namespace std;

int main(){
    //float -> 4 bytes
    float x = 10; // Direcci´on asignada a x 100
    float* pv = &x; // Direcci´on asignada a pv 200
    pv++;
    
    printf("%d\n",pv);

    printf("%d\n",&x);
    
    cout << &x;

    /*
    *   Aquí tenemos una variable x y un puntero que apunta a esta variable llamada pv, en este caso usamos printf para 
    *   poder usar %d, que lo que hace básicamente es convertir nuestra direccion en memoria en un numero entero, luego
    *   lo estamos imprimiendo sumado en 1 (4 bytes) pero en mi posición 104 no hay nada declarado, entonces lo que se 
    *   imprime simplemente es basura.
    */




    return 0;
}