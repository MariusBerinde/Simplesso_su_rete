
#include <iostream>
#include <string>
#include "../src/Arco.cpp"
using namespace std;
int main(){
Nodo *n1,*n2;
n1=new Nodo(1);
n2=new Nodo(2);
Arco a(n1,n2,3);
a.printArco();
delete n1;
delete n2;
}

