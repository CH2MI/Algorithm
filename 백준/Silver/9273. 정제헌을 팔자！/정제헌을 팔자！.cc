#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    while (cin >> s) {
        int n = stoi(s.substr(2));
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++) if (!(n * i % (i - n))) cnt++;
        cout << cnt << '\n';
    }
}
