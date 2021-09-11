#include <iostream>
using namespace std;

int main(){
    /*Agregue una instrucci´on para imprimir el valor de x desde p2 y una instrucci´on
    para modificar el valor de x a 10 desde p3:*/
int x = 5;
int * p1 = &x;
int ** p2 = &p1;
int *** p3 = &p2;

cout << **p2 << endl;
***p3 = 10;
cout << **p2 << endl;
}