/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
 
bool ok(int q[], int c) {
    for( int i = 0 ;i < c ; i++ )
        if(q[i] == q[c] || c-i == abs(q[c]-q[i]))
            return false ;
    return true ;
}
 
void print(int q[]) {
    static int solutions = 0;
    cout << "Solution #" << ++solutions << ":\n" ;
    for(int i = 0; i < 8; i++) {
        for( int j = 0 ; j < 8 ; j++ ) {
            if(i == q[j]) cout << 1 << " " ;
            else cout << 0 << " " ;
        }
        cout << endl ;  
    }
    cout << endl ;
}
 
void next(int q[], int c) {
    if(c == 8) print(q); // pass the last column, so you find a solution (base case, returns)
    else {
        for(q[c] = 0; q[c] < 8; q[c]++) { 	// next row
            if(ok(q, c)) next(q, c+1) ;		// next column
        }
    }
}
 
int main() {
   int q[8];
   next(q, 0);
   return 0;
}

