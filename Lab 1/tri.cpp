#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]){
  cout << "Enter the angle theta in degrees: " << endl;
  double theta;
  cin >> theta;
  double rad=theta*(M_PI/180); //convert to radians
  for(int y=0;y<31;y++){ //height of triangle
    cout << endl;
    double x= floor(y*tan(rad)); //base of triangle
    for(int j=1; j<=x;j++){ //creates base
      if(x>=20 && x<=30){ //Only print 20 stars per line
        for(int z=0;z<20;z++){
          cout << "*";
        }
        break; 
      }else{
        cout << "*";
      }  
    }
  }
}