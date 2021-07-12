#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>



int main ()
{
  int x=999, y=1;
      int *       p1 = &x;  // non-const pointer to non-const int
const int *       p2 = &x;  // non-const pointer to const int
      int * const p3 = &x;  // const pointer to non-const int
const int * const p4 = &x;  // const pointer to const int 

  //p4 = &y;
  //*p3 = y;
    x = -1;
  std::cout << x << "\n"; //,numbers+3);
  std::cout << p1 << "\n"; //,numbers+3);
  std::cout << p2 << "\n"; //,numbers+3);
  std::cout << p3 << "\n"; //,numbers+3);
  std::cout << p4 << "\n"; //,numbers+3);

  std::cout << *p1 << "\n"; //,numbers+3);
  std::cout << *p2 << "\n"; //,numbers+3);
  std::cout << *p3 << "\n"; //,numbers+3);
  std::cout << *p4 << "\n"; //,numbers+3);

  //print_all (numbers,numbers+3);
  return 0;
}