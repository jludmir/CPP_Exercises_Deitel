#include <cmath>

class DollarAmount{
public:
  //Constructors:
  //Constructor: explicit since 1 arg (NOT an implicit contstructor)
  explicit DollarAmount(int64_t dollars): cents{dollars}{}

  DollarAmount(int64_t dollars, int64_t cent_amount): cents{dollars + cent_amount}{}

  DollarAmount(const DollarAmount &obj): cents{obj.cents}{} // copy the value

  void add(DollarAmount value_2){
    cents += value_2.cents;
  }
  void subtract(DollarAmount value_2){
    cents -= value_2.cents;
  }

  void divide(int divisor){
    //RESULT MUST BE TO NEAREST CENT
    cents = (cents + divisor/2)/divisor;
    // 550/210 = 2.619048 ~ 3
    //550 / 210 = (550 + ) =

  }

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
