#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N; cin >> N;

    vector<long long> v(N);
    for (auto& i : v) cin >> i;
    sort(v.begin(), v.end());

    long long l = v[0], m = v[1], r = v[2];

    for (int i = 0; i < N; i++) {
        vector<long long> tmp; tmp.reserve(N - 1);
        for (int j = 0; j < N; j++) {
            if (i != j) tmp.push_back(v[j]);
        }
        int lo = 0, hi = N - 2;
        int a = 0, b = 1;
        while (lo < hi) {
            long long sum = v[i] + tmp[lo] + tmp[hi];
            if (abs(sum) < abs(v[i] + tmp[a] + tmp[b])) {
                a = lo;
                b = hi;
            }
            if (sum <= 0) lo++;
            if (sum >= 0) hi--;
        }
        if (abs(l + r + m) > abs(tmp[a] + tmp[b] + v[i])) {
            l = tmp[a];
            r = tmp[b];
            m = v[i];
        }
    }
    vector<long long> ans({l, r, m});
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << ' ';
}