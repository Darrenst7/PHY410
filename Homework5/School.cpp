#include <iostream>
#include <fstream>
#include <vector>
#include "StudentRecord.h"
#include "StudentRecordPhysics.h"
#include "StudentRecordLiterature.h"
#include "StudentRecordHistory.h"
using namespace std;

int main(int argc, char ** argv){
  vector<StudentRecord *> records; 

  string line;
  ifstream in("record.txt");


  while( !in.eof() ) {           
      StudentRecordPhysics p1;
      StudentRecordLiterature l2;
      StudentRecordHistory h3;

      getline (in, line, ',');  
      cout << line << endl;      
      if (line == "Physics"){         
        p1.input(in);
        records.push_back(&p1);      
        p1.print();}

      else if (line == "Literature"){
        l2.input(in);
        records.push_back(&l2);
        l2.print();}

      else if (line == "History"){
        h3.input(in);
        records.push_back(&h3);
        h3.print();} 
   
   
}        
    
  
double totalavg = 0.;
  for ( vector<StudentRecord *>::const_iterator i = records.begin();i != records.end(); ++i) { 
 
     totalavg += (*i)->score();
   } 
  totalavg /= records.size();
  cout << "Total GPA for this class is " << totalavg << endl;
} 

