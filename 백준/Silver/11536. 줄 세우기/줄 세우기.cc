#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<string> v(N);
    for (auto& s : v) cin >> s;

    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (v[i] < v[i + 1]) cnt += 1;
        else if (v[i] > v[i + 1]) cnt -= 1;
    }

    if (cnt == N - 1) cout << "INCREASING";
    else if (cnt == -N + 1) cout << "DECREASING";
    else cout << "NEITHER";
}
