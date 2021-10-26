#include <iostream>

using namespace std;

int suma(int* p, int* q)
{  
  return *p + *q;
}

int multiplicacion(int* p, int* q)
{ 
  return *p * *q;
}

void imprimir(int *ini, int *fin)
{
	for(int *p=ini; p<=fin; p++)
		cout<<*p<<" ";
	cout<<endl;
}

void calcular1(int (*pf)(int*,int*),int* a) {
  /*To Complete*/
}

void calcular2(int (*pf)(int*,int*),int* a) {
  /*To Complete*/
}

int main() {
    int (*pf1[2])(int*,int*) = {suma,multiplicacion};
    void (*pf2[2])(int (*pf)(int*,int*),int*) = {calcular1,calcular2};

    int (*ppff1)(int(*a[2])(int*,int*)) = pf1;
    void (*ppff2) = pf2;
      
    int num[9]= {2,5,3,1,0,6,1,3,7};
    int op1[9]= {0,0,1,0,0,0,0,1,0};
    int op2[9]= {0,1,0,0,1,0,0,1,0};

    int *pnum = num+2;
    int *pop1 = op1+2;
    int *pop2 = op2+2;

    cout<<"ARRAY INICIAL"<<endl;
    imprimir(num, num+8);
    cout<<"--------------------------------------"<<endl;
   for(int i =2; i <9; i++)
     {        
       (*(ppff2+(*pop2)))(*(ppff1+(*pop1)),pnum);
       pnum++;
       pop1++;
       pop2++;
     }
    cout<<"ARRAY FINAL"<<endl;
    imprimir(num, num+8);
    return 0;
}