#include <iostream>

using namespace std;

class ElectricBill{
public:
   /*WHY Explicit: explicit creates a constructor where there is only one arg.
   Otherwise, if 1 arg and no explicit, system assumes it is implicit conversion,
   meaning the that compiler thinks arg is another instance of class
   (used to copy member vars, ex) */
  explicit ElectricBill(int num_1, int num_2)
    : num1{num_1},
    num2{num_2}
  {
  }
  //Getters/Setters
  int get_num1(){
    return num1;
  }
  void set_num1(int num_1){
    num1 = num_1;
  }
  int get_num2(){
    return num2;
  }
  void set_num2(int num_2){
    num2 = num_2;
  }

private:
  int num1,num2;
};

int main(){
  ElectricBill test(1,2);
  cout << test.get_num1() << " " <<  test.get_num2() << endl;
  return 0;
}
