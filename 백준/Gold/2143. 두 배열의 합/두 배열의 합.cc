#include <bits/stdc++.h>
using namespace std;

void cal(vector<int>& v, map<int, int>& m) {
    int N = v.size();

    vector<int> ps(N + 1);
    for (int i = 1; i <= N; i++) {
        ps[i] = v[i - 1] + ps[i - 1];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int sum = ps[j + 1] - ps[i];
            m[sum]++;
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T; cin >> T;
    int n; cin >> n;
    vector<int> v1(n);
    for (int& i : v1) cin >> i;
    int m; cin >> m;
    vector<int> v2(m);
    for (int& i : v2) cin >> i;
    map<int, int> m1, m2;
    cal(v1, m1); cal(v2, m2);

    long long cnt = 0;
    for (auto i : m1) {
        int t = T - i.first;
        auto j = m2.find(t);
        if (j != m2.end()) {
            cnt += (long long)i.second * j->second;
        }
    }
    cout << cnt;
}