// PunteroFuncion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

int suma(int a, int b)
{
    return a + b;
}

int resta(int a, int b)
{
    return a - b;
}

void tabla(int a, int (*p)(int, int))
{
    for (int i = 1; i < 11; i++)
        cout << a << " con " << i <<" = " << p(a, i) << endl;
}

int main()
{
    int a = 10, b = 7;
    
    //int* p; puntero a entero
    //int* p[3];  un array de 3 punteros a enteros
    //int(*p)[3]; un puntero a arrays de enteros de 3 elementos
    //int* p(int, int); p es una función, que recibe 2 enteros y devuelve un puntero a enteros
    int (*p)(int, int); //p es un puntero a funciones que devuelven un entro y reciben 2 enteros
    int (*q[3])(int, int); // p es un array de 3 punteros a funciones

    q[0] = suma;
    q[1] = resta;

    cout << suma(a, b) << endl;
    cout << resta(a, b) << endl;

    cout << "----------------------" << endl;
    p = &suma;
    cout << (*p)(a, b) << endl;
    p = &resta;
    cout << (*p)(a, b) << endl;

    cout << "----------------------" << endl;
    p = suma;
    cout << p(a, b) << endl;
    p = resta;
    cout << p(a, b) << endl;

    cout << "----------------------" << endl;
    p = &suma;
    cout << p(a, b) << endl;
    p = resta;
    cout << (*p)(a, b) << endl;

    cout << "----------------------" << endl;
    cout << &suma << endl;
    cout << &resta << endl;
    cout << &a << endl;
    cout << &b << endl;

    cout << "----------------------" << endl;
    tabla(10, suma);
    cout << "----------------------" << endl;
    tabla(10, resta);
    cout << "----------------------" << endl;
    cout << q[0](13, 8) << endl;
    cout << q[1](13, 8) << endl;
    cout << "----------------------" << endl;
    tabla(10, q[0]);//tabla(10, suma);
    cout << "----------------------" << endl;
    tabla(10, q[1]);//tabla(10, resta);
    cout << "----------------------" << endl;
    tabla(10, *q);//tabla(10, suma);
    cout << "----------------------" << endl;
    tabla(10, *(q+1));//tabla(10, suma);

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
