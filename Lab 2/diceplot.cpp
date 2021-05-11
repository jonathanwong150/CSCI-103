#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int roll(){
  int random= rand() % 6 + 1;
  return random;
}
void printHistogram(int counts[]){
  for(int i=4;i<=24;i++){
    cout << i << ":";
    for(int j=0;j<counts[i-4];j++){ //Print amount of Xs at index of j
      cout << "X";
    }
    cout << endl;
  }
}
int main(int argc, char* argv[]){
  srand(time(0)); //Seed random
  cout << "Input a number: ";
  int n;
  cin >> n; //Take input
  int sums[21]; //Create and populate array
  for (int i=0;i<21;i++){
    sums[i]=0;
  }
  int sum;
  for (int i=0;i<n;i++){ //Run n amount of times
    for(int j=0;j<4;j++){ //Roll 4 dice
      sum+=roll();
    }
    sums[sum-4]++; //Increment index where sum resides
    sum=0; //Reset
  }
  printHistogram(sums); //Print
}
//10 3-headed dice
/*
int roll(){
  int random= rand() % 3 + 1;
  return random;
}
void printHistogram(int counts[]){
  for(int i=10;i<=30;i++){
    cout << i << ": ";
    for(int j=0;j<counts[i-10];j++){
      cout << "X";
    }
    cout << endl;
  }
}
int main(int argc, char* argv[]){
  srand(time(0));
  cout << "Pick a number: ";
  int n;
  cin >> n;
  int sums[21];
  for (int i=0;i<21;i++){
    sums[i]=0;
  }
  int sum;
  for (int i=0;i<n;i++){
    for(int j=0;j<10;j++){
      sum+=roll();
    }
    sums[sum-10]++;
    sum=0;
  }
  printHistogram(sums);
}
*/