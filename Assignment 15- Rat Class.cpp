/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
 
class Rat {
    private:
        int n;
        int d;
 
    public:
        // constructors
 
        // default constructor
        Rat() {
            n = 0;
            d = 1;
        }
 
        // 2 parameter constructor
        Rat(int i, int j) {
            n = i;
            d = j;
        }
 
        // conversion constructor
        Rat(int i) {
            n = i;
            d = 1;
        }
 
        // accessor functions (usually called getXX() )
        int getN() { 
            return n; 
        }
        
        int getD() { 
            return d; 
        }
 
        // mutator functions (usually called setXX(...) )
        void setN(int i) { 
            n = i; 
        }
 
        void setD(int i) { 
            d = i; 
        }
 
        // Overloading operator+
        Rat operator+(Rat r) {
            Rat t;
            t.n = n * r.d + d * r.n;
            t.d = d * r.d;
            return t;
        }
 
        // Overloading the other 3 operators (operator-, operator*, operator/).
        Rat operator- (Rat r) {
            Rat t;
            t.n=n*r.d-d*r.n;
            t.d=d*r.d;
            return t;
      
        }
 
        // overload operator* ...
        Rat operator* (Rat r){
            Rat t;
            t.n=n*r.n;
            t.d=d*r.d;
            return t;
        }
        
        
        // overload operator/ ...
        Rat operator/ (Rat r){
            Rat t;
            t.n=n*r.d;
            t.d=d*r.n;
            return t;
        }
        
 
        // The GCD (Euclid's algorithm) finds the largest common divisor
        /* ? ->  conditional ternary operator 
            evaluates an expression, returning one value if that expression evaluates to true
            and a different one if the expression evaluates as false*/
        int gcd(int n, int d) {
            return d == 0 ? n : gcd(d, n%d);
        }
 
        // Write a function to reduce the Rat to lowest terms.
        Rat reduce(Rat r){
            Rat t;
            // 1. Use the GCD function provided above to find the greatest common divisor
            int x= gcd(r.n, r.d);
            // 2. divide both n and d by the number found in step 1
            t.n=r.n/x;
            t.d=r.d/x;
            // 3. also double check if denominator is negative, if so, add negative sign to both n and d
            if(t.d < 0){
                t.n=t.n*-1;
                t.d=t.d*-1;
            }
            return t;
            
        }
        
 
        // 2 overloaded i/o operators
        friend ostream& operator<<(ostream& os, Rat r);
        friend istream& operator>>(istream& is, Rat& r);
}; //end Rat
 
// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts n and d.
ostream& operator<<(ostream& os, Rat r) {
    // Rewrite this function so that improper fractions are printed as mixed numbers.  For example:
    // 3/2 should be printed as 1 1/2
    // 1/2 should be printed as 1/2
    // 2/1 should be printed as 2
    // 0/1 should be printed as 0
    // -3/2 should be printed as -1 1/2
 
   
    // Step 1 : reduce r
    Rat t= r.reduce(r);
    // Step 2 : if n == 0 or d == 1, print n
    if(t.n == 0 || t.d == 1){ 
        cout<< t.n<<endl;
    // Step 3 : else if abs(n) < d (case abs(numerator) < denominator), print n then d
    } else if (abs(t.n) < t.d){
        cout<< t.n <<"/"<< t.d<<endl;
    
    // Step 4 : else (case abs(numerator) >= denominator)
    }else{
        // 4.1: if n is positive, print n/d, then n%d, then d
        if(t.n > 0)
            cout<< t.n/t.d <<" "<<t.n%t.d<<"/"<<t.d<<endl;
        // 4.2: else, print n/d, then -n%d, then d
        else
            cout<< t.n/t.d <<" "<<(t.n%t.d)*-1<<"/"<<t.d<<endl;
    }
 
 
    return os;
}
 
istream& operator>>(istream& is, Rat& r) {
    is >> r.n >> r.d;
    return is;
}
 
int main() {
    Rat r1(5, 2), r2(3, 2);
 
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
 
    r1 = r2;
    r2 = r1 * r2;
 
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
    cout << endl;
 
    r1 = r2 + r1 * r2 / r1;
    r2 = r2 + r1 * r2 / r1;
 
    cout << "r1: " << r1 << endl;
    cout << "r2: " << r2 << endl;
    cout << "r1 + r2: " << r1 + r2 << endl;
    cout << "r1 - r2: " << r1 - r2 << endl;
    cout << "r1 * r2: " << r1 * r2 << endl;
    cout << "r1 / r2: " << r1 / r2 << endl;
 
    return 0;
}

