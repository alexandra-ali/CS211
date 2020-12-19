#include <iostream>
#include <cmath>
using namespace std;
 
// Returns true if the queen placed in column c is ok
bool ok(int q[], int c) {
    for (int i=0; i<c; i++) //each i from 0 to c-1
        //if there is another queen in the same row, or in the same right diagonals
        if (q[i]==q[c] || abs(q[i]-q[c])==c-i)
            return false;   // that means you cannot place the queen there
    return true;
}
 
void print(int q[]) {
    static int sol = 1;
    // Print the solution count
    // ...
    cout <<"Solution #"<< sol++ <<":"<< endl;
    // First print the array like this: 0 4 7 5 2 6 1 3
    // ...
    for (int i=0; i<8; i++){
        cout<<q[i]<<" ";
    }
    cout<<endl;
    /* Then print the array in 2D like this: 
        1 0 0 0 0 0 0 0
        0 0 0 0 0 0 1 0
        0 0 0 0 1 0 0 0
        0 0 0 0 0 0 0 1
        0 1 0 0 0 0 0 0
        0 0 0 1 0 0 0 0
        0 0 0 0 0 1 0 0
        0 0 1 0 0 0 0 0
    */
    for (int r= 0; r<8; r++){
        for (int c=0; c<8; c++){
            if(q[c]==r)
                cout<<"1"<<" ";
            else cout <<"0"<<" ";
        }
        cout<<endl;
    }
    
}
 
// For 1D version of 8 Queens: 
// c (index) is the column #, q[c] (element) is the row # where a queen is placed
int main() {
    // Initialize necessary variable, array...
    int q[8]={0}, c=0;
    // Place the first queen in the first row, first column...
    q[0]=0;
    while (c >= 0) { // End the loop if you backtrack from the first column
        // Move to the next column
        // If you have passed the last column,
        // Call the print function and backtrack
            if (c==7){
                print(q);
                c--;
            }
            
        // Otherwise, set q[c] to -1 (before the first row), 
            else q[++c]=-1;
        while (c >= 0) { 
            // Move to the next row
            ++q[c];
            // If you have passed the last row, backtrack
            if (q[c]>7) --c;
            // Otherwise, call the ok function. If it returns true, go back to the outer loop.
            else if(ok(q,c)) break;
        }
    }
    return 0;
}
