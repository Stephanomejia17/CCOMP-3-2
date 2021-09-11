#include <iostream>
using namespace std;

int main(){
    std::string x = "python";
std::string y = "C++";
std::string & a1[] = {x,y};
std::cout<< a1[0] <<"\n";
}