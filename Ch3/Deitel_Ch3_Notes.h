#include <iostream>
#include <string>

class ElectricBill{
public:
   /*WHY Explicit: explicit creates a constructor where there is only one arg.
   Otherwise, if 1 arg and no explicit, system assumes it is implicit conversion,
   meaning the that compiler thinks arg is another instance of class
   (used to copy member vars, ex) */

   //Interesting Note on constructors: If constructor defined, no default constructor
  explicit ElectricBill(int num): num1{num} {}

  //ONLY use explicit w/>1 arg
  ElectricBill(int num_1, int num_2): num1{num_1},num2{num_2} {}
  //Getters/Setters

  //Note on getters/setters: We use them to control for invalid output.
  //Generally, data members = private, member functions = public
  int get_num1(){
    return num1;
  }
  void set_num1(int num_1){
    if(num_1 >= 0){
      num1 = num_1;
    }
  }
  int get_num2(){
    return num2;
  }
  void set_num2(int num_2){
    num2 = num_2;
  }

private:
  //Note: can initialize data member with {}: EX: num2
  int num1,num2{0};
};
