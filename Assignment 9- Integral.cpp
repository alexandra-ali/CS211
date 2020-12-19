#include <iostream>
using namespace std;
 
typedef double (*FUNC) (double);
 
// Returns the area under the curve between x=a and x=b.
// The function passed as the first parameter determines the shape of the curve.
// Use Riemann sum to estimate the area by dividing it into narrow rectangles
// (each rectangle should have a width of .0001)
// and adding up the areas of the individual rectangles.
// For a rectangle at horizontal position x, the height will be f(x).
// (when you call f(x) it'll call whatever function you passed as the first parameter)
double integrate(FUNC f, double a, double b) {
    // loop x from a to b, each time x increments by the width of the rectangle, i.e. 0.0001
        // area += height * width, 
        // where width = 0.0001, height = f(x) <= here choose the midpoint f(x+0.0001/2) is more accurate
    // return area;
    double s= 0;
    double delta= .0001;
    double x=a;
    while(x<b){
        s+= delta * f(x+0.0001/2);
        x= x+delta;
    }
    return s;
}
 
double line(double x) {
   return x;
}
 
double square(double x) {  
   return x*x;
}
 
double cube(double x) { 
   return x*x*x;
}
 
int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;   // output: 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // output: 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // output: 156
   return 0;
}
 
