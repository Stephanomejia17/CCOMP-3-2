#include <iostream>
using namespace std;

int main(){
	int a = 1500;//direcci´on asignada 208
    int* p = &a; //direcci´on asignada 200
    int*& c = p;
    cout<<*(&(*(c+1)));


    /*
    *   Para empezar vemos que c = p y p = 208, más abajo, en la línea 8 vemos que mi & y * se pueden anular, por lo tanto,
    *   nos queda un *, el cuál imrprime el valor aumentado en 1 de c, o sea el valor que se encuentra en la posición 212,
    *   por lo tanto se imprime basura.
    */
}