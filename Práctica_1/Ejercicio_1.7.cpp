#include <iostream>
using namespace std;

int main(){
	int a = 15;// Direcci´on asignada 200
    int* p = &a; // Direcci´on asignada 220
    int*&q = p;
    q--;
    cout<<p<<endl;
    p--;
    cout<<*(p+2)<<endl;
    cout<<p+4<<endl;
    cout<<*(&(*(p+2)))<<endl;

    /*
    *   En la primera impresion se ve que está imprimiendo una dirección de memoria, esto en verdad es basura, y se imprime eso ya que como a p/q
    *   le restamos 1 (4 bytes) nos quedamos en la posición de memoria 196, la cual no tiene ningún elemento asignado, luego nuevamente se le 
    *   resta 1 (4 bytes) a p/q y ahora estamos apuntando a la posición de memoria 192, la cual tampoco tiene un valor asignado, luego le sumamos 2 (8 bytes)
    *   a p y pedimos el valor que contiene esa posición de memoria, ahora estamos en la posición 200, la posición de 'a', entonces el programa 
    *   imprime el valor de 'a' (15), luego nuevamente le sumamos más 4 (16 bytes) a mi puntero p, quedandonos en la posición 208, en esta posición 
    *   tampoco hay ningún valor asignado a este espacio en mi memoria, por lo cual imprime basura, finalmente imprimimos el valor de 'a' porque al tener
    *   un & y * estos se anulan y nos queda un solo *, por lo cual cuando sumamos a mi puntero 8 bytes este se vuelve a posicionar en el espacio de
    *   memoria de 'a', por lo tanto imprime 15.
    */


}
