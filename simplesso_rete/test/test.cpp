#include <iostream>
#include <string>
#include "../src/CP.cpp"

using namespace std;
int main(){
 CP *obj1;
 obj1= new CP();
 cout<<"mi chiamo="<<obj1->getName()<<" e ho "<<obj1->getAge()<<" anni\n";
 delete obj1;
CP *obj2;
 obj2= new CP(22,"Marco");
 cout<<"mi chiamo="<<obj2->getName()<<" e ho "<<obj2->getAge()<<" anni\n";
 delete obj2;
 
 CP obj3(25,"Mariolone bubbarello");
 cout<<"mi chiamo="<<obj3.getName()<<" e ho "<<obj3.getAge()<<" anni\n";
 obj3.gg();
 cout<<"modifico l'eta con gg mi chiamo="<<obj3.getName()<<" e ho "<<obj3.getAge()<<" anni\n";
 obj3.gg(155);
 cout<<"mi chiamo="<<obj3.getName()<<" e ho "<<obj3.getAge()<<" anni\n";
}
