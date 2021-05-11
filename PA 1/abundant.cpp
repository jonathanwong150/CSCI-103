/********************************************************
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  Failure to follow this direction will lead
 *   to a score of 0 on this part of the assignment.
 ********************************************************/
//Name: Jonathan Wong
//Email: jzwong@usc.edu
/*Description: This program takes a series of user
inputted numbers and finds the sum of divisors for each
number. If the sum of the divisors is greater than
the number itself, increment "num_abundant" by 1.
Store the 3 greatest abundant numbers and the sum of their
divisors, sort them, and output them.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;

  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /*====================*/
  /* Start of your code */
  int in;
  cin >> in;
  while(in != 0){
    int sum=0; 
    for(int i=1; i<in; i++){
      if(in % i == 0){ //Find divisors
        sum+=i; //Add sum of divisors
      }
    }
    if(sum>in){ //If abundant,
      num_abundant++; //Increment count
      if(sum>a1){//If greater than 1st, shift down
        a3= a2;
        n3= n2;
        a2= a1;
        n2= n1;
        a1= sum;
        n1= in;
      }else if(sum>a2){ //If greater than 2nd, shift down
        a3= a2;
        n3= n2;
        a2= sum;
        n2= in;
      }else if(sum>a3){//If greater than 3rd, set to a3,n3
        a3= sum;
        n3= in;
      }
    }    
    cin >> in;
  }
  /* End of your code */
  /*==================*/
  
  
  cout << "Abundant number count: " << num_abundant << endl;
  cout << "Top 3 most abundant numbers: " << endl;
  cout << n1 << " : " << a1 << endl;
  cout << n2 << " : " << a2 << endl;
  cout << n3 << " : " << a3 << endl;


  return 0;

}
