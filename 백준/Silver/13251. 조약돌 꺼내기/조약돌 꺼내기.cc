#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 0, M, K; cin >> M;
    vector<int> v(M);
    for (int& i : v) cin >> i, N += i;
    cin >> K;
    double p = 0;
    for (int& i : v) {
        if (i < K) continue;
        double t = 1;
        for (int j = 0; j < K; j++) t *= (double)(i - j) / (N - j);
        p += t;
    }
    cout << fixed;
    cout.precision(12);
    cout << p;
}