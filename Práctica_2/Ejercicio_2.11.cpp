#include <iostream>
using namespace std;

int main(){
    float x = 10.5; // Direcci´on asignada a x 200
float * p = &x; // Direcci´on asignada a p 400
float ** p0 = &p;
std::cout<<p <<"\n"; //imprime la direccion de p
p++;
std::cout<<p <<"\n"; //se incremente e imprime la sigueinte direccion
std::cout<<*p <<"\n";  //imprime el valor que se esncentra en la posicion aumentada
(*p0)++;
(**p0)++;
std::cout<<(**p0) <<"\n";
std::cout<<p <<"\n";
std::cout<<*(p-2) <<"\n";
}