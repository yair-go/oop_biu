#include <iostream>
#include "Student.h"

using namespace std;

int  main()
{
  Student s(123);
  std::cout << "hello atom" << '\n';
  std::cout << s.getID() << '\n';
  return 0;
}
