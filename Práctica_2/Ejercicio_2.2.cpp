#include <iostream>
using namespace std;

// ¿Cuantos bytes adicionales se est´an ocupando en la memoria en cada llamada?
struct sampleData {
    int N=6;
    int M=7;
    int O=8;
};
int funcion1(sampleData d){
    std::cout<<sizeof(d)<<std::endl;
    return d.N;
}
int funcion2(sampleData & d){
    std::cout<<sizeof(d)<<std::endl;
    return d.N;
}
int funcion3(sampleData * d){
    std::cout<<sizeof(d)<<std::endl;
    return (*d).N;
}
int main() {
    sampleData data;
    std::cout<<funcion1(data)<<std::endl;
    std::cout<<funcion2(data)<<std::endl;
    std::cout<<funcion3(&data)<<std::endl;
    
}

//Se usan de más 8 bytes en cada llamada de nuestras funciones