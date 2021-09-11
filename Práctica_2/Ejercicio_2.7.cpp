#include <iostream>
using namespace std;

int main(){
    /*Agregue una instrucci´on para imprimir usando ”p.el primer telefono del array emergencia”. Tambi´en incremente el puntero ”p”para con ´el acceder al cuarto elemento
    del array ”telefonos”:*/
char* telefonos[] = {"223322", "554433","667788","441122"};
char** emergencia[] = {&(telefonos[1]),&(telefonos[2])};
char** p = telefonos;



}