#include <iostream>

using namespace std;
int main () {
  float x1, y1, x2, y2;
  std::cout << "please enter your x1 coordinate: ";
  std::cin >> x1;
  std::cout << "please enter your y1 coordinate: ";
  std::cin >> y1;
  std::cout << "please enter your x2 coordinate: ";
  std::cin >> x2;
  std::cout << "please enter your y2 coordinate: ";
  std::cin >> y2;
  
  float midpointx, midpointy;
  midpointx = (x1 + x2) / 2;
  midpointy = (y1 + y2) / 2;
  std::cout << "Your midpoint is: " << midpointx << ", " << midpointy << ".\n";




  float slope, dx = x2 - x1;
  if (dx == 0) std::cout << "Slope is undefined" << std::endl;
  else { slope = (y2 - y1) / (dx);
  std::cout << "Your slope is: " << slope << ".\n";
  
  float yint;
  yint = y1 - (slope * x1);
  std::cout << "Your y-intercept is: " << yint << ".\n";

  std::cout << "The equation for your line is: " << "y=" << slope << "*x-" << yint << endl;

  float rslope;
  rslope = 0-(x2-x1)/(y2-y1);
  
  float rint;
  rint = midpointy - (rslope * midpointx);
  
  std::cout << "The perpendicular bisector for your line is: " << "y = " << rslope << " * x - " << rint << ".\n";
  
  }
  return 0;
}

