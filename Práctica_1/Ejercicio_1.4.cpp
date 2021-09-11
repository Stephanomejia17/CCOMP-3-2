#include <iostream>
using namespace std;

int main(){
	int vector[] = {4,5,6};
	int* p1 = vector; //apunta a la primera posición de mi vector
	cout<<sizeof(p1)<<endl;
	cout<<sizeof(vector);
	int* p2 = vector + 2;
	cout<< *p2<<endl;

    /*
    *   El primer 4 se imprime lo que ocupa el puntero en el compilador
    *   después se imprime el 12 porque como tenemos 3 elementos enteros
    *   y cada uno tiene 4 bytes, se imprime 12 por la cantidad de bytes
    *   en la línea 10 estamos imprimiendo mi p2, que al comienzo apuntaba 
    *   a la primera posicion de vector, pero al sumarle 2 pasamos a la 
    *   ultima posicion de mi vector, es en esta posicion donde se encuentra 
    *   mi valor 6, y al colocar
    *   antes del p2 hace que imprima el valor que contiene la dirección de 
    *   memoria a la que apunta.   
    */

	return 0;
}
