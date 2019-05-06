#include <iostream>
//Use <climits> INT_MAX/UNIT_MAX/Mins to get systems maxes/mins
#include <climits>
//Use <iomanip> for setprecision
#include <iomanip>

using namespace std;

int main(){
  /*Using ?:
  - The only ternary operator in C++
  Ex: cout << (grade >= 60 ? "Passed" : "Failed");
  operands: 1st is condition, 2nd is true value, 3rd is false value
  */

  /*Remember: int/int = int && int/int != float...
  ...BUT static_cast<double>(int_val)/int_val2 = float
  static_cast converts temp copy of its operand to bracketed type
  */

  /*cout << setprecision(num_decimal_places_shown) << fixed; setprecision sets precision, fixed = fixed (vs. scientifc)
  Use iomanips "<< showpoint" tp force decimal (use with fixed)
  */

  double money = 5;
  cout << setprecision(3) << fixed << showpoint << (money >= 0 ? "Rich! \n" : "Poor =[ \n") <<  static_cast<double>(money)/21 << endl;

  //Another reason we use list inits: prevention of NARROWING CONVERSIONS: EX:
  //int x{12.7}; //RESULTS IN COMPILATION ERROR, BUT
  int x = 12.7; //SETS x TO 12, TRUNCATES, NO ERROR!!!

  /*Diff between pre/post incrementing (++x vs x++):
  ++x -> add 1 to x, then use new value in expression
  x++ -> use x in expression, then increment x by 1
  */
  cout << "Postincrement: " << endl;
  for (int i = 0; i < 10; ){
    cout << i++ << " "; //will output i, then add to i
  }
  cout << "\nPreincrement " << endl;
  for (int i = 0; i < 10;){
    cout << ++i << " "; //will add to i, then output it
  }
  //DO: 4.34, 4.35
  return 0;
}
