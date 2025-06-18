#include <bits/stdc++.h>
using namespace std;

int solve() {
    string s; cin >> s;

    int i = 0;
    int l = s.size();

    while (i < l) {
        if (s[i] == 'p' && s.substr(i, 2) == "pi") i += 2;
        else if (s[i] == 'k' && s.substr(i, 2) == "ka") i += 2;
        else if (s[i] == 'c' && s.substr(i, 3) == "chu") i += 3;
        else return 0;
    }

    return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cout << (solve() ? "YES" : "NO");

}