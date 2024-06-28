#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s; cin >> s;
    vector<string> v;
    
    for (int i = 1; i < s.size() - 1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            
            string a(s.substr(0, i)), b(s.substr(i, j - i)), c(s.substr(j));
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            v.push_back(a + b + c);
        }
    }
    
    sort(v.begin(), v.end());
    cout << v[0];
}