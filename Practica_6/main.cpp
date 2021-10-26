#include <iostream>
using namespace std;

int suma_mediana_1D( int* vector, int dim1 ){
    int x = (dim1%2==0) ? 1 : 0;

    if(x){
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

void imprimir_1D(int *ptr, int dim1){
  for(int* i = ptr; i < ptr + (dim1); i++){
    cout << *i << '\t';
  }
}
void imprimir_2D(int *ptr, int dim1){    
    int *p= ptr;
    int *q= ptr;
    while (p< (ptr)+(dim1*dim1))
    {
        while (p< q+(dim1))
        {   
            cout<<*p<<'\t';
            p++;
        }
        cout<<endl;
        q = q+dim1;
    }
}
void imprimir_3D(int*ptr, int dim1){
    int*p = ptr;
    int*q = ptr;
    int*s = ptr;
    int cont =1;
    for(; p < ptr+(dim1*dim1*dim1);){
      
        for(; p<q+(dim1*dim1); p++){
            cout << *p << '\t';
            if(cont % dim1 == 0){
              cout << endl;
            }
            cont ++;
            
        }
        cout << endl;
        q = q+(dim1*dim1);
        
    }
}


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

    int* ptr1D = array1D;
    int* ptr2D = *(array2D);
    int* ptr3D = *(*array3D);
    int* punteros[3] = {ptr1D, ptr2D, ptr3D};
    int (*pf[3])(int*, int) = {suma_mediana_1D, suma_mediana_2D, suma_mediana_3D};
    void (*print[3])(int*, int) = {imprimir_1D,imprimir_2D,imprimir_3D};
    int op[3] = {0,1,2};
    int dimensiones[3] = {10,5,6};
    int res = 0;

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
      print[op[i]](punteros[i], dimensiones[i]);
    }
    
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
      res = 0;
      res = pf[op[i]](punteros[i],dimensiones[i]);
      cout << res << endl;
    }
    
    return 0;
}