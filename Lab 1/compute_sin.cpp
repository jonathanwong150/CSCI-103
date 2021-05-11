/* Author: Jonathan Wong
 * Program: compute_sin
 * Description: Reads a number x from input, an angle in radians. 
 *    Computes an approximation to sin(x) using an 4th-order Taylor series.
 */
#include <iostream>
#include <cmath>

using namespace std;

int fact(int); // declares a function the skeleton defines for you.

int main(int argc, char *argv[])
{
   // Declare any variables you need here
   double x;
   double sum=0;
   double sign=1.0; //will alternate from - to +
   // Prompt the user
   cout << "Enter x in radians:  ";
   
   // get input
   cin >> x;
   
   // Do some operations
   for(int i=1; i<=7; i+=2,sign*=-1){ //runs when i is 1,3,5, and 7
     sum+=(sign*pow(x,i))/fact(i); 
   }
   
   // Print the result to the user
   cout << sum << endl;
   
   // You're done
   return 0;
   
}

// here's the actual definition of fact, declared earlier.
int fact(int n)
{
   int result = 1;
   for (int i = 1; i <= n; i++) {
      result = result * i;
   }
   return result;
}

