#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int& i : v) cin >> i;

    double mn = DBL_MAX;
    for (int i = K; i <= N; i++) {
        for (int j = 0; j < N - i + 1; j++) {
            double avg = 0;
            for (int k = 0; k < i; k++) avg += v[j + k];
            avg /= i;
            double sum = 0;
            for (int k = 0; k < i; k++) {
                sum += pow(v[j + k] - avg, 2);
            }
            mn = min(mn, sqrt(sum / i));
        }
    }

    cout << fixed << setprecision(10) << mn;
}

