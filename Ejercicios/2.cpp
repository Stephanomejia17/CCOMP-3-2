#include <iostream>
using namespace std;

int suma_mediana_1D( int* vector, int dim1 );
int suma_mediana_2D( int* array, int dim1, int dim2 );
int suma_mediana_3D();


int main(){
    int vector [] = {10,20,30,40,50,60,70,80,90};
    cout << " SUMA MEDIANA 1D:\n " <<suma_mediana_1D(vector, 9) << endl;

    int array [5][5] = { {1,0,0,0,0},
                         {0,2,0,0,0},
                         {0,0,3,0,0},
                         {0,0,0,4,0},
                         {0,0,0,0,5} };

    cout << " SUMA MEDIANA 2D:\n " << suma_mediana_2D( *array, 5, 5 ) << endl;
    return 0;
}

int suma_mediana_1D( int* vector, int dim1 ){
    int x = (dim1%2==0) ? 1 : 0;

    if(x){ // dim1 es par 
        return *(vector + (dim1/2)-1) + *(vector + (dim1/2));
    }
    else{
        return *(vector + (dim1/2));
    }
}   

int suma_mediana_2D( int *array, int dim1, int dim2 ){
  return 1;
}