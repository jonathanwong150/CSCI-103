// wscramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
//  arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>

using namespace std;

// Scramble the letters of this string randomly
void permute(char items[], int len);

/* Delete the array below and replace by reading in words from a file 
   in main() */

int main(int argc, char*argv[]) {
  
  srand(time(0));
  char guess[80];
  
  if(argc < 2){ //Quit if there is no file to read
    cout << "No file inputted." << endl;
    return 1;
  }
  ifstream wordfile(argv[1]); 
  if(wordfile.fail()){ //Quit if file is invalid or doesn't exist
    cout << "Invalid file"<< endl;
    return 2;
  }
  int numWords;
  wordfile >> numWords; //Sets the amount of word in wordbank
  if(wordfile.fail()){ //Quit if an int isn't first value in file
    cout << "Failed to enter int." << endl;
    return 3;
  }
  char** wordBank = new char*[numWords]; //Allocate wordBank of char*s
  char buf[41]; 
  for(int i=0; i< numWords;i++){ //Iterate through all words in file
    wordfile >> buf; //Set buf to word at wordBank[i]
    char* buf2= new char[strlen(buf)+1];//Create buf2
    strcpy(buf2,buf); //Create copy of buf into buf 2
    wordBank[i]=buf2; //Point at buf2
  }
  bool wordGuessed = false;
  int numTurns = 10;
 
  // Pick a random word from the wordBank
  int target = rand() % numWords;
  int targetLen = strlen(wordBank[target]);

  // Make a dynamically-allocated copy of the word and scramble it
  char* word = new char[targetLen+1];
  strcpy(word, wordBank[target]);
  permute(word, targetLen);
  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while (!wordGuessed && numTurns > 0) {
    cout << "Scrambled word: " << word << endl;
    cout << "What do you guess the original word is? ";
    cin >> guess;
    // Complete the next line of code
    if(strcmp(guess, wordBank[target])==0){ 
      wordGuessed=true;
    }
    numTurns--;   // Every guess counts as a turn
  }
  if (wordGuessed) {
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }
  // Free up any necessary memory
  wordfile.close(); //Close wordfile
  for(int i=0; i< numWords;i++){ //Delete each pointer in wordBank
    delete[] wordBank[i];
  }
  delete[] wordBank;
  delete [] word;
  return 0;
} 

// Scramble the letters. See "Knuth shuffle".
void permute(char items[], int len) {
  for (int i = len-1; i > 0; --i) {
    int r = rand() % i;
    char temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }
}

