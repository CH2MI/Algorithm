#include <bits/stdc++.h>
using namespace std;

int K;
vector<int> v;
vector<vector<int>> ans;

void recursion(int s, int e, int level) {
    if (level == K) return;
    int m = (s + e) / 2;
    ans[level].push_back(v[m]);
    recursion(s, m, level + 1); recursion(m + 1, e, level + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    v.assign((int)pow(2, K) - 1, 0);
    ans.assign(K, vector<int>());
    for (int& i : v) cin >> i;
    recursion(0, pow(2, K) - 1, 0);

    for (auto& i : ans) {
        for (int& j : i) cout << j << ' ';
        cout << '\n';
    }
}