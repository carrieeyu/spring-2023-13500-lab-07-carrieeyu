#include <iostream>
#include <fstream>
#include "indent.h"
#include "unindent.h"

int countChar(std:: string line, char c){

  int count = 0;

  for(int i = 0; i < line.length(); i++){
    if(line[i] == c){
      count ++;
    }
  }
  return count;
  
}

std:: string indentFile(std:: string filename){

  std:: ifstream fin(filename); 

  std:: string indentResult; 
  std:: string line; 
  int countBlocks = 0; //keeping track of open blocks 

  while(getline(fin, line)){

    line = removeLeadingSpaces(line); //func from Task A removes indents from each line
    
    //to prevent closed braces from indenting one level further than they should
    if(line[0] == '}'){ //if the first char of the current line is a closed brace,
      countBlocks--; //then reduce the indentation level by 1
    }
    
    for(int i = 0; i < countBlocks; i++){ //looping through open blocks
      indentResult += "\t"; //indentation after each open brace(open block)
    }
    indentResult += line + "\n";
    countBlocks += countChar(line, '{'); //number of tabs according to number of open braces/blocks
    //1
    countBlocks -= countChar(line, '}'); //number of tabs for closed braces
    //2
  }
  fin.close(); 

  return indentResult;
}


//note to self

//1
//std:: cout << countChar(line, '{') << std:: endl; //found in 1st and 4th lines-->2
//1,1,1-->1,2 and 1,2

//2
//std:: cout << countChar(line, '}') << std:: endl; //found in 7th and 8th lines-->2
//7th line; minus 1 tab bc first char=} and then 1--> 1,0
