/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

string add(string small, string big){
    string result="";
    int carry = 0;
    if(small.length() > big.length()){
        string temp= small;
        small = big;
        big = temp;
    }
    
    while (small.length() < big.length()){
        small= "0"+ small;
    }
    
    for (int i= big.length()-1; i >=0 ;i--){
        int value = ((int)big[i] - '0') + ((int)small[i]- '0') + carry;
        if (value < 10){
            result = (char)(value + '0') + result;
            carry = 0;
        }else{
            value = value % 10;
            result = (char)(value+ '0') + result;
            carry = 1;
        }
    }
    if (carry == 1){
        result= (char)(carry + '0') + result;
    }
    return result;
}

int main(){
    cout << add("2345566777844567", "9999988777765768009998") << endl; // 9999991123332545854565
    cout << add("9999988777765768009998", "9999988777765768009998") << endl; // 19999977555531536019996
    cout << add("2345566777844567", "745566777844567") << endl; // 3091133555689134
 
    // write the required loop descripted in the problem statement.
    string small, big;
    while (small != "done"){
        cout<< "Enter Two Numbers" << endl;
        cin >> small;
        cin >> big;
        if(small.length() > 100 ){
            cout<<"Too many digits, enter smaller first value"<< endl;
            cin >> small;
        }else if(big.length() > 100){
            cout<<"Too many digits, enter smaller second value"<< endl;
            cin >> big;
        }
        cout << add(small,big)<< endl;
    }
    
    cout << "End of Program." << endl;


    return 0;
}
