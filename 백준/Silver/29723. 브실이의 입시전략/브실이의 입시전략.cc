#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;
    unordered_map<string, int> m;
    for (int i = 0; i < N; i++) {
        string a; int b;
        cin >> a >> b;
        m[a] = b;
    }

    int sum = 0;
    for (int i = 0; i < K; i++) {
        string s; cin >> s;
        auto itr = m.find(s);
        sum += itr->second;
        m.erase(itr);
    }

    vector<int> v;
    for (auto& i : m) {
        v.push_back(i.second);
    }

    sort(v.begin(), v.end());

    int mx = sum + accumulate(v.rbegin(), v.rbegin() + M - K, 0);
    int mn = sum + accumulate(v.begin(), v.begin() + M - K, 0);

    cout << mn << ' ' << mx;
}