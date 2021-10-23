#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;


/*
TIGRE
A   G   M   U   S   S   O   P   A   A   S   O
G   P   P   M   R   W   A   R   T   V   O   G
O   T   T   E   E   G   I   E   U   R   E   R
H   I   P   P   O   R   O   T   A   M   U   S
E   A   E   I   A   G   G   G   I   I   T   Z
G   P   P   T   P   A   N   I   A   G   T   E
P   A   N   T   E   R   A   I   T   I   E   B
E   E   L   P   K   E   E   A   M   R   R   R
T   D   O   D   R   A   P   O   E   L   F   A
A   L   T   A   K   R   E   E   M   F   L   T
C   J   A   R   E   P   E   G   H   T   W   U
Y   U   K   E   E   T   H   C   X   S   D   J
*/
int main(){
    ifstream letras("sopa.txt"); //Cargamos mi archivo
    char Palabra [12];
    char Sopa [12][12];
    char *ptr = Sopa[0];
    char (*ptrSopa)[12] = Sopa;
    char *ptrPalabra = Palabra;
    int h = 1;
    int cont = 0;
    char PPalabra = *(ptrPalabra); // T
    char (*ptr2Sopa)[12] = ptrSopa;
    int TamPalabra = (sizeof(Palabra)/sizeof(Palabra[0])); //12
    bool encontrado = false;
    
    //Asignamos la Palabra a ser buscada a mi variable y el resto a mi sopa de letras
    letras >> Palabra; 
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12;j++){
            letras >> Sopa[i][j]; 
        }

    }

    //Imprimimos la palabra que buscaremos y la sopa de letras
    cout << "La palabra a buscar es: ";
    while(*ptrPalabra != '\0'){
        cout << *(ptrPalabra++);
    }
    cout << endl;
    cout << "La sopa de letras es: " << endl;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12;j++){
            cout << Sopa[i][j]; 
        }
        cout << endl;
    }


    //Buscamos la Palabra en mi sopa de letras
    while(!encontrado){
        

        //horizontales
        while((*(*ptrSopa) == *ptrPalabra) && (h < TamPalabra)){
            if( ((*(*ptrSopa))+h) == *(ptrPalabra + h)  ){
                h++;
                cont++;
            }
            else if( ((*(*ptrSopa))-h) == *(ptrPalabra + h)  ){
                h++;
                cont++;
            }
            else{
                h = 1;
                cont = 0;
                break;
            }
        }

        //Verticales
        while((*(*ptrSopa) == *ptrPalabra) && (h < TamPalabra)){
            if( ((*(*ptrSopa))+10) == *(ptrPalabra + h)  ){
                h++;
                cont++;
            }
            else if( ((*(*ptrSopa))-10) == *(ptrPalabra + h)  ){
                h++;
                cont++;
            }
            else{
                h = 1;
                cont = 0;
                break;
            }
        }

        //Diagonales
        while((*(*ptrSopa) == *ptrPalabra) && (h < TamPalabra)){
            if( ((*(*ptrSopa)+13)) == *(ptrPalabra + h)  ){
                h++;
                cont++;
            }
            else if( ((*(*ptrSopa)-13)) == *(ptrPalabra + h)  ){
                h++;
                cont++;
            }
            else if( ((*(*ptrSopa)+11)) == *(ptrPalabra + h)  ){
                h++;
                cont++;
            }
            else if( ((*(*ptrSopa)-11)) == *(ptrPalabra + h)  ){
                h++;
                cont++;
            }
            else{
                h = 1;
                cont = 0;
                break;
            }
        }

        if(cont == TamPalabra){
            encontrado = true;
        }


          
      
    }
    

    cout << cont;
    



    //Intentos:

    /*while(*(*ptrSopa)!='\0' && cont <= TamPalabra){
        if(*(*ptrSopa)==PPalabra){
          ++ptrPalabra;
          cont += 1; //Encontro una letra
          //Horizontal Derecha
          while(*(*ptrSopa+cont) == *ptrPalabra){
            cont++;
            ptrPalabra++;

          }
          //Horizontal Izquierda
          while(*((*ptrSopa)-cont) == *ptrPalabra){
            cont++;
            ptrPalabra++;
          }

          //Vertical
          

        }
        *(*ptrSopa++);
        
    }
    //cout << Sopa;*/
    /*for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if((*(*ptrSopa)+j) == *(Palabra+j)){
                cont++;
            }
            else if((*(*ptrSopa)-j) == *(Palabra+j)){
                cont++;
            }






        }
    }*/
    
    return 0;

}