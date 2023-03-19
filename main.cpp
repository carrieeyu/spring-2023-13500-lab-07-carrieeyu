#include <iostream>
#include "indent.h"
#include "unindent.h"

int main(){
  //Task A
  std:: cout << "Removing indentation from one line:" << std:: endl;
  std:: cout << removeLeadingSpaces("       int x = 1;  \n") << std:: endl;

  std:: cout << "Removing indentation from multiple lines in file:" << std:: endl;
  std:: cout << unindentFile("bad-code.cpp") << std:: endl;

  std:: cout << "--------------------" << std:: endl;
  
  //Task B
  std:: cout << "Counting instances of char '{':" << std:: endl;
  std:: cout << countChar("are there { in this{ for {:", '{') << "\n" << std:: endl; //should return 3

  std:: cout << "Counting instances of char '}'" << std:: endl;
  std:: cout << countChar("sometimes} } fee} b}eh}}}}", '}') << "\n" << std:: endl; //should return 8

  std:: cout << "Adding indentation to multiple lines in file:" << std:: endl;
  std:: cout << indentFile("bad-code.cpp") << std:: endl;

}



