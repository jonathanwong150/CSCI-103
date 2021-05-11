//Name: Jonathan Wong
//Email: jzwong@usc.edu
/*Description: This program takes a number inputted
by the user and reassigns the number variable 
depending on if it is even or odd. If the number is even,
divide it by 2, if it is odd, multiply by 3 and add 1. 
Final output should be the all the numbers and how many
steps it took to reach 1.
*/

#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
  cout << "Enter a number: " << endl;
  int num=-1; 
  cin >> num; //Takes user input
  int count=0;
  while(num!=1){ //Loop as long as the number isn't 1
    if(num%2==0){ //Alteration if number is even
      num/=2;
      count++;
      cout << num << " ";
    }else{ //Alteration if number is odd
      num*=3;
      num++;
      count++;
      cout << num << " ";
    }
  }
  cout << "Length: " << count <<endl; //Print length
}