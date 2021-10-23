// PunteroFuncionApp1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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

int multi(int a, int b)
{
    return a * b;
}

int negativo(int a)
{
    return -a; 
}

int main()
{
    int num[10] = { 13, 20, 8, 33, 35, 70, 43, 4, 19, 55 };
    int (*p[4])(int, int) = { suma, resta, multi };
    int oper[10] = { 0,2,1,0,1,2,2,0,1,1 };
    int result = 0;
    
    for (int i = 0; i < 10; i++)
    {
        result = p[oper[i]](result, num[i]);
        cout << result << endl;
    }

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
