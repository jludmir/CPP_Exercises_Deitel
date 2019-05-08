/*
Program that can:
1. Compute factorial
2. Estimate e with factorial
3. Estimate e^x with factorial
*/
#include <iostream>
//Use <climits> INT_MAX/UNIT_MAX/Mins to get systems maxes/mins
#include <climits>
//Use <iomanip> for setprecision
#include <iomanip>
//Contains pow function
#include <math.h>

using namespace std;

int factorial(int);
double e_estimate(int, int);

//compute factorial of x
int factorial(int x){
  if(x == 0 || x == 1){
    return 1;
  }
  else{
    int factorial = 1;
    while(x > 0){
      factorial *= x;
      x--;
    }
    return factorial;
  }
}
//estimate e^numerator
double e_estimate(int num_terms, int numerator=1){
  double e_est = 0;
  num_terms--;
  while(num_terms >= 0){
    e_est += (pow(numerator, num_terms)/factorial(num_terms));
    num_terms--;
  }
  return e_est;
}

int main(){
  //start REPL
  while(1){
    cout << "Please enter option:\n0: Exit\n1: Input nonnegative int, compute factorial\n2: Input desired accuracy (number of terms of summation), output estimate of constant e\n3: Input x and desired accuracy, output e^x" << endl;
    int option;
    cin >> option;
    switch(option){
      case 0: {
        return 0;
      }
      case 1: {
        int val;
        cout << "Please enter nonnegative int: ";
        cin >> val;
        cout << factorial(val) << endl;
        break;
      }
      case 2: {
        int num_terms;
        cout << "Please enter nonnegative int: ";
        cin >> num_terms;
        cout << setprecision(6) << fixed << e_estimate(num_terms) << endl;
        break;
      }
      case 3: {
        int exponent, num_terms;
        cout << "Please enter two nonnegative ints: ";
        cin >> exponent >> num_terms;
        cout << setprecision(6) << fixed << e_estimate(num_terms, exponent) << endl;
        break;
      }
      default: {
        cout << "Invalid input" << endl;
        break;
      }
    }
  }
}
