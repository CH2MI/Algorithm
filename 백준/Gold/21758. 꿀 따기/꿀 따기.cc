#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    vector<int> ps(N + 1);
    for (int i = 1; i <= N; i++) ps[i] = ps[i - 1] + v[i - 1];

    int mx = 0;

    for (int i = 2; i < N; i++) {
        mx = max(mx, ps[N - 1] + ps[i - 1] - v[i - 1]);
    }
    for (int i = 2; i < N; i++) {
        mx = max(mx, (ps[i] - ps[1]) + (ps[N - 1] - ps[i - 1]));
    }
    for (int i = 2; i < N; i++) {
        mx = max(mx, (ps[N] - ps[1]) + (ps[N] - ps[i]) - v[i - 1]);
    }


    cout << mx;

}