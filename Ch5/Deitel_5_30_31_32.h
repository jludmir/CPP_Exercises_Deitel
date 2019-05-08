#include <cmath>

class DollarAmount{
public:
  //Constructors:
  //Constructor: explicit since 1 arg (NOT an implicit contstructor)
  explicit DollarAmount(int64_t dollars): cents{dollars}{}

  //Constructor using dollar and cent values as args
  DollarAmount(int64_t dollars, int64_t cent_amount): cents{dollars + cent_amount}{}

  //Copy constructor
  explicit DollarAmount(const DollarAmount &obj): cents{obj.cents}{} // copy the value

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
    DollarAmount interest{
      (cents * rate + divisor / 2) / divisor
    };
    add(interest);
  }

  void addInterest_Bankers(int64_t rate, int64_t divisor) {
    //Likely needs some modulo arithmetic
    int64_t temp_val = cents * rate;
    int half_a_cent =  (5 * divisor) / 10;
    if((cents * rate) / )
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
