#include <bits/stdc++.h>
using namespace std;

int arr[26];

void Solve() {
    memset(arr, 0, sizeof(arr));
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        arr[s[i] - 'A']++;
        if (arr[s[i] - 'A'] == 3) {
            if (i == s.size() - 1 || s[i] != s[i + 1]) {
                cout << "FAKE\n";
                return;
            }
            i++;
            arr[s[i] - 'A'] = 0;
        }
    }

    cout << "OK\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        Solve();
    }
}