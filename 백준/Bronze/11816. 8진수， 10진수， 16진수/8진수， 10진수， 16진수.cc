#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin >> s;
    if (s.size() > 2 && s.substr(0, 2) == "0x") {
        cout << stoi(s, nullptr, 16);
    }
    else if (s.size() > 1 && s[0] == '0') {
        cout << stoi(s, nullptr, 8);
    }
    else cout << s;
}
