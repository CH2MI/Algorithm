#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<bool> v(N, 1);

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == 'O') v[j] = 0;
        }
    }

    int i = 0;
    for (; i < M; i++) {
        if (v[i]) break;
    }
    if (i == M) cout << "ESCAPE FAILED";
    else cout << i + 1;

}