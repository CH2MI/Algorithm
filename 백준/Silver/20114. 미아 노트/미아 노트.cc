#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, H, W;
    cin >> N >> H >> W;
    vector<char> v(N, '?');

    for (int i = 0; i < H; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < W; k++) {
                if (s[j * W + k] != '?') v[j] = s[j * W + k];;
            }
        }
    }
    for (auto c : v) cout << c;

}