#include <iostream>
using namespace std;

int main(){
	int vector[] = {4,5,6};
	int* p1 = vector; //apunta a la primera posición de mi vector
	cout<<sizeof(p1)<<endl;
	cout<<sizeof(vector)/sizeof(vector[0])<<endl;
	int* p2 = vector + 2;
	cout<< *p2<<endl;

    /*
    *
    *   en la línea 8 había un error, lo que estaba pasando era que nmo estabamos dividiendo el sizeof de vector entre
    *   el sizeof de vector en la posición 0, como sabemos si no se hace de esta forma no nos da el tamaño real de nuestro
    *   vector, en la línea 10 estamos imprimiendo mi p2, que al comienzo apuntaba a la primera posicion de vector, pero al
    *   sumarle 2 pasamos a la ultima posicion de mi vector, es en esta posicion donde se encuentra mi valor 6, y al colocar
    *   * antes del p2 hace que imprima el valor que contiene la dirección de memoria a la que apunta.   
    */

	return 0;
}
