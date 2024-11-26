#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    if (s.size() == 2) cout << s[0] - '0' + s[1] - '0';
    else if (s.size() == 3) {
        int a = stoi(s.substr(0, 2));
        if (a == 10) {
            cout << a + s[2] - '0';
        }
        else {
            cout << s[0] - '0' + stoi(s.substr(1, 2));
        }
    }
    else cout << 20;
}