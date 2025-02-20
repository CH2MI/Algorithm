#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int z = 0, o = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] != s[i]) {
            if (s[i - 1] == '0') z++;
            else o++;
        }
    }
    if (s.back() == '0') z++;
    else o++;
    cout << min(z, o);
}