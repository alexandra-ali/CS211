/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    vector<int> t[3];  
    // t is an array of 3 vectors, each represent a tower
    int n;
    cout << "Please enter the number of rings to move: ";
    cin >> n;
   
    int from = 0;   // set the first “from tower” at index 0, ie. t[0] tower A
    int to; // set the first “to tower” to be the closer tower.
    if(n%2 == 1) to = 1; // if n is odd, we want to put to the right tower first
    else to = 2;   // if n is even, we want to put to the left tower first.
    int candidate = 1;  // the ring id
    int move = 0;
 
    // add a base ring (n+1) to all three towers
    t[0].push_back(n+1);  
    t[1].push_back(n+1);  
    t[2].push_back(n+1);
    // put all the rings to tower 0, (first vector t[0])
    for(int i = n; i >= 1; i--)  t[0].push_back(i); 
 
    // your goal is to move all rings from t[0] to t[1]
    // while t[1] does not contain all of the rings
    while (t[1].size() != n+1) { 
        cout << "\nMove #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A');
    
        // Step 1: Move the ring from "from tower" to the "to tower"
        // ...  // 1. get the ring "from tower", push it to "to tower"
        // ...  // 2. delete that ring from "from tower"
        t[to].push_back(t[from].back());
        t[from].pop_back();
 
        // Step 2a: new "from" = the tower (index) with the smallest ring that is not the previous "to" tower: (to+1)%3 or (to+2)%3
        if (t[(to+1)%3].back()<t[(to+2)%3].back()) 
            from = (to+1)%3;  
        else
            from = (to+2)%3;  
        
        // Step 2b: new candidate = the ring on top of the new "from tower".
        candidate = t[from].back();
        
        // Step 3: new "to" = the tower (index) on which the candidate can be placed: (from+1)%3 or (from+2)%3
        if (n%2 !=0) {  // if n is odd, we want to try move to the right tower first 
            if (candidate > t[(from+1)%3].back())  // if candidate is larger than the top one (back) on the right
                to = (from+2)%3; //set the new "to" to the left tower.
            else
                to = (from+1)%3;//set the new "to" to the right tower
        }
        else {  // if n is even, we want to try move to the left tower first 
             // similiar to above…
             if (candidate > t[(from+2)%3].back())
                to=(from+1)%3;
             else 
                to=(from+2)%3;
        }
    }
    return 0;
}
