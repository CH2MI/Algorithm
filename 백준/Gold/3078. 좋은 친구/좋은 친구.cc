#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K; cin >> N >> K;

    vector<string> v(N);
    vector<vector<int>> db(21);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        db[v[i].size()].push_back(i);
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int l = v[i].size();
        sum += upper_bound(db[l].begin(), db[l].end(), i + K) - lower_bound(db[l].begin(), db[l].end(), i) - 1;
    }
    cout << sum;
}