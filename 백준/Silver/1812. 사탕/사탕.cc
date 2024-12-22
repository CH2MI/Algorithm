#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v, ans;

bool solve(int a) {
    ans[0] = a;
    for (int i = 1; i < N; i++) {
        ans[i] = v[i - 1] - ans[i - 1];
        if (ans[i] < 0) return 0;
    }
    return v[N - 1] == ans[0] + ans[N - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    v.assign(N, 0);
    ans.assign(N, 0);
    for (int& i : v) cin >> i;

    for (int i = 0; i <= v[0]; i++) {
        if (solve(i)) break;
    }
    for (int& i : ans) cout << i << '\n';
}