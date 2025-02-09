#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; double S;
    cin >> N >> S >> K;
    double sum = 0;
    int cur = 1;
    cout << fixed;
    cout.precision(12);
    for (int i = 0; i < K; i++) {
        int m; double s;
        cin >> m >> s;
        sum += 60 / (S / 4 / (m - cur));
        S = s;
        cur = m;
    }
    sum += 60 / (S / 4 / (N - cur + 1));

    cout << sum;
}

