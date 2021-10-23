#include <iostream>
using namespace std; 

int suma(int a, int b)
{
    return a+b;
}

int resta(int a, int b)
{
    return a-b;
}

typedef int (*PFU)(int,int);

int main()
{
    //ALTERNATIVA CON USO DE INDICES
    int (*pf[2])(int, int) = { suma, resta };
    int num[10] =   {10,15,5,38,39,77,100,45,48,3};
    int op[10] =    {0,0,1,0,1,0,0,1,1,0}; // 0 = suma, 1 = resta
    int res = 0; 

    // sumas y restas secuenciales
    for(int i = 0; i < 10 ;i ++){
        res = pf[op[i]](res, num[i]);
        cout << res << "\n";
    }
    
    cout << "\n";

    // ALTERNATIVA CON USO DE PUNTEROS 
    PFU(*p) = pf; // puntero a cada elemento de array op  DOBLE PUNTERO
    int *pop = op;
    int *pnum = num;

    res = 0; 

    // sumas y restas secuenciales
    for(int i = 0; i < 10 ;i ++){
        if(*pop)
            p++;
        res = (*p)(res, *pnum);
        if(*pop)
            p--;
        cout << res << "\n";
        pop++;
        pnum++;
        
    }
    return 0;
}