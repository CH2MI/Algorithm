#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v, arr;

set<vector<int>> ans;

void go(int cnt, int cur) {
    if (!cnt) {
        ans.insert(arr);
        return;
    }

    for (int i = cur; i < N; i++) {
        arr.push_back(v[i]);
        go(cnt - 1, i + 1);
        arr.pop_back();
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int M;
    cin >> N >> M;
    v.assign(N, 0);
    for (int& i : v) cin >> i;
    sort(v.begin(), v.end());
    go(M, 0);

    for (auto& a : ans) {
        for (int i : a) cout << i << ' ';
        cout << '\n';
    }
}