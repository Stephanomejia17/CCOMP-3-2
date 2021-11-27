#include <iostream>
using namespace std;

int main(){
    int z(3),y(5),x(6);
  int* m= new int[z*x*y];
  for(int* i=m;i<m+x*y*z;i++){
    *i=5;
  }
  int* i=m;
  int* q=m;
  int* r=m;
  while(i<m+x*y*z){
    while(i<q+x*y){
      while(i<r+x){
        cout<<*i;
        i++;
      }
      cout<<endl;
      r+=x;
    }
    cout<<endl;
    q+=y*x;
  }

    delete[] m;
    return 0;
}