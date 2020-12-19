/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    //Initialize board q[8][8] to 0;
    
    int q[8][8] = {};
    int r=0, c=0;
    static int solution=0;
    
    //Place the first Queen at q[0][0] (1st row, 1st col)
    q[0][0]=1;

nextCol: 
    //Move to the next column
    c++;
    //If passed the last column, (i.e. find a solution) goto print
    if(c>7) goto print;
    //(Otherwise,) reset row to -1 (before the first row)
    else r = -1;

nextRow: 
    //Move to the next row
    r++;
    
    //If passed the last row, (i.e. cannot place a queen on that column) goto backtrack
    if(r>7) goto backtrack;
    
    //If there is a queen in the same row, goto nextRow
    for(int i=0; i<c; i++)
        if(q[r][i]==1) goto nextRow;
    //If there is a queen in the same upper-left diagonal, goto nextRow
    for(int i=1;(r-i)>=0 && (c-i)>=0;i++)
        if(q[r-i][c-i]==1) goto nextRow;
    //If there is a queen in the same lower-left diagonal, goto nextRow
    for(int i=1;(r+i)<8 && (c-i)>=0;i++)
        if(q[r+i][c-i]==1) goto nextRow;
    //Place a queen in the current q[row][col]
    q[r][c]=1;
    
    goto nextCol;

backtrack:
    //Move to the previous column
    c--;
    //If column is -1, (out of board, no more solution can be found), exit the program
    if(c < 0) return 0;
    //Locate the position (row number) of the queen in that column
    r=0;
    while(r<8){
        if(q[r][c]==1) break;
        r++;
    }
    //Remove the queen
    q[r][c]=0;
    
    goto nextRow;

print:
    //Print the solution counter
    cout<<"Solution #: "<< ++solution<<endl;
    
    //Write a nested loop to print the solution
    for(int r=0; r<8; r++){
        for(int c=0; c<8; c++){
            cout<<q[r][c]<< " ";
        }
        cout<<endl;
    }
    cout<< endl;
    
    goto backtrack;



    return 0;
}
