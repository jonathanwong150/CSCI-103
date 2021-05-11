#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) {
  for(int i=0 ; i<width ; i++){
    if(left+i<=255 && left+i>0){
      if(top>=0 && top<=255){
        image[top][left+i]=0;
      }
      if(top+height<=255 && top+height>=0){
        image[top+height][left+i]=0;
      }  
    }
  } 
  for(int j=0 ; j<height ; j++){
    if(j+top<=255 && j+top>=0){
      if(left<=255 && left>=0){
        image[top+j][left]=0;
      }
      if(left+width<=255 && left+width>=0){
        image[top+j][left+width]=0;
      }
    }  
  }
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) {
  double rx=width/2;
  double ry=height/2;
  for(double theta=0;theta<=2*M_PI;theta+=0.01){
    double x=rx*cos(theta);
    double y=ry*sin(theta);
    if(cy+(int)(y)<=255 && cy+(int)(y)>=0 && cx+(int)(x)<=255 && cx+(int)(x)>=0){
      image[cy+(int)(y)][cx+(int)(x)]=0;
    }
  }
}


int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
  int shape;
  int p1;
  int p2; 
  int p3;
  int p4;
  cout << "Enter 0 and top, left, height, and width for a rectangle." << endl;
  cout << "Enter 1 and cy, cx, height, and width for an ellipse." << endl;
  cout << "Enter 2 to quit: ";
  cin >> shape;
  if(shape!=2){
    cin >> p1 >> p2 >> p3 >> p4;
  }
  while(shape!=2){
    if(shape==0){
      draw_rectangle(p1, p2, p3, p4);
    }else if(shape==1){
      draw_ellipse(p1,p2,p3,p4);
    }
    cout << "Enter a shape and its 4 parameters: ";
    cin >> shape;
    if(shape!=2){
      cin >> p1 >> p2 >> p3 >> p4;
    }
  }
   // Write the resulting image to the .bmp file
   //draw_rectangle(10, 10, 20, 20); 
  writeGSBMP("output.bmp", image);
  return 0;
}
