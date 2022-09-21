#include <iostream>
#include <cstring>
/*Name: Ishaan Varma
Purpose of this file: Where everything for the Palindrome program is
Purpose of thsi file cont: Where the input is taken in, and whether the sentence is a palindrome or not
Date: 9/21/2022
 */
//done so that I don't have to type std::cout
using namespace std;

//main
int main() {
  //array where input is stored
  char input[80];
  //tells what the program does
  cout << "Enter a sentence. This program will check if it is a palindrome." << endl;
  //gets user input and clears the input from cin.get after getting the input
  cin.get(input, 80, '\n');
  cin.get();
  //where the original sentence and the reverse are stored with only lower case letters
  char palindrome[80];
  char reverse[80];
  //stores how many characters are in the array
  int size = 0;
  //stores the smallest index not filled with a characer
  int index = 0;
  
  //stores whether the null character has been found
  bool nullcheck = false;
  for(int i = 0; i < 80; i++) {
    //puts the character in the input into its ascii value
    int character = (int) input[i];
    //if the character is the null character, make nullcheck true so that the rest of the array is not looped through
    if(character == '\0') {
      nullcheck = true;
    }
    //if the null character hasn't been hit...
    if(nullcheck == false) {
      //and the character is lower case...
      if(character <= 122 && character >= 97) {
	//increment the size by one, put the character from the input into the palindrome array in the smallest available index
	size++;
        palindrome[index] = (char) character;
	//and increment the index by 1
	index++;
      }
      //if the character is uppercase, make it lower case, and do the same
      else if(character <= 90  && character >= 65) {
        character += 32;
        size ++;
        palindrome[index] = (char) character;
	index++;
      }
    }
  }
  int reverseIndex = 0;
  for(int i = size-1; i >=0; i--) {
    reverse[reverseIndex] = palindrome[i];
    reverseIndex++;
  }
  palindrome[size] = '\0';
  reverse[size] = '\0';
  /*for(int i = 0; i <= size; i++) {
    cout << "palindrome[" << i << "]: " << palindrome[i] << endl;
  }
  for(int i = 0; i <= size; i++) {
    cout << "reverse[" << i << "]: " << reverse[i] << endl;
    }*/
  bool actualPalindrome = false;
  //cout << "comparison result: " << strcmp(palindrome,reverse) << endl;
  if(strcmp(palindrome,reverse) == 0) {
    actualPalindrome = true;
  }
  if(actualPalindrome == true) {
    cout << "This is a palindrome!" << endl;
  }
  else {
    cout << "This is not a palindrome." << endl;
    cout << "Palindrome: " << palindrome << endl;
    cout << "Reverse: " << reverse << endl;
  }
  return 0;
}
