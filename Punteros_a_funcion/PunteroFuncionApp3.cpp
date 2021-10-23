// PunteroFuncionApp3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

float cuadrado(float *lado)
{
    return *lado * *lado;
}

float triangulo(float *param)
{
    return (*param *  *(param+1))/2;
}

float circulo(float *radio)
{
    return (3.1416 * *radio * *radio);
}
void ejecuta(float (*pf[3])(float*), char (*mensaje)[10], float(*param)[2], int n)
{
    for (int i = 0; i < n; i++, mensaje++, param++)
    {
        cout << " el area del " << *mensaje << " es ";
        cout << pf[i](*param) << endl;
    }
}

int main()
{
    float (*pf[3])(float*) = { cuadrado, triangulo, circulo };
    char mensaje[3][10] = { "cuadrado", "triangulo", "circulo"};
    float param[3][2] = { {4,1000}, {40,35}, {30,-1} };
    
    for (int i = 0; i < 3; i++)
    {
        cout << " el area del " << mensaje[i] << " es ";
        cout << pf[i](param[i]) << endl;
    }
    cout << "---------------------" << endl;
    ejecuta(pf, mensaje, param, 3);
    
    cout << "Calculando el área del cuadrado de otra forma" << endl;
    float a = 100;
    cout << pf[0](&a);

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
