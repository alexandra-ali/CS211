/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


//Shortest Path Recursive
 
#include <iostream>
#include <string>
using namespace std;
 
const int ROWS = 5, COLS = 6;
string path[ROWS][COLS]; // stores a string of cumulative row numbers to the target square.

int minimum(int x, int y, int z){
    if(x<y && x<z)
        return x;
    else if(y<x && y<z)
        return y;
    return z;
} 
 
// Returns the cost of the shortest path from left to any target square with row i, column j.
int calculateCost(int i, int j) {
    // Given a weight matrix.
    static int weight[ROWS][COLS] = { {3,4,1,2,8,6},
                                      {6,1,8,2,7,4},
                                      {5,9,3,9,9,5},
                                      {8,4,1,3,2,6},
                                      {3,7,2,8,6,4} };
 
    // Initialize the cost matrix.
    int cost[ROWS][COLS] = {};
 
    // Memorization: Check if the cost has already been calculated, if so, simply return that.
    // ...
 
    // Base case: the first column
    if (j == 0) {
        cost[i][0] = weight[i][0];
        path[i][0] = to_string(i);
        return cost[i][0];
    }
 
    // Calculate costs of 3 adjacent squares (up, left, down) by calling the function recursively.
    int left = calculateCost(i, j-1); 
    // ... // for up, +Rows to avoid negative numbers in the index
    int up= calculateCost((i-1+ROWS)%ROWS, j-1);
    // ... // for down...
    int down= calculateCost((i+1)%ROWS, j-1);
    
    // Find the minimum of the 3 above adjacent squares (up, left, down).
    // int minCost = 
    int minCost= minimum(up, left, down); 
 
    // Update the cost matrix:
    // cost[i][j] = sum of the weight of target square itself and the min adj square's cost
    cost[i][j] = weight[i][j] + minCost; 
 
    // Update the path matrix:
    // If left is the min cost, get the path to that square from the path matrix and concatenate it with the current row.   
    if(minCost == left) path[i][j] = path[i][j - 1] + to_string(i);
    // ... // if up is the min cost...
    if(minCost == up) path[i][j] = path[(i-1+ROWS)%ROWS][j-1] + to_string(i);
    // ... // if down is the min cost...
    if(minCost == down) path[i][j] = path[(i+1)%ROWS][j-1] + to_string(i);
    return cost[i][j]; 
}
 

 
int main() {
    // set the min as the first row of the last column.
    int minRow = 0;
    int minCost = calculateCost(0, COLS-1);
 
    // loop through all the remaining rows of the last column
    // everytime call the calculateCost function and replace the minRow and minCost if necessary
    for(int i=0; i<ROWS; i++){
        if (calculateCost(i, COLS-1)<minCost){
            minCost= calculateCost(i, COLS-1);
            minRow= i;
        }
    }
    
    
    cout << "The length of the shortest path is " << minCost;
    cout << ".\nThe ROWS of the path from left to right are " << path[minRow][COLS-1] << ".";
    return 0;
}
 

