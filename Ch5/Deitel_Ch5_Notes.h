#include <cmath>

class DollarAmount{
public:
  //Constructor: explicit since 1 arg (NOT an implicit contstructor)
  explicit DollarAmount(int64_t dollars): cents{dollars}{}

  //NOTE Copy constructor: Use another DollarAmount object to construct new object
  DollarAmount(const DollarAmount &obj): cents{obj.cents}{} // copy the value

  void add(DollarAmount value_2){
    //COOL NOTE: objects can access private members of other objects of same class!!! (see below)
    cents += value_2.cents;
  }
  void subtract(DollarAmount value_2){
    cents -= value_2.cents;
  }

  /* NOTE
  HALF-UP ROUNDING: Take integer value, multiply by int version of rate (ex: 5%=5)
  Then add HALF of the divisor to result (this is to guarantee proper truncation of integers when rounding)
  Finally, divide by divisor to rescale integers.
  */
  void addInterest_HalfUp(int64_t rate, int64_t divisor){
    DollarAmount interest{
      (cents*rate + divisor/2)/divisor
    };
    add(interest);
  }

  std::string toString(){
    std::string dollars{std::to_string(cents/100)};
    std::string cent_amount{std::to_string(abs(cents%100))};
    return ((cents/100) != 0 ? dollars : "0") + "." + (cent_amount.size() == 1 ? "0" : "" ) + cent_amount;
  }

private:
  int64_t cents{0};
};
