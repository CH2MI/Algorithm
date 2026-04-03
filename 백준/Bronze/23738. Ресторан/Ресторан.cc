#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    string s; cin >> s;

    string ans;
    for (auto c : s) {
        switch (c) {
            case 'B':
                ans += 'v';
            break;
            case 'E':
                ans += "ye";
            break;
            case 'H':
                ans += 'n';
            break;
            case 'P':
                ans += 'r';
            break;
            case 'C':
                ans += 's';
            break;
            case 'Y':
                ans += 'u';
            break;
            case 'X':
                ans += 'h';
            break;
            default:
                ans += c - 'A' + 'a';
            break;
        }
    }
    cout << ans;
}
