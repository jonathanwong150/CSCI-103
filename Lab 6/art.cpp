#include "turtle.h"
int main(){
  draw::setrange(-100, 100);
  Turtle t1(0,0,0);
  t1.setColor(draw::ORANGE);
  Turtle t2(30,20,60);
  t2.setColor(draw::BLUE);
  Turtle t3(-30,-20,45);
  t3.setColor(draw::GREEN);
  Turtle t4(80,80,180);
  t4.setColor(draw::RED);
  for(int i=0;i<5;i++){
    t1.move(10);
    t1.turn(40);
    t2.move(25);
    t2.turn(240);
    t3.turn(86);
    t3.move(50);
  }
  t4.move(10);
  t4.turn(12);
  t4.move(30);
  draw::show(100);
  return 0;
}