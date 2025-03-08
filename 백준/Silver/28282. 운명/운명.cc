#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    map<int, int> m1, m2;

    long long X, K; cin >> X >> K;
    for (int i = 0; i < X; i++) {
        int a; cin >> a;
        m1[a]++;
    }
    for (int i = 0; i < X; i++) {
        int a; cin >> a;
        m2[a]++;
    }

    long long sum = 0;
    for (auto [k, v] : m1) {
        if (auto itr = m2.find(k); itr == m2.end()) {
            sum += v * X;
        }
        else {
            sum += v * (X - itr->second);
        }
    }
    cout << sum;
}