#include "Student.h"

Student::Student(int id){
  _id=id;
}
int Student::getID(){
  return _id;
}

#include <iostream>
using namespace std;

int  main()
{
  Student s(123);
  std::cout << "hello atom" << '\n';
  std::cout << s.getID() << '\n';
  return 0;
}
