/********************************************************
 * Description:
 *  Displays a 64-bit integer (long long) with
 *   commas for thousands, millions, billions, etc.
 *
 * ** ABSOLUTELY NO ARRAYS, NO `string`, NO `vector` **
 *  usage is allowed.
 *
 * Instead, you may only declare:
 *
 *    bool,
 *    int, or
 *    int64_t (long long)
 *
 *  The only library function allowed is pow(base, exp)
 *    defined in the <cmath> library.
 *
 ********************************************************/
//Name: Jonathan Wong
//Email: jzwong@usc.edu
/*Description: This program takes a 64 bit int and outputs
the number with commas. 
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  long long n;
  cout << "Enter an integer:" << endl;
  /*====================*/
  /* Start of your code */
  cin >> n; 
  if(n < 0){ //If input is negative,
    cout <<"-"; 
    n = -n; //Turn the input positive and output "-" in front
  }
  if(n<1000){ //If the number is less than 1000
    cout <<n; //Print and end program
    return 0;
  }
  long long sub=n;
  int count=0;
  while(sub!=0){ //Finds how many 0s there are
    sub/=10; 
    count++;
  }
  long divisor = pow(10,count-1);//Find value to divide
  while(divisor > 0){
    cout<< n/divisor; //Print first digit
    n%=divisor; //Removes first digit
    divisor/=10;//Changes divisor
    count--;//Decrement count
    if((count % 3 == 0) && (count > 0)){
      cout<<",";
    }
  }
  /* End of your code */
  /*==================*/
  
  return 0;
}
