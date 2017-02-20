#include <iostream>

int main() {
  int i1, i2, i3;
double d1, d2, d3;
 i1 = 2;
 i2 = 5;
 i3 = -3;
  d1 = 2.0;
  d2 = 5.0;
  d3 = -0.5;

  int Pa,Pb,Pc,Pd,Pe,Pf;
double Pg,Ph,Pi,Pj,Pk,Pl,Pm,Pn;
  Pa = i1 + (i2 * i3);
  std::cout<< "Part A: " << Pa << ".\n";
  Pb = i1 * (i2 + i3);
  std::cout<< "Part B: " << Pb << ".\n";
  Pc = i1 / (i2 + i3);
  std::cout<< "Part C: " << Pc << ".\n";
  Pd = i1 / i2 + i3;
  std::cout<< "Part D: " << Pd << ".\n";
  Pe = 3 + 4 + 5 / 3;
  std::cout<< "Part E: " << Pe << ".\n";
  Pf = (3 + 4 + 5) / 3;
  std::cout<< "Part F: " << Pf << ".\n";
  Pg = d1 + (d2 * d3);
  std::cout<< "Part G: " << Pg << ".\n";
  Ph = d1 + d2 * d3;
  std::cout<< "Part H: " << Ph << ".\n";
  Pi = d1 / d2 - d3;
  std::cout<< "Part I: " << Pi << ".\n";
  Pj = d1 / (d2 - d3);
  std::cout<< "Part J: " << Pj << ".\n";
  Pk = d1 + d2 + d3 / 3;
  std::cout<< "Part K: " << Pk << ".\n";
  Pl = (d1 + d2 + d3) / 3;
  std::cout<< "Part L: " << Pl << ".\n";
  Pm = d1 + d2 + (d3 / 3);
  std::cout<< "Part M: " << Pm << ".\n";
  Pn = 3 * (d1 + d2) * (d1 -d3);
  std::cout<< "Part N: " << Pn << ".\n";
return 0;
}
