#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;
    array<long long, 6> v{};
    for (auto& i : v) cin >> i;

    vector<long long> a{v[0] + v[1] + v[2], v[0] + v[1] + v[3], v[0] + v[4] + v[2], v[0] + v[4] + v[3], v[5] + v[1] + v[2], v[5] + v[1] + v[3], v[5] + v[4] + v[2], v[5] + v[4] + v[3]};
    vector<long long> b;
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (i + j == 5) continue;
            b.push_back(v[i] + v[j]);
        }
    }
    sort(v.begin(), v.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sum = 0;
    if (N == 1) {
        cout << accumulate(v.begin(), v.begin() + 5, 0ll);
    }
    else {
        sum += 4 * a.front();
        sum += 4 * b.front();
        if (N > 2) sum += (N - 2) * (N - 2) * 5 * v.front() + (N - 2) * 8 * b.front() + (N - 2) * 4 * v.front();
        cout << sum;
    }
}