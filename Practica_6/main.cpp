#include <iostream>
using namespace std;
/*Buenas profesoor, en este codigo que implemente he intentado seguir todo tal cual lo puso en la actividad, mis funciones unicamente
 reciben un puntero a mi array, y una dimension, solo recibe una dimension porque recuerdo que en la anterior clase indico que los 
 arrays debian ser "cuadrados", entonces al ser cuadrados, unicamente me hace falta tener una de sus dimensiones, asi es mas simple 
 tambien para poder poner todas mis funciones en un solo array, y tambien para poder tener una forma "universal" de mis funciones.*/

//Esta es mi Suma Mediana para arrays 1D
int suma_mediana_1D( int* vector, int dim1 ){
    int x = (dim1%2==0) ? 1 : 0; //Verificacion de la dimension, si es par su valor sera 1, de lo contrario sera 0

    if(x){
        return *(vector + (dim1/2)-1) + *(vector + (dim1/2)); //Este es una simple formula para calcular la suma mediana en caso de que la dimension sea par
    }
    else{
        return *(vector + (dim1/2)); //Y esta por lo contrario es una formula para calcular la suma mediana cuando la dimensio es impar
    }
}

//Suma Mediana para arrays 2D
int suma_mediana_2D( int* ptr, int dim1){
  int res = 0;
  for(int* i = ptr ; i < ptr + (dim1*dim1) ; i += dim1+1){ //Como puede ver, mi i esta iterando segun mi dimension aumentado en 1, esto lo puse asi porque en mi array 2D la suma mediana es la diagonal de la misma
    res += *i; //Aqui le estoy sumando todos los valores que se encuentran en mi diagonal principal
  }
  return res;
}

//Suma Mediana para arrays 3D
int suma_mediana_3D(int * ptr, int dim1){
  int res = 0;
  for(int* i = ptr; i < ptr + (dim1*dim1*dim1); i += ((dim1*dim1)+dim1+1)){ //La logica que emplee para este calculo es muy similar a la de mis arrays 2D
    res += *i;//Sumamos a res todos los valores que estan en mi diagonal
  }
  return res; 
}

//Impresion de arrays 1D
void imprimir_1D(int *ptr, int dim1){
  for(int* i = ptr; i < ptr + (dim1); i++){
    cout << *i << '\t'; //Una impresion simple para mis arrays 1D, le puse un tab para que se vea mejor
  }
}

//Impresion de arrays 2D
void imprimir_2D(int *ptr, int dim1){    
    int *p= ptr;
    int *q= ptr;
    while (p< (ptr)+(dim1*dim1))
    {
        while (p< q+(dim1)) //hace que mi p itere unicamente dentro de una fila, luego cuando la condicion no se cumpla
        {   
            cout<<*p<<'\t';
            p++;
        }
        cout<<endl; // se imprime un salto de linea para imprimir el resto de mi array
        q = q+dim1; // q aumenta y se posiciona en mi siguiente fila
    }
}
//Impresion de arrays 3D
void imprimir_3D(int*ptr, int dim1){
    int*p = ptr;
    int*q = ptr;
    int*s = ptr;
    int cont = 1;
    for(; p < ptr+(dim1*dim1*dim1);){
      
        for(; p<q+(dim1*dim1); p++){ //Esta logica es muy similar al de arrays 2D, pues me guie un poco de esa funcion
            cout << *p << '\t';
            if(cont % dim1 == 0){ //Esto simplemente es para que la impresion sea mas estetica
              cout << endl;
            }
            cont ++;
            
        }
        cout << endl;
        q = q+(dim1*dim1);
        
    }
}

typedef int (*PF)(int*, int);

int calculo(PF pf, int* ptr, int dim){ //Esta funcion va a recibir por parametro una funcion, puede ser suma_mediana_1D, suma_mediana_2D o suma_mediana_3D, tambien recibe mi puntero a mis arrays de distintas dimensiones y las dimensiones
  int res = pf(ptr,dim); //Aqui almacenamos los resultados de cada funcion en res
  return res;
}

int main(){
    int array1D [] = {10,20,30,40,50,60,70,80,90,100};
    int array2D [5][5] = {{1,0,0,0,0},
                        {0,2,0,0,0},
                        {0,0,3,0,0},
                        {0,0,0,4,0},
                        {0,0,0,10,5}};    
    int array3D [6][6][6] = {{ {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} },
                             { {1,2,3,4,5,6},{7,10,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} },
                             { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,20,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} },
                             { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,30,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} },
                             { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,40,30},{31,32,33,34,35,36} },
                             { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,50} }};

    int* ptr1D = array1D;
    int* ptr2D = *(array2D);
    int* ptr3D = *(*array3D);
    int* punteros[3] = {ptr1D, ptr2D, ptr3D};
    int* (*puntPunteros) = punteros;

    PF PuntFun[3] = {suma_mediana_1D, suma_mediana_2D, suma_mediana_3D};
    PF *ppff = PuntFun;

    void (*print[3])(int*, int) = {imprimir_1D,imprimir_2D,imprimir_3D};
    int op[3] = {0,1,2};
    int* ptrOp = op;
    int dimensiones[3] = {10,5,6};
    int* puntDim = dimensiones;
    int res = 0;

    //Aqui estoy utilizando unos condicionales solo para que la impresion de mis arrays se vean de forma ordenada, con una separador que indica el inicio de cada array 
    for(int i = 0; i < 3; i++){
      if(i == 0){
        cout << "\nArray 1D: " << endl;
      }
      else if(i == 1){
        cout << "\nArray 2D: " << endl;
      }
      else{
        cout << "\nArray 3D: " << endl;
      }

      print[*(ptrOp+i)](*(puntPunteros+i), *(puntDim+i)); //Aqui pasamos cada uno de mis arrays y sus dimensiones para poder imprimirlas en el display
    }
    

    //Nuevamente aqui estoy usando condicionales unicamente para que se vea de manera mas estetica y se distinga cada uno de los resultados
    for(int i = 0; i < 3; i++){
      if(i == 0){
        cout << "Suma Mediana 1D: " << endl;
      }
      else if(i == 1){
        cout << "Suma Mediana 2D: " << endl;
      }
      else{
        cout << "Suma Mediana 3D: " << endl;
      }
      res = 0; //Aqui establezco que cada vez que se itere res sea 0, ya que res sera el resultado de cada una de mis funciones, si no colocamos esta linea, el valor de la suma mediana 1D se sumaria con la suma mediana 2D e igualmente con la 3D
      res = calculo(*(ppff+i), *(puntPunteros+i), *(puntDim+i)); //Almacenamos los calculos de sumas medianas en mi res
      cout << res << endl;//y finalmente imprime los resultados en pantalla
    }
    
    return 0;
}