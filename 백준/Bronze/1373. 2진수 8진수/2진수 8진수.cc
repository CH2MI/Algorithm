#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int i = 0;
    if (s.size() % 3 == 1) {
        cout << s[i++];
    }
    else if (s.size() % 3 == 2) {
        cout << (s[i] - '0') * 2 + s[i + 1] - '0';
        i += 2;
    }
    
    for (; i < s.size(); i += 3) {
        cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + s[i + 2] - '0';
    }
}