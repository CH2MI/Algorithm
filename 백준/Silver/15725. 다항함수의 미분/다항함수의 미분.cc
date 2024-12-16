#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    if (s[0] == 'x') cout << 1;
    else if (s[0] == '-' && s[1] == 'x') cout << -1;
    else if (s.find('x') == string::npos) cout << 0;
    else {
        string ans;
        int i = 0;
        while (s[i] != 'x') ans += s[i++];
        cout << ans;
    }
}