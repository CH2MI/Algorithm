#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    string mn = "zzz";
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (s.size() == 3) {
            mn = min(mn, s);
        }
    }
    cout << mn;
}