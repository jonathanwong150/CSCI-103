// game.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter

  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  for(int i=0;i<(int)strlen(targetWord);i++){ //Populate word array
    word[i]='*';
  }
  word[strlen(targetWord)]='\0';
  while(numTurns>0 && strcmp(word,targetWord)!=0){ //While user still has turns and hasnt won
    cout << "Current word: " << word << endl;
    cout << numTurns << " remain...Enter a letter to guess:" << endl;
    cin >> guess; //Take char as input
    int appear= processGuess(word, targetWord, guess); //function call
    if(appear==0){
      numTurns--; //If guess doesnt appear in targetWord
    }
  }
  
  // Print out end of game status
  if(strcmp(word,targetWord)==0){
    cout << "The word was: " << word << ". You win!" <<endl;
  }else{
    cout << "Too many turns...You lose!" <<endl;
  }

  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int count=0; //count for while loop
  int appear=0; //amount of times guess appears in targetWord
  while(targetWord[count]!='\0'){ //Loop through targetword
    if(targetWord[count]==guess){ //If guess is in targetword
      word[count]=guess; //Reveal character in word
      appear++;
    }
    count++;
  }
  return appear;
}