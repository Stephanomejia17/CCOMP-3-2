//Paso de punteros a metodos por parametros
#include <iostream>
using namespace std;
class Operacion{
    public:
    int dato;
    int suma(int a, int b){
        return a+b;
    }
    int mult(int a, int b){
        return a*b;
    }
};

int llamada(Operacion* pO ,int (Operacion::*pm)(int,int), int a, int b ){
    //return (*pO.*pm)(a,b); //o tambien podemos usar:
    return (pO->*pm)(a,b);
}

int main(){
    Operacion op;
    int (Operacion::*p) (int,int) = &Operacion::suma; //Va a ser igual al metodo suma
    //Para ejecutar este metodo por medio de p
    cout << llamada(&op,p,3,7) << endl;
    //cout << (op.*p)(5,4) << endl; //5 + 4 = 9

    return 0;
}