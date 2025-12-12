#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int vaild(char c) {
    for (int i = 0; i < 3; i++) {
        if (v[i][0] == c && v[i][1] == c && v[i][2] == c) return 1;
        if (v[0][i] == c && v[1][i] == c && v[2][i] == c) return 1;
    }
    if (v[0][0] == c && v[1][1] == c && v[2][2] == c) return 1;
    if (v[0][2] == c && v[1][1] == c && v[2][0] == c) return 1;
    return 0;
}

void print(int idx) {
    cout << "Case " << idx << ":\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}

void solve(int idx) {
    v.assign(3, {});
    for (auto& s : v) cin >> s;
    char c; cin >> c;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (v[i][j] != '-') continue;
            v[i][j] = c;
            if (vaild(c)) {
                print(idx);
                return;
            }
            v[i][j] = '-';
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int T; cin >> T;
    for (int i = 0; i < T; i++) solve(i + 1);
}
