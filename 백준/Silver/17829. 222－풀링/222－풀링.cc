#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> v;

int Recursion(int N, int x, int y) {
    if (N == 1) return v[x][y];

    vector<int> ans;
    ans.push_back(Recursion(N / 2, x, y));
    ans.push_back(Recursion(N / 2, x, y + N / 2));
    ans.push_back(Recursion(N / 2, x + N / 2, y));
    ans.push_back(Recursion(N / 2, x + N / 2, y + N / 2));

    sort(ans.begin(), ans.end());
    return ans[2];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;
    v.assign(N, vector<int>(N));

    for (auto& i : v) for (auto& j : i) cin >> j;

    cout << Recursion(N, 0, 0);
}