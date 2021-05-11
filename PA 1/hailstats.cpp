//Name: Jonathan Wong
//Email: jzwong@usc.edu
/*Description: This program iterates through 2 user
inputted values to find the numbers with the greatest
and least length. Using the hail function from the previous
program, I ran a for loop to that goes through each
number in between the two inputs and finds the length.
Then, if that length is greater or less than the previous
max or min values respectfully, update the values and print.
*/

#include <iostream>

using namespace std;

int hail(int num){ //Function that finds the length
  int count=0;
  while(num!=1){ //Loop as long as the number isn't 1
    if(num%2==0){ //Alteration if number is even
      num/=2;
      count++;
    }else{ //Alteration if number is odd
      num*=3;
      num++;
      count++;
    }
  }
  return count;
}
int main(int argc, char* argv[]){
  cout << "Enter the range that you want to search: ";
  int low;
  int high;
  cin >> low; //Stores high and low variables
  cin >>high;
  if(low>high){ //If the 1st input is greater than the 2nd
    cout << "Invalid range" <<endl; //Print invalid
    return 0; //End program
  }
  int maxLength=-1; //Sets the max and min length and value
  int minLength=100000;
  int maxNum;
  int minNum;
  for(int i=low; i<=high;i++){ //Run loop through inputs
    int temp=hail(i);
    if(temp<minLength){ //If hailstone length < min
      minLength=temp; //Update min values
      minNum=i;
    }
    if(temp>maxLength){ //If hailstone length > max
      maxLength=temp; //Update max values
      maxNum=i;
    }
  }
  cout << "Minimum length: " << minLength <<endl; //Output
  cout << "Achieved by: " << minNum <<endl;
  cout << "Maximum length: " << maxLength <<endl;
  cout << "Achieved by: " << maxNum <<endl;
}
  