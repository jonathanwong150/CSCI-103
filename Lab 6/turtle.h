#include "draw.h"
//This file starts out empty!
//Define the Turtle class here.
class Turtle{
  public:
    Turtle(double x0, double y0, double dir0); //Constructor
    void turn(double deg);
    void move(double dist);
    void setColor(Color c);
    void off();
    void on();
  private:
    double _x0;
    double _y0;
    double _dir0;
    Color _c;
    bool draw;
};