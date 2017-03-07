#include <iostream>
#include <fstream>
#include "StudentRecord.h"
#include <cmath>
#include <cstdlib>
#include <vector>


 
void print_vector(std::vector<StudentRecord> * happyjack){
  double average = 0
    for (unsigned int i = 0; i < happyjack->size(); ++i){
      (*happyjack)[i].print();
  average += (*happyjack)[i].sc();
}
average /= happyjack->size();
std::cout << "The average is " << average << std::endl;
}




int main(int argc, char ** argv) {

  std::ifstream inputfile( "record.txt");
  std::vector<StudentRecord> p_vector;


  bool valid = true;
  while( valid ) {
    Point p1;
    valid = p1.input( inputfile ) ;
    if ( not valid ) 
      break;
    std::cout << "You input:" << std::endl;
    p1.print();
    p_vector.push_back( p1 );
    
  }

  std::cout << "VECTORCATS HOOOO!" << std::endl;
  print_vector( &p_vector);
  return 0;
}



