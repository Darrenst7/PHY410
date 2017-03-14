#include "StudentRecordLiterature.h"

StudentRecordLiterature::StudentRecordLiterature(){};
StudentRecordLiterature::~StudentRecordLiterature() {};

void StudentRecordLiterature::print( std::ostream & out ) const  {
  out << "Literature score : " << lastname_ << "," << firstname_
      << ", Analytic: " << scores_[0] << ", Creative: " << scores_[1] <<  ", Commentary: " << scores_[2]
      << ", total: " << score() << std::endl;
}

bool StudentRecordLiterature::input( std::istream & in ) {



 std::string line;

 getline( in, line, ',');
 lastname_ = line;

 getline( in, line, ',');
 firstname_ = line;
  // Now get each score. Literature has three, with weights 0.4, 0.4, 0.2
  std::getline( in, line, ',' );
  scores_.push_back( std::atof( line.c_str() ) );

  std::getline( in, line, ',' );
  scores_.push_back( std::atof( line.c_str() ) );

  std::getline( in, line );
  scores_.push_back( std::atof( line.c_str() ) );

  if ( line == "") 
    return false;
  else {
    compute_score();
    return true;
  }
}
