#include <iostream>
#include <fstream>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <string>

using namespace std;


// REQUIRES: str1 and str2 point to C-strings
// EFFECTS:  If st1 and str2 are identical (contain exactly
//           the same characters), returns 0.
//           If the first differing character has a greater
//           value in str1 than in str2, return a positive number.
//           Otherwise, return a negative number.
int strcmp_eecs280(const char *str1, const char *str2){

  // Make auxiliary pointers to move. Note: technically
  // we could just use str1 and str2 directly in this case.
  const char *ptr1 = str1;
  const char *ptr2 = str2;

  // Advance both pointers to first mismatched characters.
  while (*ptr1 && *ptr1 == *ptr2) {
    ++ptr1;
    ++ptr2;
  }

  // Subtract characters to get a difference. If positive,
  // it means str1 is greater, negative means str2 is greater,
  // zero means equal.
  return *ptr1 - *ptr2;

}






// EFFECTS:  Prompts the user to end a word using the prompt
//           "Please enter a word:  " and then reads a string
//           from cin which will be returned. After reading the
//           input, clean up by printing a newline to cout.
string getUserWord(){
  
  string s = "Please enter a word:  ";
  cout << s;

  string s1;
  cin >> s1;
  cout << endl;

  // Return the string from the user
  return s1;

}



// EFFECTS:  Searches words.txt for the word passed as a
//           parameter. If found, return true. Otherwise false.
//           If words.txt cannot be opened, prints an error
//           message to cout and calls exit(1).
//
bool findWord(string query, const char * wordsFile){

	cout << "findWord: query = " << query << endl;

  // Open words.txt file for reading
  ifstream fin(wordsFile);
  string word;
  while (fin >> word) {
    if (strcmp_eecs280(query.c_str(), word.c_str()) == 0) { // 0 means equal
      // If we found the user's word, return true immediately
      return true;
    }
  }

  // If we didn't find it, return false
  return false;
}



// Testing code

void test_strcmp_eecs280() {

  assert(strcmp_eecs280("turtle", "frog") > 0); 
  assert(strcmp_eecs280("turtle", "turtles") < 0); 
  assert(strcmp_eecs280("", "frog") < 0); 
  assert(strcmp_eecs280("lizard", "lizard") == 0); 
  assert(strcmp_eecs280("hello", "hello") == 0);
}







int main(int argc, char *argv[]){

  test_strcmp_eecs280();

  cout << "Welcome to eecs280 spell checker!" << endl;
  cout << "You may quit at any time by typing \"quit\"." << endl;

  for(string userWord = getUserWord(); userWord != "quit"; userWord = getUserWord()){
    
    if (findWord(userWord, argv[1])){
      cout << "It appears " << userWord << " is spelled correctly!";
    }
    else{
      cout << "Oops. " << userWord << " is not a correctly spelled word!";
    }

    cout << endl << endl;
  }
  
  cout << "See you again soon.  Happy spelling!" << endl;

  return 0;
}
