#include <iostream>
using namespace std;

//Array 3D con varios Arrays (Ejemplo en iPad)
int X = 2;
int Y = 3;
int Z = 4;

int main(){
    int*** A = new int**[X];
    //Creacion
    for(int i = 0; i < X; i++){
        A[i] = new int*[Y];
        for(int j = 0; j < Y; j++){
            A[i][j] = new int[Z];
        }
    }
    //Asignacion de valores
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            for(int k = 0; k < Z; k++){
                A[i][j][k] = 5;
            }
        }
    }
    //Imprimir
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            for(int k = 0; k < Z; k++){
                cout << A[i][j][k];
            }
            cout << "\n";
        }
        cout << "\n\n";
    }
    //delete
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            delete[] A[i][j];
        }
        delete[] A[i];
    }
    delete[] A;


    return 0;
}