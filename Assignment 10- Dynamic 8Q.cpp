/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
 
bool ok(int q[], int c) {
    // you know how to write this-- write the ok function for 8 Queens
    for (int i=0; i<c; i++) //each i from 0 to c-1
        //if there is another queen in the same row, or in the same right diagonals
        if (q[i]==q[c] || abs(q[i]-q[c])==c-i)
            return false;   // that means you cannot place the queen there
    return true;
}
 
int nqueens(int n) {
    int solutions = 0;
    int c=0;
    // Initalize your variables…
    // Dynamically creates an array of size n.
    int* q = new int [n];
    q[0]=0;
    //The loop goes on until column becomes -1
    while (c >= 0) {
        // write the n queens backtracking algorithm
        // condition to backtrack is based on n
        // simply increment solutions, no need to print
        c++;                
        if (c==n) { 
            solutions++;
            c--;
        }
        else q[c] = -1;    
        while (c >= 0) {  
            q[c]++;           
            if (q[c] == n) c--;  
            else              
                if(ok(q, c)) break; 
        }
         
    }
    
    // Delete the array
    delete[] q;
    return solutions; // Return the number of solutions found.
}
 
int main() {
    // cin >> n; 
    int n = 12;	
    for (int i = 1; i <= n; ++i)
        cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
    return 0;
}

