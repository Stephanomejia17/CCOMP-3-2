#include <iostream>
using namespace std;

int main(){
	int a = 1100;
    char* pc;
    pc = (char*)&a;
    printf("%d\n",*(pc+1));

    /*
    *   Aquí como sabemos, un entero ocupa 4 bytes, un char ocupa 1 byte, entonces cuando apuntamos 
    *   un puntero a char hacia un entero lo que estamos haciendo es tomar el valor que se encuentra
    *   en la primera posición de mi conjunto de bytes de mi 'a', pero líneas más abajo nos indica que 
    *   al momento de imprimir se sume uno a mi 'pc', lo que significa que tomarría el valor que se encuentra
    *   en el segundo byte de mi conjunto de bytes de 'a'.
    */

}