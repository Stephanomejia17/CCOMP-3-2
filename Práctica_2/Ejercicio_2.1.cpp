#include <iostream>
using namespace std;


int funcion1(int n, int m);
int funcion2(int &n, int &m);
int funcion3(const int & n, const int &m);
int main() {
    int a, b;
    a = 10;
    b = 20;
    std::cout << "a,b ->" << a << ", " << b << std::endl;
    std::cout << "funcion1(a,b) ->"<< funcion1(a, b) << std::endl;
    std::cout << "a,b ->" << a << ", " << b << std::endl;
    std::cout << "funcion2(a,b) ->"<< funcion2(a, b) << std::endl;
    std::cout << "a,b ->" << a << ", " << b << std::endl;
    std::cout << "funcion3(a,b) ->"<< funcion3(a, b) << std::endl;
    ::cout << "a,b ->" << a << ", " << b << std::endl;
    
    return 0;
}
int funcion1(int n, int m) {
    n = n + 2;//12
    m = m - 5;//15
    return n+m;//27
}
int funcion2(int &n, int &m) {
    n = n + 2;
    m = m - 5;
    return n+m;
}
int funcion3(const int &n, const int &m) {
    int a = n + 2;
    int b = m - 5;
    return a+b;
}

/*
    Primero imprimimos nuestros valores de a y b, luego estamos pasándolos por nuestra funcion 1, volvemos a imprimir mis valores de a y b
    luego pasamos a y b por la función 2, pero como estamos haciendo un paso por referencia los valores de mis variables cambian, a se suma
    en 2 y b se resta en 10, después nuevamente estamos imprimiendo mis valores de a y b, después pasamos mis valores ya modificados por mi
    función 3, y al ser constantes, sus valores no se modifican, y finalmente imprimimos nuevamente los valores de a y b
*/
