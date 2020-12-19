/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    //8 Queens 1D with Goto - Algorithm Steps:
// row = q[c] (element), col = c (index)

    //Initialize board q[8] to 0;
    int q[8]= {0}, c=0;
    static int solution=0;
    //Place the first Queen at q[0] (1st row, 1st col)
    q[0]=0;
    // 2D: q[0][0] = 1 
    // 1D: q[0 (col)] = 0 (row)

nextCol: 
    //Move to the next column
    c++;
    //If passed the last column, (i.e. find a solution) goto print
    if(c>7) goto print;
    //(Otherwise,) reset row to -1 (before the first row)
    else q[c]=-1;

nextRow: 
    //Move to the next row <--- q[c]++ (put the row # of the queen)
    q[c]++;
    //If passed the last row, (i.e. cannot place a queen on that column) goto backtrack
    if(q[c]>7) goto backtrack;

for(int i=0; i < c; i++)
    //If there is a queen in the same row, goto nextRow
    // q[c] == q[i]
   
    //If there is a queen in the same upper-left diagonal, goto nextRow
    // col difference == row difference
    // (c-i) == (q[c] - q[i]) 
    //If there is a queen in the same lower-left diagonal, goto nextRow
    // col difference == row difference
    // (c-i) == (q[i] - q[c])
    if((q[c]==q[i]) || ((c-i) == (q[c] - q[i])) || ((c-i) == (q[i] - q[c]))) goto nextRow;
    

    // Place a queen in the current q[row][col] <- remove this
    
    goto nextCol;

backtrack:
    //Move to the previous column
    c--;
    //If column is -1, (out of board, no more solution can be found), exit the program
    if(c==-1) return 0;
    // Locate the position (row number) of the queen in that column <- remove this
    // Remove the queen <- remove this
    goto nextRow;

print:
    //Print the solution counter
    cout<<"Solution #"<< ++solution<<": ";
    //Write a loop to print the solution
    for (int i = 0; i<8; i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;
    goto backtrack;




    return 0;
}
