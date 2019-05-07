#include <iostream>
#include <iomanip>
#include <string>
#include "Deitel_Ch5_Notes.h"

using namespace std;

int main(){
  //Can initialize/increment multiple vars using commas:
  int i,j = 5;
  i +=  3, j -= 3; //i = 8, j = 2

  //--------------------------------------------------------------------------------------------------------

  //DollarAmount Driver:

  //Enter starting amount
  int64_t dollars;
  cout << "Enter dollar amount: ";
  cin >> dollars;
  //NOTE: cin.ignore() fixes skipped input by ignoring a lingering newline (causes to skip input)
  cin.ignore();
  DollarAmount capital(dollars*100);

  string option;
  cout << "\nEnter \"add\", enter \"subtract\", enter \"interest\", or ctrl+d to exit: " << endl;
  //NOTE: Use while(cin>>input to continuously read input)
  //NOTE <ctrl> d = EOF on Unix/Mac; <ctrl> z = EOF on Windows
  //start REPL
  while(getline(cin,option)){
    //NOTE: Don't need cin.ignore with getline as getline throws out newline character

    //Add dollar amount to capital
    if(option.compare("add")==0){
      cout << "Enter dollar value to add: ";
      cin >> dollars;
      cin.ignore();
      DollarAmount val2(dollars*100);
      capital.add(val2);
      cout << "New value: " << capital.toString() << endl;
    }

    //Subtract dollar amount to capital
    else if(option.compare("subtract")==0){
      cout << "Enter dollar value to subtract: ";
      cin >> dollars;
      cin.ignore();
      DollarAmount val2(dollars*100);
      capital.subtract(val2);
      cout << "New value: " << capital.toString() << endl;
    }

    //Show yearly compounding interest, save final value in capital
    else if(option.compare("interest")==0){
      int64_t years, rate, divisor;
      cout << "Enter integer interest rate, year, and divisor\nEX:\nFor 2% on 5 years enter: 5 2 100\nFor 2.3% on 10 years enter: 10 23 1000\nEnter year/rate/divisor (space separated): ";
      cin >> years >> rate >> divisor;
      cin.ignore();
      cout << "Initial balance: " << capital.toString() << endl;
      //NOTE: iomanip's setw(n) sets the width of the following string to be n-length (for column-alignment below Amount on deposit in this case )
      cout << "\nYear" << setw(20) << "Amount on deposit" << endl;

      for(int year{0}; year < years; year++){
        capital.addInterest_HalfUp(rate,divisor);

        cout << setw(4) << year+1 << setw(20) << capital.toString() << endl;
      }
    }
    cout << "\nEnter \"add\", enter \"subtract\", enter \"interest\", or ctrl+d to exit: " << endl;
  }

  //--------------------------------------------------------------------------------------------------------
  //NOTE: You can explicitly make output of boolean vals words true/false using boolalpha
  cout << boolalpha << "Boolalpha test: " true << " " << false;
  return 0;
}
