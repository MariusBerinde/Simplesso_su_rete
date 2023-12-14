#include <iostream>
#include <string>
using namespace std;

class CP{
 private :
	string name;
	int age;
 public:
  CP(){ name="default"; age=666;}
  CP(int my_age,string my_name){age=my_age;name=my_name;}
  string getName();
  int getAge();
  void setName(string new_name);
  void setAge(int new_age);
  void gg(int new_age); 
};

