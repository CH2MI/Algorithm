#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin >> s;
    int i = 0, N = 1;
    while (i < s.size()) {
        string n = to_string(N);

        for (int j = 0; j < n.size(); j++) {
            if (s[i] == n[j]) {
                if (++i == s.size()) {
                    break;
                }
            }
        }
        N++;
    }

    cout << N - 1;
}