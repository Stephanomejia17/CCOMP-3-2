#include <iostream>

int main(){
    //MALLOC
    /*int* res = (int*)malloc(5*sizeof(int)); //array de 5 enteros
    res[0]=1;
    res[1]=3;*/
    //CALLOC
    /*int* res = (int*)calloc(5,sizeof(int)); //calloc inicializa las variables, mientras que malloc les asigna basura
    res[0]=1;
    res[1]=3;*/
    //REALLOC
    int* res = (int*)malloc(5*sizeof(int)); 
    res[0]=1;
    res[1]=3;
    res = (int*)realloc(res,10*sizeof(int)); //Array de 10 enteros
}