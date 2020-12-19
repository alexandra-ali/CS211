/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
 
bool ok(int q[], int c, int n) {
    for (int i = 0; i < c; i++)
        if (abs(q[c]/n-q[i]/n)==abs(q[c]%n-q[i]%n)) // col difference == row difference
            return false; // bishop c and i are diagonal to each other, not ok
    return true;
}
 
int kBishops(int n, int k) {
    // dynamic allocate an array in heap base on k (num of bishops)
    int *q= new int[k];
 
    // place first bishop at first (top-left) box
    q[0]=0;
 
    int c = 0, solutions = 0;
 
    // Similar Backtracking Algorithm from the assignments we’ve done many times
    while (c >= 0) {    // NEXT BISHOP
        c++; 
        if (c==k) {   // if all the bishop has been put onto the broad
            // increment solution count
            solutions++;
            // backtrack
            c--;
        }
        else 
            //... // start from the position of the previous bishop to avoid duplicate solutions
            q[c]= q[c-1];
      
        while (c >= 0) {    // NEXT SQUARE
            q[c]++;
            if (q[c]==n*n) // If all the squares have been tried (passed the bottom-right square) for this bishop c, backtrack
            c--;
            else
                // ... // check if it's ok to put the bishop on this sqaure...
                if(ok(q, c, n)) break;
        }
    }
    
    //... // free up the memory in heap
    delete[] q;
    return solutions; 
}
 
int main() {
    // Declare n and k.
    int n, k;
    
    while(1){
        cout<<"Enter Value for size of board n: ";
        cin>> n;
        if(n==-1) break;
        cout<<"Enter Value for number of bishops k: ";
        cin>>k;
        if(k==-1) break;
        // check if n >= k
        // call the kBishop(n, k) function to get the number of solutions.
        if(n>=k)
            cout<<"Number of Solutions: "<< kBishops(n,k) << endl;
        else break;

    }    

    return 0;
    
}


