/* Author: YOUR NAME HERE
 * Program: color_conv
 * Description: Converts RGB -> CMYK color representation
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  double r;
  double g;
  double b;
  cout << "Enter 3 integers (red, green, and blue), in that order:";
  // Enter your code here
  cin >> r;
  cin >> g;
  cin >> b;
  double white= max(max(r/255,g/255),b/255);
  double cyan= (white-(r/255))/white;
  double magenta= (white-(g/255))/white;
  double yellow= (white-(b/255))/white;
  double black= 1-white;
  cout << "cyan: " << cyan << endl;
  cout << "magenta: " << magenta << endl;
  cout << "yellow: " << yellow << endl;
  cout << "black: " << black << endl;
  return 0;
}