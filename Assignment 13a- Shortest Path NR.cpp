/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//Shortest Path Non-Recursive
#include <iostream>
#include <string>
using namespace std;
 
const int ROWS = 5, COLS = 6;

int minimum(int x, int y, int z){
    if(x<y && x<z)
        return x;
    else if(y<x && y<z)
        return y;
    return z;
} 
 
void calculateCosts() {
    static int weight[ROWS][COLS] = { {3,4,1,2,8,6},
                                      {6,1,8,2,7,4},
                                      {5,9,3,9,9,5},
                                      {8,4,1,3,2,6},
                                      {3,7,2,8,6,4} };
 
    // Initialize the cost matrix and path matrix.
    int cost[ROWS][COLS] = {};
    string path[ROWS][COLS] = {};
 
    // Step 1: fill out the leftmost column of cost matrix and path matrix.
    for (int i = 0; i< ROWS; i++) {
        cost[i][0]= weight[i][0];
        path[i][0]=to_string(i);
    }
 
 
    // fill out the rest of the cost and path matrix
    // finish all the rows in one column and then go to next column just like 8 queens, 
    // so column is the outer loop, row is the inner loop.
    for (int j = 1; j < COLS; j++) {    // Step 4: repeat until you finish all columns in the matrix
        for (int i = 0; i < ROWS; i++) {	// Step 3: repeat until you finish all rows on that column
 
            // Step 2a: find the minimum from left-up, left and left-down
            int left= cost[i][j-1];
            int up= cost[(i-1+ROWS)%ROWS][j-1];
            int down= cost[(i+1)%ROWS][j-1];
            int minCost= minimum(up, left, down);
            
            // Step 2b: add the min to itself and update the cost matrix: 
            // cost[i][j] = weight[..][..] + min
            cost[i][j]= weight[i][j]+minCost;
 
            // Step 2c: update the path matrix:
            // path[i][j] = path[i][...(min: left/up/down)... ] + to_string(i);
            if(minCost == left) path[i][j] = path[i][j - 1] + to_string(i); //left
            if(minCost == up) path[i][j] = path[(i-1+ROWS)%ROWS][j-1] + to_string(i); //up
            if(minCost == down) path[i][j] = path[(i+1)%ROWS][j-1] + to_string(i); //down
            
        }
    }
 
 
 
 
 
    int minRow = 0;
    int minC = cost[0][COLS-1];
    // write a loop to check your rightmost column of the cost matrix and see which row has the minimum cost.
    for(int i=0; i<ROWS; i++){
        if (cost[i][COLS-1] < minC)
         minRow = i;
         minC = cost[i][COLS-1];
    }
      
    
    cout << "The length of the shortest path is " << cost[minRow][COLS - 1];
    cout << ".\nThe ROWS of the path from left to right are " << path[minRow][COLS - 1] << ".";
}
 
int main() {
    calculateCosts();
    return 0;
}

