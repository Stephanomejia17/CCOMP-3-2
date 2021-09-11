#include <iostream>
using namespace std;

int main(){
    int x = 5; // Direcci´on asignada 200
    int * p = &x;
    p = 0;
    p = nullptr;
    //p = 1;  //Aquí da error porque una línea antes estamos poniendo a p como un puntero nulo, al ser nulo no puede tener ningún valor
    cout << p;
    

}