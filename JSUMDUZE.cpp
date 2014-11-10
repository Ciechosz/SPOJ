/*
JSUMDUZE
Dodawanie
2014-11-10
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main(){

    int t;
    string num1, num2;
    stack<short> result;// cyfry, od koñca
    cin >> t;
    for(;t;--t){
        cin >> num1 >> num2;
        int overflow = 0;

        string::reverse_iterator it1 = num1.rbegin();
        string::reverse_iterator it2 = num2.rbegin();
        while(overflow || it1 != num1.rend() || it2 != num2.rend()){
            short digit1, digit2, resultDigit;
            if( it1 != num1.rend()){
                digit1 = *it1 - '0';
                ++it1;
            }else{
                digit1 = 0;
            }

            if(it2 != num2.rend()){
                digit2 = *it2- '0';
                ++it2;
            }else{
                digit2 = 0;
            }
            //cout << "digit1: "<<digit1 << " digit2: "<<digit2<<endl;
            resultDigit = (digit1 + digit2 + overflow) % 10;

            overflow = (digit1 + digit2 + overflow)/10;
            result.push(resultDigit);
        }
        while(!result.empty()){
            cout << result.top();
            result.pop();
        }
        cout << endl;

    }
    return 0;
}
