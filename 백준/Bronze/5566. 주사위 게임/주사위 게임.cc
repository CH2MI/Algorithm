#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    int p = 1;
    int i;
    for (i = 0; i < M && p <= N; i++) {
        int d; cin >> d;
        p += d;
        p += v[p];
    }
    cout << i;
}