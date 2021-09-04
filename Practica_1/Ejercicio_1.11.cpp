#include <iostream>
using namespace std;

int main(){
	int a = 1070;
    char* pc;
    char*& rpc = pc;
    rpc = (char*)&a;
    cout<<*(pc);
    cout<<*(rpc);

    /*
    *   Aquí estamos viendo que tenemos un valor entero, uno de tipo char y otro que referencia a mi valor char, lo que quiere decir es que
    *   rpc = pc = (char*)&a, esta última parte se pone para que mi valor de 'a' (1070) se "convierta" en un valor char, después de esto
    *   imprimimos el valor que contiene mi pc, el cual es 1070 pero al "convertirlo" en char obtenemos un '.', finalmente como rpc y pc son 
    *   iguales, imprimimos el mismo valor 2 veces
    */


}