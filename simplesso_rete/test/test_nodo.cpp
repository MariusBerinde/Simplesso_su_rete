#include <iostream>
#include <string>
#include "../src/Nodo.cpp"
using namespace std;
void test_equals(){
Nodo a(1),b(1),c(3);
bool e1=a.equals(b);
bool e2=a.equals(c);
if(e1)
	cout<<"equals e1:ok\n";
else
	cout<<"equals e1:problema\n";
if(e2==false)
	cout<<"equals e2:ok\n";
else
	cout<<"equals e2:problema\n";
}
int main(){
test_equals();
}
