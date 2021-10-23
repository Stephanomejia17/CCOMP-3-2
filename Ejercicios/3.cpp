//Cree una funcion llamada "Mezcla" que reciba un array de enteros
//que este ordenado parcialmente ordenado, un puntero al ultimo elemento
//ordenado y que termine de ordenar el array
//Ej. 2, 7, 14, 18, 19, 28, 30, 21 -> 2,7,14,18,19,21,18,30

#include <iostream>
using namespace std;

int swap0(int* a, int* b){
    int t=*a;
    *a=*b;
    *b=t;
    return 0;
}


int cocktail_sort(int *a, int n){
    for(int* j=a; j<a+n; j++){
        for(int* b = a; b <a+n-1 ; b++){
            if( *b > *(b+1)){
                swap0( b, 1+b );}
                }
        ++j;
        for(int* b=a-1+n ; b > a ; b--){
            if( *b < *(b-1)){
                swap0( b, b-1 );}}
                }
    return 0;}

int main()
{
    int a[9]={3,7,8,6,5,4,9,2,1};

    cocktail_sort(a,9);



    for(int i=0; i<9; i++){
            cout<<a[i]<<"  ";}
    return 0;
}