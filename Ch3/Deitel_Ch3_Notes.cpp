#include <iostream>
#include "Deitel_Ch3_Notes.h"

using namespace std;

int main(){
  /* WHY USE test{} instead of test() for object instantiation?
    - Using brackets = List initialization = More efficient
  */
  ElectricBill test{1};
  cout << test.get_num1() << " " << test.get_num2() << endl;
  ElectricBill test_2{1,2};
  cout << test_2.get_num1() << " " << test_2.get_num2() << endl;
  return 0;
}
