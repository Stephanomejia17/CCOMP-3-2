#include <iostream>
using namespace std;

int main(){
	int a = 15; // Direcci´on asignada 204
    int* p = &a; // Direcci´on asignada 200
    int*&q = p;
    q++;
    cout<<*q;
    /*
    *   Para empezar tuve que arreglar el código, cambié la línea 7 porque estaba declarándose una variable de forma incorrecta, luego haciendo mi gráfico
    *   me di cuenta que cuando a 'q' le aumentamos 1 (4 bytes) apuntamos a la posición 208, la cual no tiene nada asignado, por lo tanto lo que se imprime
    *   es basura
    */

}