#include <iostream>

using namespace std;

int main(int argc, char*argv[]){
  cout << "Enter a positive integer: ";
  int num;
  cin >> num; //Stores integer
  int numOfTwos=0;
  int numOfThrees=0;
  while(num%3==0||num%2==0){ //As long as number is divisible by 2 or 3
    if(num%2==0){ //Check if divisible by 2
      numOfTwos++;
      num=num/2;
    }
    if(num%3==0){ //Check if divisible by 3
      numOfThrees++;
      num=num/3;
    }
  }
  if(num!=1){ //If not  divisible by primes 2 and 3, must have other prime factors
    cout << "No" << endl;
  }else{
    cout << "Yes" <<endl;
    cout << "Twos=" << numOfTwos << ", Threes=" << numOfThrees << endl;
  }
}