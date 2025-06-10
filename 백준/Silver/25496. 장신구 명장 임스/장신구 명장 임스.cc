#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int P, N; cin >> P >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    sort(v.begin(), v.end());

    int i;
    for (i = 0; i < N && P < 200; i++) {
        if (P < 200) P += v[i];
    }
    cout << i;
}