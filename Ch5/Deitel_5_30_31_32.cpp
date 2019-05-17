#include <iostream>
#include <iomanip>
#include <string>
#include "Deitel_5_30_31_32.h"

using namespace std;

//DollarAmount Driver
int main(){
  //Enter starting amount
  string values,str_dollars,str_cents = "0";
  cout << "Enter dollar amount OR dollar and cent amount separated by decimal: ";
  getline(cin, values);
  bool space_exists = false;

  for(int i{0}; i < values.size(); i++){
    if (values[i]=='.'){
      str_dollars = values.substr(0,i);
      str_cents = values.substr(i+1);
      space_exists = true;
      break;
    }
  }
  if(space_exists == false){
    str_dollars = values;
  }

  int64_t dollars = stoi(str_dollars), cents = stoi(str_cents);

  //Call contructor depending on which arguments entered
  DollarAmount* capital;
  if(cents == 0){
    capital = new DollarAmount(dollars*100);
  }
  else{
    capital = new DollarAmount(dollars*100, cents);
  }

  cout << capital->toString() << endl;

  string option;
  cout << "\nEnter \"a\" for add, enter \"s\" for subtract, enter \"i\" for interest, enter \"d\" for divide, or ctrl+d to exit: " << endl;

  //start REPL
  while(getline(cin,option)){
    //Add dollar amount to capital
    if(option.compare("a")==0){
      cout << "Enter dollar value to add: ";
      cin >> dollars;
      cin.ignore();
      DollarAmount val2(dollars*100);
      capital->add(val2);
      cout << "New value: " << capital->toString() << endl;
    }

    //Subtract dollar amount to capital
    else if(option.compare("s")==0){
      cout << "Enter dollar value to subtract: ";
      cin >> dollars;
      cin.ignore();
      DollarAmount val2(dollars*100);
      capital->subtract(val2);
      cout << "New value: " << capital->toString() << endl;
    }
    //Show yearly compounding interest, save final value in capital

    else if(option.compare("i")==0){
      cout << "Choose type of rounding:\n0=Half-Up\n1=Banker's" << endl;
      int opt;
      cin >> opt;
      int64_t years, rate, divisor;
      cout << "Enter integer interest rate, year, and divisor\nEX:\nFor 2% on 5 years enter: 5 2 100\nFor 2.3% on 10 years enter: 10 23 1000\nEnter year/rate/divisor (space separated): ";
      cin >> years >> rate >> divisor;
      cin.ignore();
      cout << "Initial balance: " << capital->toString() << endl;
      cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

      if (opt == 0){
        for(int year{0}; year < years; year++){
          capital->addInterest_HalfUp(rate,divisor);
          cout << setw(4) << year+1 << setw(20) << capital->toString() << endl;
        }
      }
      else if (opt == 1){
        for(int year{0}; year < years; year++){
          capital->addInterest_Bankers(rate,divisor);
          cout << setw(4) << year+1 << setw(20) << capital->toString() << endl;
        }
      }
    }

    else if(option.compare("d")==0){
      cout << "Enter value as divisor: ";
      int divisor;
      cin >> divisor;
      cin.ignore();
      capital->divide(divisor);
      cout << "New value: " << capital->toString() << endl;
    }

  cout << "\nEnter \"a\" for add, enter \"s\" for subtract, enter \"i\" for interest, enter \"d\" for divide, or ctrl+d to exit: " << endl;
  }
  delete capital;
  return 0;
}
