/*
Solution to Deitel 20th Ed Problem 3.17.
Creates/tests ElectricBill class to compute how much a given amount will pay for electricity-wise
*/

#include <iostream>
#include "Deitel_3_17.h"

using namespace std;

//Driver program to test functionality of ElectricBill class
int main(){
  //Easy tests
  // ElectricBill test(95000);
  // ElectricBill negTest(-100);
  // cout << test.getUnits() << "\n" << negTest.getUnits() << endl;

  //Simple REPL loop menu for testing purposes
  while(1){
    double amount = 0.0;
    cout << "Enter any number greater than 0 to compute units paid for using entered amount, or 0 to quit: ";
    cin >> amount;
    if(amount == 0.0){
        break;
    }
    ElectricBill test(amount);
    cout << test.getUnits() << endl;
  }

  return 0;
}
