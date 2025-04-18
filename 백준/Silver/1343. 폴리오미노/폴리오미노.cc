#include <bits/stdc++.h>
using namespace std;

string a = "AAAA";
string b = "BB";

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin >> s;
    int cnt = 0;
    string ans;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            if (cnt % 2) {
                cout << -1;
                return 0;
            }

            for (int j = 0; j < cnt / 4; j++) {
                ans += a;
            }
            if (cnt % 4) ans += b;
            ans += '.';
            cnt = 0;
        }
        else cnt++;
    }
    if (cnt % 2) {
        cout << -1;
        return 0;
    }

    for (int j = 0; j < cnt / 4; j++) {
        ans += a;
    }
    if (cnt % 4) ans += b;
    cout << ans;
}
