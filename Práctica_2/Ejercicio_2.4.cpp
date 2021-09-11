#include <iostream>
using namespace std;

int main(){
    
int x = 10;
char y = 'F';   //Aquí daba error porque se estaba asignando mi cariable de forma incorrecta 
int * a = &x;
char * b = &y;
void* c;
c = b;
cout<< (*c) <<"\n";
int & z; //Aquí falta asignarle el valor, por eso da error

}