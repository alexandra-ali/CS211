/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int i= 1;
    while (true){
        int square= i * i;
        int lastDigit= square%10;
        int secondLastDigit= (square/10) % 10;
        if (lastDigit%2 == 1 && secondLastDigit%2 == 1){
            break;
        }
        i++;
    }
    
    cout << i << " "<<i*i<<endl;

    return 0;
}
