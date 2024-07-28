#include <iostream>
using namespace std;

int main() {
    int a, ret;
    string input;
    
    while (true) {
        cin >> input;
        if (input == "=") {
            cout << ret;
            break;
        }
        if (input >= "0") a = stoi(input);
        else {
            string b;
            cin >> b;
            if (input == "+") 
                ret = a + stoi(b);
            else if (input == "-") 
                ret = a - stoi(b);
            else if (input == "*") 
                ret = a * stoi(b);
            else
                ret = a / stoi(b);
            a = ret;
        }
        
    }
}