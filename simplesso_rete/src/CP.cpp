#include "../include/CP.h"
#include <iostream>
#include <string>
//#include "CP.h"

using namespace std;

  string CP::getName(){
	return name;
  }
  int CP::getAge(){
	return age;
	}
  void CP::setName(string new_name){
       name=new_name;
   }
  void CP::setAge(int new_age){
      name=new_age;
  }
 
  void CP::gg(int new_age=55){
	age=new_age;
	}
