#include <cmath>

//Class for DollarAmount using only integers to avoid floating point issues

class DollarAmount{
public:
  //Constructors:
  //Constructor: explicit since 1 arg (NOT an implicit contstructor)
  explicit DollarAmount(int64_t dollars): cents{dollars}{}

  //Constructor using dollar and cent values as args
  DollarAmount(int64_t dollars, int64_t cent_amount): cents{dollars + cent_amount}{}

  //Copy constructor
  DollarAmount(const DollarAmount &obj): cents{obj.cents}{} // copy the value

  //Add amount to cents
  void add(DollarAmount value_2){
    cents += value_2.cents;
  }

  //Subtract amount from cents
  void subtract(DollarAmount value_2){
    cents -= value_2.cents;
  }

  //Divide amount by divisor
  void divide(int divisor){
    cents = (cents + 50) / divisor;
  }

  void addInterest_HalfUp(int64_t rate, int64_t divisor) {
    DollarAmount interest{ (cents * rate + divisor / 2) / divisor };
    add(interest);
  }

  /*
  Interest computer, except rounding with Banker's: If rounding .5, round to nearest even integers
  Purpose of this is to ensure roughly equal amount of up/down rounds with .5 (rather than all up-rounds)
  To see how they differ, try computing interest on initital capital of 100 with arguments: 1 125 100000
  Notice how output with Half-Up is 100.13 (rounding up on 100.125) and with Banker's is 100.12
  (rounding to nearest even, in this case to 100.12...if we used 135 instead it would be 100.14)
  */
  void addInterest_Bankers(int64_t rate, int64_t divisor) {
    //Likely needs some modulo arithmetic
    int64_t temp_val = (cents * rate)/(divisor/10);
    //If exactly 5 remainder:
    if((temp_val % 5 == 0) && (temp_val % 10 != 0)){
      temp_val /= 10;
      //If the smallest decimal is even after getting rid of remainder, then we are fine
      //...If not, we need to add 1 to make it even. Ensures Banker's rounding property maintained
      if(temp_val % 2 != 0){
        temp_val += 1;
      }
    }
    //Else just round like with Half-Up
    else{
      temp_val = (cents * rate + divisor / 2) / divisor;
    }
    DollarAmount interest{temp_val};
    add(interest);
  }

  std::string toString(){
    std::string dollars{std::to_string(cents / 100)};
    std::string cent_amount{std::to_string(abs(cents % 100))};
    return ((cents/100) != 0 ? dollars : "0") + "." + (cent_amount.size() == 1 ? "0" : "" ) + cent_amount;
  }

private:
  int64_t cents{0};
};
