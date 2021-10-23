// PunteroFuncionApp2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

void blanquear(int* ini, int* fin)
{
    while (fin > ini)
    {
        *ini = 0;
        *fin = 0;
        ini++;
        fin--;
    }
}

bool par(int a)
{
    return !(a % 2);
}

bool impar(int a)
{
    return (a % 2);
}

bool multiplo3(int a)
{
    return !(a % 3);
}

void split1(int *origen, int *dest1, int *dest2, int elem)
{
    for (int* p = origen; p < origen + elem; p++)
    {
        if (*p % 2)
        {
            *dest1 = *p;
            dest1++;
        }
        else
        {
            *dest2 = *p;
            dest2++;
        }
    }
}
void split2(int* origen, int* dest1, int* dest2, int elem, bool (*pf)(int))
{
    for (int* p = origen; p < origen + elem; p++)
    {
        if (pf(*p))
        {
            *dest1 = *p;
            dest1++;
        }
        else
        {
            *dest2 = *p;
            dest2++;
        }
    }
}

int main()
{
    int a[10] = { 11, 20, 30, 25, 14, 66, 43, 34, 70, 90 };
    int b[10], c[10];

    blanquear(b, b + 9);
    blanquear(c, c + 9);

    split1( a, b, c, 10);
    for (int i = 0; i < 10; i++)
        cout << b[i] << " ";
    cout << endl;

    for (int i = 0; i < 10; i++)
        cout << c[i] << " ";

    blanquear(b, b + 9);
    blanquear(c, c + 9);

    split2(a, b, c, 10,par);

    cout << endl <<"Primero pares luego impares" << endl;
    for (int i = 0; i < 10; i++)
        cout << b[i] << " ";
    cout << endl;

    for (int i = 0; i < 10; i++)
        cout << c[i] << " ";

    blanquear(b, b + 9);
    blanquear(c, c + 9);

    split2(a, b, c, 10, impar);

    cout << endl << "Primero impares luego pares" << endl;
    for (int i = 0; i < 10; i++)
        cout << b[i] << " ";
    cout << endl;

    for (int i = 0; i < 10; i++)
        cout << c[i] << " ";

    split2(a, b, c, 10, multiplo3);

    cout << endl << "Primero multiplos de 3 y despues no multiplos de 3" << endl;
    for (int i = 0; i < 10; i++)
        cout << b[i] << " ";
    cout << endl;

    for (int i = 0; i < 10; i++)
        cout << c[i] << " ";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
