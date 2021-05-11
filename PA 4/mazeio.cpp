/* 
mazeio.cpp
*/

#include <iostream>
#include <fstream>
#include "mazeio.h"

using namespace std;

/*************************************************
 * read_maze:
 * Read the maze from the given filename into a 
 *  2D dynamically  allocated array.
 * 
 * Return the pointer to that array.
 * Return NULL (a special address) if there is a problem, 
 * opening the file or reading in the integer sizes.
 *
 * The first argument is the filename of the maze input.
 *  You should use an ifstream to open and read from this
 *  file.
 *
 * We also pass in two pointers to integers. These are
 * output parameters (i.e. declared by the caller and 
 * passed-by-reference for this function to fill in).
 * Fill the integers pointed to by these arguments
 * with the number of rows and columns 
 * read (the first two input values).
 *
 *************************************************/
char** read_maze(char* filename, int* rows, int* cols) 
{
	
  // *** You complete ****
	ifstream ifile(filename);
  if(ifile.fail()){
    return NULL;
  }
  int row; int col;
  ifile >> row >>col;
  *rows=row;
  *cols=col;
  if(ifile.fail()){
    return NULL;
  }
  char** mazeArr=new char*[row];
  for(int i=0;i<row;i++){
    mazeArr[i]= new char[col];
  }
  for(int i=0;i<row;i++){
    string currRow;
    ifile >> currRow;
    for(int j=0;j<col;j++){
      mazeArr[i][j]=currRow[j];
      if(mazeArr[i][j]!='#'&&mazeArr[i][j]!='S'&&mazeArr[i][j]!='F'&&mazeArr[i][j]!='.'){
        return NULL;
      }
    }
  }
  return mazeArr;
}

/*************************************************
 * Print the maze contents to the screen in the
 * same format as the input (rows and columns, then
 * the maze character grid).
 *************************************************/
void print_maze(char** maze, int rows, int cols) 
{
	
  // *** You complete ****
  cout << rows << " " << cols << endl;
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      cout << maze[i][j];
    }
    cout << endl;
  }
}

