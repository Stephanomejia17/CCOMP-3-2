#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;



int main(){
    ifstream letras("sopa.txt"); //Cargamos mi archivo
    char Palabra [12];
    char Sopa [12][12];
    char **ptrSopa = Sopa;
    char *ptrPalabra = Palabra;
aaa

    int ultimapos = (sizeof(Palabra)/sizeof(Palabra[0]));
    
    letras >> Palabra; //asignamos el primer conjunto de letras a Palabra

    //asignamos el resto de mis letras a Sopa
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12;j++){
            letras >> Sopa[i][j]; 
        }

    }

    cout << "La palabra a buscar es: " << Palabra<<endl; //Imprimimos la palabra buscada

    //Imprimimos la sopa de letras
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12;j++){
            cout << Sopa[i][j]; 
        }
        cout << endl;
    }
    


    
    
    
}


