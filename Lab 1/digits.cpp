#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  cout << "Enter an integer between 0 and 999: ";
  int num;
  cin >> num;
  int ones= num%10;
  num=num/10;
  int tens= num%10;
  num=num/10;
  int hundreds= num%10;
  cout << "1's digit is " << ones << endl;
  cout << "10's digit is " << tens << endl;
  cout << "100's digit is: " << hundreds << endl;
  
}