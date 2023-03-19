//Task A
// function takes one line of code as input and returns its copy without leading spaces and tabs

/*
Make use of the function isspace defined in <cctype> to check if a character is a whitespace. Your function should probably iterate over the input string, skip all spaces, and after it finds the first non-space character, start accumulating the characters into a new string, which will be returned.

Write a program unindent.cpp that reads input from cin and prints out each input line with leading spaces removed.
*/

/*
example:
removeLeadingSpaces("       int x = 1;  ") --> "int x = 1;  "
*/

#include <iostream>
#include <fstream>
#include "unindent.h"
#include <cctype>

//need to fix; adding characters to string result
/*
std:: string removeLeadingSpaces(std:: string line){
  std:: string result;
  int index;
  int count = 0;

  for(int i = 0; i < line.length(); i++){
    if(isspace(line[i]) == false){ //if not a space
      count++; //counting up to the first index that doesn't return a space
      index = count;
    }
  }
  return line.substr(index, line.length()-1); //returns the string's contents without the unnecessary indentation

}
*/

std:: string removeLeadingSpaces(std:: string line){
  
  std:: string result;
  bool space = true;

    for(int i = 0; i < line.length(); i++){
    if(isspace(line[i]) == false){ 
      space = false;
    }

    if(space == false){ //when it's a character
      result += line[i]; //add it to the string
    }
      
  }
  return result;

}

std:: string unindentFile(std:: string filename){

  std:: string unindentResult; 
  std:: ifstream fin("bad-code.cpp"); //opens file

  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
    }

  std:: string line; // new string variable
  
  while(getline(fin, line)){ //reading each line
    unindentResult += removeLeadingSpaces(line) + "\n"; //adding each unindented line 
  }  
  fin.close(); //closes file

  return unindentResult;

}

 
