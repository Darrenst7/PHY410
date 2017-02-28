#include <iostream>


int factorial(int n);
int main()
{
  int n;
  std::cout << "Enter a positive integer less than 20." << std::endl;
  std::cin >> n;
  
  if(n<0){
   std::cout << "PLEASE FOLLOW INSTRUCTIONS!" << std::endl;
  }
  else if(n>19){
   std::cout << "Keep it below 20 big guy!" << std::endl;
  }
  else{
std::cout << "And the answer is " << factorial(n)<< "!!!!!!!!!" << std::endl;
  }

  
    
  return 0;
  
}
int factorial(int n)
{
  if(n>1)
    return n*factorial(n-1);
  
  else 
   return 1;
  


}
