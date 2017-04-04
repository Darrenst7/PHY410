#include <cmath>
#include <iostream>
using namespace std;


const int n = 24; // number of galaxies in Table 
const int g = 9; // Groups
double r[n] = {     // distances in Mpc
  0.032, 0.034, 0.214, 0.263, 0.275, 0.275, 0.45, 0.5, 0.5, 0.63, 0.8, 0.9,
  0.9,   0.9,   0.9,   1.0,   1.1,   1.1,   1.4,  1.7, 2.0, 2.0,  2.0, 2.0
};

double d[g] = {   // avg distance for each group
  (r[0] + r[1] + r[2])/3 , (r[3] + r[4] + r[5])/3 ,
(r[7] + r[8] + r[9] + r[10])/4 , (r[6] + r[11])/2 ,
(r[12] + r[17])/2 , (r[14] + r[15])/2 ,
(r[16] + r[18] + r[19])/3, (r[13]+ r[20])/2,
(r[21] + r[22] + r[23])/3
};

double v[n] = {     // velocities in km/s
  +170, +290, -130, -70,  -185, -220, +200, +290, +270, +200, +300, -30,
  +650, +150, +500, +920, +450, +500, +500, +960, +500, +850, +800, +1090
};

double velocity[g] = { // avg velocity for each group
 (v[0] + v[1] + v[2])/3 , (v[3] + v[4] + v[5])/3 ,
(v[7] + v[8] + v[9] + v[10])/4 , (v[6] + v[11])/2 ,
(v[12] + v[17])/2 , (v[14] + v[15])/2 ,
(v[16] + v[18] + v[19])/3, (v[13]+ v[20])/2,
(v[21] + v[22] + v[23])/3
};

int main() {

  // declare and initialize various sums to be computed
  double s_x = 0, s_y = 0, s_xx = 0, s_xy = 0;

  if ( g < 2 ) {  // now for the groups
    cout << "Error! Need at least two data points!" << endl;
    return 0;
  }

  // compute the sums
  for (int i = 0; i < g; i++) {   // now for the groups
    s_x += d[i];
    s_y += velocity[i];
    s_xx += d[i] * d[i];
    s_xy += d[i] * velocity[i];
  }

  cout << s_x << " " << s_y << " " << s_xx << " " << s_xy << endl;

  // evaluate least-squares fit forumlas for the groups
  double denom = g * s_xx - s_x * s_x;
 
  if ( fabs(denom) < 0.000001 ) {
    cout << "Error! Denominator is zero!" << endl;
    return 0;
  }

  double a = (s_xx * s_y - s_x * s_xy) / denom;
  double b = (g * s_xy - s_x * s_y) / denom;  // for groups

  cout << denom << " " << a << " " << b << endl;

  // estimate the variance in the data set
  double sum = 0;
  for (int i = 0; i < g; i++) {   // for groups
    double v_of_r_i = a + b * d[i]; // for groups
    double error = velocity[i] - v_of_r_i;  // for groups
    sum += error * error;
  }

  double sigma = (n > 2) ? sqrt(sum / (n - 2)) : 0;    // estimate of error bar in v

  // estimate errors in a and b
  double sigma_a = sqrt(sigma * sigma * s_xx / denom);
  double sigma_b = sqrt(sigma * sigma * n / denom);

  // print results
  cout.precision(4);
  cout << " Least-squares fit of " << g << " data points\n"  // for groups
       << " -----------------------------------\n"
       << " Hubble's constant slope   b  =  " << b
       << " +- " << sigma_b << " km/s/Mpc\n"
       << " Intercept with r axis     a  =  " << a
       << " +- " << sigma_a << " km/s\n"
       << " Estimated v error bar sigma  =  " << sigma << " km/s" << endl;
}
