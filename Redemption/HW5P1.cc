#include "StudentRecordPhysics.h"
#include "StudentRecordHistory.h"
#include "StudentRecordLiterature.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>

bool operatora(const std::shared_ptr<StudentRecord>& a, const std::shared_ptr<StudentRecord>& b);

float calulate_average( std::vector<std::shared_ptr<StudentRecord> > const & records ) {
  float avg = 0.0;
  if ( records.size() == 0 ) {
    std::cout << "Error.... none given" << std::endl;
    return avg;
  }
  for ( auto const & rec : records ) {
    avg += rec->score();
  }
  avg /= records.size();
  return avg;
}



int main(int argc, char * argv[]){

  if ( argc < 2 ) {
    std::cout << "Usage: " << argv[0] << " filename.txt" << std::endl;
    return 0;
  }
  std::ifstream fin( argv[1] );


  std::vector<std::shared_ptr<StudentRecord> > records, physics, literature, history;
  bool valid = true;
  while( valid ) {
    std::string line;
    std::getline( fin, line, ',');
    if ( line == "" ) 
      break;

    if ( line == "Physics" ) {
      std::shared_ptr<StudentRecord> irecord( new StudentRecordPhysics() );
      valid = irecord->input(fin);     
 if ( valid ) {
	records.push_back( irecord );
	physics.push_back( irecord );
      }
      else
	break;
    } else if ( line == "Literature" ) {
      std::shared_ptr<StudentRecord> irecord( new StudentRecordLiterature() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	literature.push_back( irecord );
      }
      else
	break;
    } else if ( line == "History" ) {
      std::shared_ptr<StudentRecord> irecord( new StudentRecordHistory() );
      valid = irecord->input(fin);
      if ( valid ) {
	records.push_back( irecord );
	history.push_back( irecord );
      }
      else
	;
    } else {
      std::cout << "Invalid input, ignoring" << std::endl;
      continue;
    }

  }



  std::cout << "" << std::endl;
  std::cout << "Sorting..." << std::endl;
  std::sort( physics.begin(), physics.end(), operatora);
  std::cout << "Physics Students:" << std::endl;
  for ( std::shared_ptr<StudentRecord> const & rec : physics ) {
    rec->print( std::cout );
  }

  std::cout << "" << std::endl;
  std::cout << "Re-sorting..." << std::endl;
  std::sort( history.begin(), history.end(), operatora );
  std::cout << "History Students:" << std::endl;
  for ( std::shared_ptr<StudentRecord> const & rec : history ) {
    rec->print( std::cout );

  }

  std::cout << "" << std::endl;
  std::cout << "Re-sorting..." << std::endl;
  std::sort( literature.begin(), literature.end(), operatora );
  std::cout << "Literature Students" << std::endl;
  for ( std::shared_ptr<StudentRecord> const & rec : literature ) {
    rec->print( std::cout );
  }

  
  std::cout << "" << std::endl;
  std::cout << "Re-sorting..." << std::endl;
  std::sort( records.begin(), records.end(), operatora );
  std::cout << "All Students" << std::endl;
  for ( std::shared_ptr<StudentRecord> const & rec : records ) {
    rec->print( std::cout );
  }
  

  std::cout << std::endl;

  std::cout << "Tot average : " << calulate_average( records ) << std::endl;
  std::cout << "Phy average : " << calulate_average( physics ) << std::endl;
  std::cout << "Lit average : " << calulate_average( literature ) << std::endl;
  std::cout << "His average : " << calulate_average( history ) << std::endl;


}

bool operatora(const std::shared_ptr<StudentRecord>& a, const std::shared_ptr<StudentRecord>& b)
{
  if ( a->score() < b->score() )
        return true ;
  else
    return false;
}

