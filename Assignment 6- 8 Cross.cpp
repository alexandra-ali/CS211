/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
 
bool ok(int q[], int c) {
   static int checkList[8][5] = {
      // write this according to how you set up the cross (refer to the print function)
      // aka indicator
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
      // if (the number you are writing to box c has already been written to previous boxes)
      if(q[c]==q[i])
        return false;
   }
 
   // Test 2: Make sure no two adjacent boxes contain consecutive numbers
   for(int i=0; checkList[c][i]!=-1; i++) {
      int neighborBox = checkList[c][i];
 // if (the number you are writing in box c is consecutive to the number in it’s adjacent squares, i.e., one of box c's checklist)
      if(abs(q[c]-q[neighborBox])==1) return false;
   }
   return true;
}
 
void print(int q[]) {
   static int solution = 1;
   cout << "solution " << solution++ <<endl;
   cout << " " << " " << q[1] << q[2] << endl;
   cout << " " << q[0] << q[3] << q[4] << q[5] << endl;
   cout << " " << " " << q[6] << q[7] << endl;
   cout << "----------------" << endl;
}
 
 
// c is the box index
// q[c] is the number to fill in the box
// Similar backtracking algorithm from the 8 Queens without Goto Assignment
int main() {
 
   // initialize…
   int q[8], c=0; 
   q[0]=1;
   while (c >= 0) { // BOX PART:
      // Move to the next box
        c++;
      // If you completed all the boxes, you found a solution
          // call the print function and backtrack
      if(c>7){ 
        print(q);
        c--;
      }
      // Otherwise, reset number to 0, so you will start from number 1 in the inner loop
      else q[c]=0;
      while (c >= 0) { // NUMBER PART:
         // Move to the next number
         q[c]++;
         // If you tried all the numbers, backtrack
         if(q[c]>8){
             c--;
         } 
         // Otherwise, call the ok function. If it returns true, go back to the box part.
         else if(ok(q,c)) break;
         
         // if not ok, continue this loop to try next number
      }
   }
   
   return 0;
}
 
