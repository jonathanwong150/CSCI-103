#include "turtle.h"
#include <cmath>
#include <iostream>
//This file also starts out empty.
//Implement the Turtle class here.
Turtle::Turtle(double x0,double y0, double dir0){
  _x0 = x0;
	_y0 = y0;
	_dir0 = dir0;
  _c= draw::BLACK;
  draw=true;
}
void Turtle::move(double dist){
  double x1=_x0+(dist*cos((M_PI/180)*_dir0));
  double y1=_y0+(dist*sin((M_PI/180)*_dir0));
  draw::setcolor(_c);
  if(draw==true){
    draw::line(_x0,_y0,x1,y1);    
  } 
  _x0=x1;
  _y0=y1;
}
void Turtle::turn(double deg){
  _dir0=_dir0+deg;
}
void Turtle::setColor(Color c){
  _c=c;
}
void Turtle::on(){
  draw=true;
}
void Turtle::off(){
  draw=false;
}