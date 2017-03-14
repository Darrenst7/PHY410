#include "StudentRecordPhysics.h"
StudentRecordPhysics::StudentRecordPhysics(){};
StudentRecordPhysics::~StudentRecordPhysics() {};

void StudentRecordPhysics::print( std::ostream & out  ) const  {
  std::cout << "Physics score: " << lastname_ << "," << firstname_
      << ", Homework: " << scores_[0] << ", Lab: " << scores_[1]
      << ", total: " << score() << std::endl;
}

bool StudentRecordPhysics::input( std::istream & in ) {



 std::string line;

 getline( in, line, ',');
 lastname_ = line;

 getline( in, line, ',');
 firstname_ = line;

  // Now get each score. Physics has two
  std::getline( in, line, ',' );
  scores_.push_back( std::atof( line.c_str() ) );

  std::getline( in, line );
  scores_.push_back( std::atof( line.c_str() ) );

  if ( line == "") 
    return false;
  else {      
     total_phy();         // Make sure to call compute_score in input!
    return true;
  }
}
