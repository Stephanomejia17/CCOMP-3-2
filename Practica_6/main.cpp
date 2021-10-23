#include <iostream>
using namespace std;

int suma_mediana_1D( int* vector, int dim1 ){
    int x = (dim1%2==0) ? 1 : 0;

    if(x){ // dim1 es par 
        return *(vector + (dim1/2)-1) + *(vector + (dim1/2));
    }
    else{
        return *(vector + (dim1/2));
    }
}
int suma_mediana_2D( int* ptr, int dim1){
  int res = 0;
  for(int* i = ptr ; i < ptr + (dim1*dim1) ; i += dim1+1){
    res += *i;
  }
  return res;
}

int suma_mediana_3D(int * ptr, int dim1){
  int res = 0;
  for(int* i = ptr; i < ptr + (dim1*dim1*dim1); i += ((dim1*dim1)+dim1+1)){
    res += *i;
  }
  return res; 
}

/*void imprimir(int *ptr, int dim1){
  for(int* i = ptr; i < ptr + ())
}*/


int main(){
    int array1D [] = {10,20,30,40,50,60,70,80,90,100};
    int array2D [5][5] = {{1,0,0,0,0},
                        {0,2,0,0,0},
                        {0,0,3,0,0},
                        {0,0,0,4,0},
                        {0,0,0,10,5}};    
    int array3D [6][6][6] = {{ {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} },
                             { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} },
                             { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} },
                             { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} },
                             { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} },
                             { {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} }};

    cout << suma_mediana_1D(array1D, 10) << endl;
    cout << suma_mediana_2D(*(array2D), 5) << endl;
    cout << suma_mediana_3D(*(*(array3D)), 6) << endl;
    
    int (*pf[3])(int*,int) = {suma_mediana_1D, suma_mediana_2D,suma_mediana_3D};
    
    return 0;
}
//+13
/*
for(; *ptrColumnas < *ptrColumnas + (dim1); ptrColumnas++){
      
    }
*/
