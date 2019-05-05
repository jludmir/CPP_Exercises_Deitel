/*
Definition of ElectricBill class to compute how much a given amount will pay for electricity-wise
*/

#include <iostream>
#include <string>

class ElectricBill{
public:
  //Constructor: Takes amount paid in Tanzanian Shillings as argument
  explicit ElectricBill(double paid){
    if (paid >= 0){
      amountPaid = paid;
    }
  }

  //getters/setters
  double getVAT(){
    double vat_total = amountPaid * vat;
    return vat_total;
  }
  void setVAT(double newVAT){
    if(newVAT >= 0.0){
      vat = newVAT;
    }
  }
  double getEWURA(){
    double ewura_total = amountPaid * ewura;
    return ewura_total;
  }
  void setEWURA(double newEWURA){
    if(newEWURA >= 0.0){
      ewura = newEWURA;
    }
  }
  double getREA(){
    double rea_total = amountPaid * rea;
    return rea_total;
  }
  void setREA(double newREA){
    if(newREA >= 0.0){
      rea = newREA;
    }
  }
  double getUnits(){
    double amountAfterDeductions = amountPaid - getVAT() - getEWURA() - getREA() - fixedServiceCharge;
    if(amountAfterDeductions >= 0){
      units = amountAfterDeductions/costPerKWH;
    }
    return units;
  }
  double getFixedCharge(){
    return fixedServiceCharge;
  }
  void setFixedCharge(double newFixedCharge){
    if(newFixedCharge >= 0.0){
      fixedServiceCharge = newFixedCharge;
    }
  }
  double getCostPerKWH(){
    return costPerKWH;
  }
  void setCostPerKWH(double newCostPerKWH){
    if(newCostPerKWH >= 0.0){
      costPerKWH = newCostPerKWH;
    }
  }
private:
  double amountPaid{0.0},vat{.18},fixedServiceCharge{5000},ewura{0.01},rea{0.03},units{0},costPerKWH{295};
};
