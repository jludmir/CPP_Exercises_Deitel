#include <iostream>
//cmath has a bunch of standard math functions
#include <cmath>

using namespace std;

//NOTE: Purpose of this: Ensure that compiler knows we will define this function, such that we can use it before definining it
int add_vars(int a, int b);

int main(){
  cout << "Test cmath funcs? y/n: ";
  char c;
  cin >> c;
  if (c == 'y'){
    cout << "ceil(100.5) = round up: " << ceil(100.5) << endl;
    cout << "floor(100.5) = round down: " << floor(100.5) << endl;
    cout << "exp(1) = e^1: " << exp(1) << endl;
    cout << "fabs(-2) = |-2|: " << fabs(-2) << endl;
    cout << "fmod(2.6,1.2) = floating point modulo: " << fmod(2.6,1.2) << endl;
    cout << "log(1) = ln(1): " << log(1) << endl;
    cout << "log10(1) = log_10(1): " << log10(1) << endl;
    cout << "pow(2,3) = 2^3: " << pow(2,3) << endl;
    cout << "sqrt(4): " << sqrt(4) << endl;
    cout << "sin(0.5) tan(0.5) (in radians): " << sin(0.5) << " " << tan(0.5) << endl;
  }
  int a = 1, b = 2;
  cout << "\na + b = "<< add_vars(a,b) << endl;

  return 0;
}

int add_vars(int a, int b){
  return a + b;
}
