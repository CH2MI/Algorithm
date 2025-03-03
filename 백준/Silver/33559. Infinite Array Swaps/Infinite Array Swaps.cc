#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    map<int, int> a, b;
    for (int i = 0; i < N; i++) {
        int t; cin >> t;
        a[t]++;
    }
    for (int j = 0; j < N; j++) {
        int t; cin >> t;
        b[t]++;
    }

    int cnt = 0;
    vector<int> A, B;
    for (auto [k, v] : a) {
        auto itr = b.find(k);
        if (itr == b.end()) continue;
        int l = min(v, itr->second);
        for (int i = 0; i < l; i++) {
            ++cnt;
            A.push_back(k); B.push_back(k);
            --a[k]; --itr->second;
        }
    }
    for (auto [k, v] : a) {
        for (int i = 0; i < v; i++) A.push_back(k);
    }
    for (auto [k, v] : b) {
        for (int i = 0; i < v; i++) B.push_back(k);
    }
    cout << cnt << '\n';
    for (auto i : A) cout << i << ' ';
    cout << '\n';
    for (auto i : B) cout << i << ' ';
}