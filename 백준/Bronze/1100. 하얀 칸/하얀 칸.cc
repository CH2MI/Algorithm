#include <iostream>
using namespace std;

int count(string s, int k) {
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == k) {
            if (s[i] == 'F') cnt++;
        } 
    }
    return cnt;
}

int main() {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        cnt += count(s, i % 2);
    }    
    cout << cnt;
}