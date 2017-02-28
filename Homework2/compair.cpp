#include <iostream>
#include <string>

int main(void) {

  std::string s1,s2,s3;
  std::cout << "Enter a string: ";
  std::cin >> s1 >> s2 >> s3;

 
  std::cout << "s1 = " << s1 << std::endl;
  std::cout << "s2 = " << s2 << std::endl;
  std::cout << "s3 = " << s3 << std::endl;

  if (s1 == "Yay!") {
    std::cout << "Yay? Just what I was thinking!" << std::endl;
  }
}
