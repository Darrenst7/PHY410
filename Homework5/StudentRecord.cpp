#include "StudentRecord.h"


StudentRecord::StudentRecord(){}
std::string StudentRecord::classname() const { return classname_; }
std::string StudentRecord::firstname() const { return firstname_; }
std::string StudentRecord::lastname() const { return lastname_; }
 
double StudentRecord::score() const { return score_; }
bool StudentRecord::operator>( StudentRecord const & right ) const {
 return this->score() > right.score();
};
bool StudentRecord::operator>=( StudentRecord const & right ) const {
 return this->score() >= right.score();
};
bool StudentRecord::operator<( StudentRecord const & right ) const {
 return this->score() < right.score();
};
bool StudentRecord::operator<=( StudentRecord const & right ) const {
 return this->score() <= right.score();
};

void StudentRecord::compute_score(void) {
 if ( scores_.size() == 0 ) {
 return ;
 }
 score_ = 0.0;
 for ( unsigned int i = 0; i < scores_.size(); ++i ) {
 double iscore = scores_[i];
 score_ += iscore;
 }
 score_ /= scores_.size(); 

}


void StudentRecord::total_his(void) {

if (scores_.size() == 0 ){
  return ;
}
double a,b,c,d,e;
double smallest = 99999999;
score_ = 0.0;
for (unsigned int i = 0; i < scores_.size(); i++)
  a = scores_[i];
if (a < smallest){
  smallest = a;
  d = (0.4 * smallest);
 }
for (unsigned int i = 0; i < scores_.size(); i++)
  a = scores_[i];
if (a > b){
  b = a;
  e = (0.6 * b);
 }
  score_ = (d + e);
}


/*void StudentRecord::total_lit(void) {
  double a,b,c,d,e,f;
  for (unsigned int i = 0; i < scores_.size(); i++){
  a = score_[0];
  d = a * 0.4;}
  for (unsigned int i = 0; i < scores_.size(); i++){
  b = score_[1];
  e = b * 0.4;}
  for (unsigned int i = 0; i < scores_.size(); i++){
  c = score_[2];
  f = c * 0.2;}
  score_ = d + e + f;

}
void StudentRecord::total_phy(void) {
  double a,b,d,e;
  for (unsigned int i = 0; i < scores_.size(); i++){
  a = score_[0];
  d = a * 0.8;}
  for (unsigned int i = 0; i < scores_.size(); i++){
  b = score_[1];
  e = b * 0.2;
  }
  score_ = d + e;

}
*/

void StudentRecord::total_phy(void) {
if (scores_.size() == 0 ){
  return ;
}
double a,b,c,d,e;
score_ = 0.0;
for (unsigned int i = 0; i < scores_.size(); i++)
  if ( i == 0){
    a = 0.8 * scores_[i];}
  else if (i == 1){
    b = 0.2 * scores_[i];}

c = a + b;
score_ = c;
}


void StudentRecord::total_lit(void) {
  if (scores_.size() ==0){
    return ;
  }
  double a,b,c,d,e,f;
  for (unsigned int i = 0; i < scores_.size(); i++){
    if (i == 0){
      a = 0.4 * scores_[i];}
    else if (i == 1){
      b = 0.4 * scores_[i];}
    else if (i == 2){
      c = 0.2 * scores_[i];}
    d = a + b + c;
    score_ = d;
  
  }
}
