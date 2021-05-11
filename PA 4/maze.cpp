/* 
maze.cpp
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
   int rows, cols, result;
   char** mymaze= NULL;
   
   if(argc < 2)
   {
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
  
   mymaze = read_maze(argv[1],&rows,&cols); // <---TASK: COMPLETE THIS
   if (mymaze == NULL) {
      cout << "Error, input format incorrect." << endl;
      return 1;
   }
	 //================================
   // When working on Checkpoint 3, you will call maze_search here.
   // But for Checkpoint 1, just assume we found the path.
  
   result = maze_search(mymaze,rows,cols); // <--- TASK: CHANGE THIS
	
	
   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

	 //================================
   // ADD CODE BELOW
   // to delete all memory that read_maze allocated
   for(int i=0;i<rows;i++){
      delete[] mymaze[i];
   }
  delete[]mymaze;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 * NOTE: don't forget to deallocate memory in here too!
 *************************************************/
int maze_search(char** maze, int rows, int cols) 
{
  // *** You complete ****
  Location start;
  int numS=0; int numF=0;
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      if(maze[i][j]=='S'){
        numS++;
        start.row=i;
        start.col=j;
      }else if(maze[i][j]=='F'){
        numF++;
      }
    }
  }
  if(numF!=1 || numS!=1){
    return -1;
  }
  bool** visited= new bool*[rows];
  for(int i=0;i<rows;i++){
    visited[i]= new bool[cols];
  }
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      visited[i][j]=0;
    }
  }
  Queue q(rows*cols);
  q.add_to_back(start);
  visited[start.row][start.col]=1;
  Location** predecessor=new Location*[rows];
  for(int i = 0; i < rows; i++){   
      predecessor[i] = new Location[cols];
  }
  Location pre;
  pre.row=-1;
  pre.col=-1;
  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      predecessor[i][j]=pre;
    }
  }
  bool done=false;
  while(!q.is_empty()){
    Location loc=q.remove_from_front();
    Location N;
    N.row=loc.row-1;
    N.col=loc.col;
    if(N.row>=0&&N.row<rows && N.col>=0&&N.col<cols){
      if(visited[N.row][N.col]==0 && maze[N.row][N.col]=='.'){
        q.add_to_back(N);
        visited[N.row][N.col]=1;
        predecessor[N.row][N.col] = loc;
      }else if(maze[N.row][N.col] == 'F'){
        while(maze[loc.row][loc.col] != 'S'){
          maze[loc.row][loc.col] = '*';
          loc = predecessor[loc.row][loc.col];
        }
        done = true;
        break;
      }
    } 
    Location W;
    W.row=loc.row;
    W.col=loc.col-1;
    if(W.row>=0&&W.row<rows &&W.col>=0&&W.col<cols){
      if(visited[W.row][W.col]==0 && maze[W.row][W.col]=='.'){
        q.add_to_back(W);
        visited[W.row][W.col]=1;
        predecessor[W.row][W.col] = loc;
      }else if(maze[W.row][W.col] == 'F'){
        while(maze[loc.row][loc.col] != 'S'){
          maze[loc.row][loc.col] = '*';
          loc = predecessor[loc.row][loc.col];
        }
        done = true;
        break;
      }
    } 
    Location S;
    S.row=loc.row+1;
    S.col=loc.col;
    if(S.row>=0&&S.row<rows &&S.col>=0&&S.col<cols){
      if(visited[S.row][S.col]==0 && maze[S.row][S.col]=='.'){
        q.add_to_back(S);
        visited[S.row][S.col]=1;
        predecessor[S.row][S.col] = loc;
      }else if(maze[S.row][S.col] == 'F'){
        while(maze[loc.row][loc.col] != 'S'){
          maze[loc.row][loc.col] = '*';
          loc = predecessor[loc.row][loc.col];
        }
        done = true;
        break;
      }
    }
    Location E;
    E.row=loc.row;
    E.col=loc.col+1;
    if(E.row>=0&&E.row<rows &&E.col>=0&&E.col<cols){
      if(visited[E.row][E.col]==0 && maze[E.row][E.col]=='.'){
        q.add_to_back(E);
        visited[E.row][E.col]=1;
        predecessor[E.row][E.col] = loc;
      }else if(maze[E.row][E.col] == 'F'){
        while(maze[loc.row][loc.col] != 'S'){
          maze[loc.row][loc.col] = '*';
          loc = predecessor[loc.row][loc.col];
        }
        done = true;
        break;
      }
    }
  }
  for(int i=0;i<rows;i++){
    delete[] visited[i];
    delete[] predecessor[i];
  }
  delete[] visited;
  delete[] predecessor;
  if(done){
    return 1;
  }
  return 0;
  //return 0; // DELETE this stub, it's just for Checkpoint 1 to compile.
}
