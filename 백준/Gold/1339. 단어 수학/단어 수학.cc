#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<char, long long> m;
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        long long base = 1;
        for (auto itr = s.rbegin(); itr != s.rend(); itr++) {
            m[*itr] += base;
            base *= 10;
        }
    }

    vector<pair<char, long long>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second > b.second; });

    long long sum = 0, weight = 9;
    for (auto [a, b] : v) {
        sum += b * weight;
        weight--;
    }

    cout << sum;
}