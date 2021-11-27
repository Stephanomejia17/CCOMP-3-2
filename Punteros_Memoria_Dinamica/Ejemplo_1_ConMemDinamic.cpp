#include <iostream>

using namespace std;

void imprimir(){
    printf("Hola\n");
}

int* Add(int *a, int *b){
    int* res = (int*)malloc(sizeof(int));
    *res = (*a) + (*b);
    return res;
}
int main(){
    int a=2, b=5;
    int* p = Add(&a,&b);
    imprimir();
    printf("Suma= %d\n", *p);
    free(p);
    return 0;
}