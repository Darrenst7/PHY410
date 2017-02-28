#include <iostream>
#include <cmath>




int main(void){
  float xi=0.,yi=0.,mag=0;
  float small = 999999;  
while( std::cin >> xi >> yi ) { 
  float mag=sqrt(xi*xi+yi*yi);
  if (mag < small) small = mag;
   std::cout << xi << "," << yi << std::endl; 
   std::cout << "Magnitude: " << mag << std::endl;
  
   
}
 std::cout <<"The smallest magnitude was: "<< small << std::endl;

 return 0;
}

