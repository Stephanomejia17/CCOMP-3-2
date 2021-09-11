#include <iostream>
using namespace std;

int main(){
    std::string s1 = "C++ y ";
std::string s2 = "python";
std::string && s3 = s1 + s2 + " los mejores";
std::cout << s3 <<"\n";
}