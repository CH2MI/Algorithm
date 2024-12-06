#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        string s; cin >> s;
        if (s == "#") break;
        int cnt = 0;
        for (int i = 0; i < (int)s.size() - 1; i++) {
            cnt ^= (s[i] - '0');
            cout << s[i];
        }
        if (s.back() == 'e') cout << (cnt == 1);
        else cout << (cnt == 0);
        cout << '\n';
    }
}
