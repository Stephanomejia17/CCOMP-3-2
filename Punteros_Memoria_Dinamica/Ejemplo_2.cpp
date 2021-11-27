#include <iostream>

using namespace std;

int main()
{
    int f = 4; int c = 2;
    int *M= new int[f*c];
  
    int *p_M = M;
    int *p_2M = M;
    while(p_M< M + f*c)
    {
        while(p_2M < p_M + c )
        {
            *p_2M = 5;
            p_2M ++;
        }
        p_M = p_M + c;
    }
    p_M = M;
    p_2M = M;
    while(p_M< M + f*c)
    {
        while(p_2M < p_M + c )
        {
            cout<<*p_2M;
            p_2M ++;
        }
        cout<<endl;
        p_M = p_M + c;
 
    }
    delete[] M;
    
}