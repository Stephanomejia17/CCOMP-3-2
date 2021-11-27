#include <iostream>
using namespace std;

int main(){
    int x = 2;
    int y = 3;
    int z = 4;
    int* A = new int[x*y*z];

    for(int i = 0; i < x; i++){
        for(int  j = 0; j <y; j++){
            for(int k = 0; k < z; k++){
                *(A+(i*y*z)+j*z+k) = 5;

            }
        }
    }
    for(int i = 0; i < x; i++){
        for(int  j = 0; j <y; j++){
            for(int k = 0; k < z; k++){
                cout << *(A+(i*y*z)+j*z+k);
            }
            cout << "\n";
        }
        cout << "\n\n";
    }

    delete[] A;
    return 0;
}