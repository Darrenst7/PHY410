#include "StudentRecordHistory.h"


StudentRecordHistory::StudentRecordHistory(){};
StudentRecordHistory::~StudentRecordHistory() {};

void StudentRecordHistory::print( std::ostream & out ) const {
 std::cout << "History score : " << lastname_ << "," << firstname_
 << ", score 0: " << scores_[0] << ", score 1: " << scores_[1]
 << ", total: " << score() << endl;
}

bool StudentRecordHistory::input( std::istream & in ) {

 // First add name (last,first)

 std::string line;

 // getline( in, line, ',');
 // classname_ = line;

 getline( in, line, ',');
 lastname_ = line;

 getline( in, line, ',');
 firstname_ = line;

 // Now get each score. History has two. Large * .6, Small * .4

 getline( in, line, ',' );
 scores_.push_back( atof( line.c_str() ) );

 getline( in, line );
 scores_.push_back( atof( line.c_str() ) );

 if ( line == "")
 return false;
 else {
  total_his();

 return true;}
 
}

