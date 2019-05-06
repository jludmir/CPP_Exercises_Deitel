/*
Program which takes in the lengths of sides of a triangle, outputs whether right triangle or not.
*/
#include <iostream>
//Use <climits> INT_MAX/UNIT_MAX/Mins to get systems maxes/mins
#include <climits>
//Use <iomanip> for setprecision
#include <iomanip>

using namespace std;

bool pythagorean_verify(int, int, int);

//Function which verifies pythagorean property on input triangle
bool pythagorean_verify(int side1, int side2, int hypotenuse){
  int side1_sq = side1 * side1;
  int side2_sq = side2 * side2;
  int hypotenuse_sq = hypotenuse * hypotenuse;

  if(side1_sq + side2_sq == hypotenuse_sq){
    return true;
  }
  else{
    return false;
  }
}

int main(int argc,char *argv[]){
  //Get the lengths of sides as command line args
  if(argc != 4){
    cout << "Error: Input must be ./Deitel_4_34 side1_length side2_length hypotenuse_length" << endl;
    return 1;
  }

  int side1 = stoi(argv[1]);
  int side2 = stoi(argv[2]);
  int hypotenuse = stoi(argv[3]);

  bool is_right_triangle = pythagorean_verify(side1, side2, hypotenuse);
  if(is_right_triangle == true){
    cout << "Right triangle" << endl;
  }
  else{
    cout << "Not right triangle" << endl;
  }
  return 0;
}
