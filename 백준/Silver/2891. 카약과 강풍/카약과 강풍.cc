#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, S, R; cin >> N >> S >> R;
    vector<int> v(N, 1);

    for (int i = 0; i < S; i++) {
        int s; cin >> s;
        v[s - 1]--;
    }

    for (int i = 0; i < R; i++) {
        int r; cin >> r;
        v[r - 1]++;
    }

    for (int i = 0; i < N; i++) {
        if (v[i] == 2) {
            if (i && !v[i - 1]) {
                v[i - 1] = 1;
                v[i] = 1;
            }
            else if (i != N - 1 && !v[i + 1]) {
                v[i + 1] = 1;
                v[i] = 1;
            }
        }
    }

    cout << count(v.begin(), v.end(), 0);

}