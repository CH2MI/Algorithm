#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string s, rs;
        cin >> s;
        rs = s;
        reverse(rs.begin(), rs.end());
        int index = -1;
        
        for (int i = 0; i < s.size(); i++) {
            int j;
            for (j = 0; j < s.size() - i; j++) {
                if (s[j + i] != rs[j])
                    break;
            }
            if (j == s.size() - i) {
                index = i;
                break;
            }
        }
        
        if (index == -1) cout << s + rs << '\n';
        else {
            cout << s;
            for (int i = index - 1; i >= 0; i--) cout << s[i];
            cout << '\n';
        }
        
        
    }
}