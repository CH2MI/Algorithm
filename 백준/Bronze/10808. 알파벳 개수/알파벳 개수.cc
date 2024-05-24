#include <iostream>
using namespace std;

int a[26];
int main() {
    string s;
    cin >> s;
    
    for (auto i : s) {
        a[i - 'a']++;
    }
    
    for (int i = 0; i < 26; i++) {
        cout << a[i] << ' ';
    }
}