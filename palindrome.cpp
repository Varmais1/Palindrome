#include <iostream>
#include <cstring>


using namespace std;

int main() {
  char input[80];
  cout << "Enter a sentence. This program will check if it is a palindrome." << endl;
  cin.get(input, 80, '\n');
  cin.get();
  char palindrome[80];
  char reverse[80];
  int size = 0;
  int index = 0;
  int loop = 0;
  
  bool nullcheck = false;
  for(int i = 0; i < 80; i++) {
    int character = (int) input[i];
    if(character == '\0') {
      nullcheck = true;
    }
    if(nullcheck == false) {
      if(character <= 122 && character >= 97) {
        index++;
        size++;
        palindrome[index] = (char) character;
      }
      else if(character <= 90  && character >= 65) {
        character += 32;
        index++;
        size ++;
        palindrome[index] = (char) character;
      }
    }
  }
  int reverseIndex = 0;
  for(int i = size; i >=0; i--) {
    reverse[reverseIndex] = palindrome[i];
    reverseIndex++;
  }
  if(strcmp(palindrome,reverse) == 0) {
  cout << "This is a palindrome!" << endl;
  }
  else {
    cout << "This is not a palindrome." << endl;
    cout << "Palindrome: " << palindrome << endl;
    cout << "Reverse: " << reverse << endl;
  }
  return 0;
}
