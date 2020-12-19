/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
//RECURSIVE 8 NUMBERS IN A CROSS
 
bool ok(int *q , int c) {
    static int checkList[8][5] = {
      {-1}, // box 0's checklist
      {0,-1},   // box 1's checklist
      {1,-1},  //box 2's checklist
      {0,1,2,-1},   // box 3's checklist
      {1,2,3,-1},   // box 4's checklist
      {2,4,-1},   // box 5's checklist
      {0,3,4,-1},   // box 6's checklist
      {3,4,5,6,-1},   // box 7's checklist
   };
 
   // Test 1: Similar to row test in 8 Queens
   for(int i=0; i<c; i++) {
      if(q[c]==q[i])
        return false;
   }
   // Test 2: Make sure no two adjacent boxes contain consecutive numbers
   for(int i=0; checkList[c][i]!=-1; i++) {
      int neighborBox = checkList[c][i];
      if(abs(q[c]-q[neighborBox])==1) return false;
   }
   return true;
}
 
void print(int *q) {
   static int solution = 1;
   cout << "solution " << solution++ <<endl;
   cout << " " << " " << q[1] << q[2] << endl;
   cout << " " << q[0] << q[3] << q[4] << q[5] << endl;
   cout << " " << " " << q[6] << q[7] << endl;
   cout << "----------------" << endl;
}
 
void next(int *q , int c) {
    if(c > 7){ 
        print(q); // pass the last column, so you find a solution (base case, returns)
    }
    
    for(int j = 1; j < 9; j++) { 	// next row
            q[c]=j;
            if(ok(q, c))
                next(q, c+1) ;		// next column
        }
    
}

int main() {
   int q[8];
   next(q, 0);
   return 0;
}


