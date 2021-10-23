#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

void leer_archivo(char *p,char q [6][6][7]){    
    ifstream archivo("sopa3D.txt");
    archivo >> p;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            archivo >> q[i][j];
        }
    }
}
void imprimir(char* sopa, int dim1, int dim2, int dim3){
    char*ptrsopa = sopa;
    char*ptr2sopa = sopa;
    char*s = sopa;
    int cont =1;

    cout << "PLANOS: " << endl;
    for(; ptrsopa < sopa+(dim3*dim2*dim1);){
      
        for(; ptrsopa<ptr2sopa+(dim3*dim2); ptrsopa++){
            cout << *ptrsopa;
            if(cont % 7 == 0){
              cout << endl;
            }
            cont ++;
            
        }
        cout << endl;
        ptr2sopa = ptr2sopa+(dim3*dim2);
        
    }
}
    
    

void iterar(char (*p)[6][7],char *q, char *s ,char* sopa,  char* palabra,int tamPalabra, int dim1, int dim2, int dim3, bool& encontrar, int operacion){
  char* ptrsopa = sopa;
  char* ptr2sopa = sopa;
  char *ptrpalabra = palabra;
  

  if(encontrar == false){
    char *temp = q;
    int contador = 0;
    for(; ptrpalabra < palabra+tamPalabra; ptrpalabra++){
      if(encontrar == true){
        break;
      }
      if(*temp != *ptrpalabra){
        break;
      }
      if(*temp == *ptrpalabra){
        contador++;
      }
      if(contador == tamPalabra){
        encontrar = true;
        //cout << " (" << (((*(*(*(q)))) - r)/7) + 1 << ", " << () 
        cout << "hola se encontro la palabra";
        break;
      }
      temp = temp + operacion;

      
    }
  }
  

  
}

int main(){

    char sopa[6][6][7];
    char palabra[7];
    char (*ptrSopa)[6][7] = sopa;
    char *q = *(*(sopa));
    char *s = *(*(sopa));
    int tamPalabra = strlen(palabra);

    int dim1=6;
    int dim2=6;
    int dim3=7;

    bool encontrar = false;
    leer_archivo(palabra, sopa);
    imprimir(*(*(ptrSopa)),6,6,7);
    //iterar(*(*(ptrSopa)),palabra,6,6,7, encontrar, +43);
    for(char (*p)[6][7] = sopa; p < sopa + (dim1*dim2*dim3); p++){
      while(q < *(*(sopa)) + 6){
        while(*s < *(*(*(sopa))) + 7){
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, +43); //Hacia Derecha
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, -43); //Hacia Izquierda
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, +35); //Hacia Arriba
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, -35); //Hacia Arriba
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, +49); //Hacia Abajo
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, -49); //Hacia Abajo
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, +36); // Hacia Diagonal Derecha Arriba
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, -36); // Hacia Diagonal Derecha Arriba
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, +34); // Hacia Diagonal Izquierda Arriba
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, -34); // Hacia Diagonal Izquierda Arriba
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, +50); // Hacia Diagonal Derecha Abajo
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, -50); // Hacia Diagonal Derecha Abajo
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, +48); // Hacia Diagonal Izquierda Abajo
          iterar(p,q,s, (*(*(ptrSopa))),palabra,tamPalabra,6,6,7, encontrar, -48); // Hacia Diagonal Izquierda Abajo
        }
        s = q;
      }
      q = *(*(p));
    }
    if(encontrar == true){
      cout << "Palabra encontrada";
    }
    else{
      cout << "-1, -1, -1";
    }
    
    
      


}