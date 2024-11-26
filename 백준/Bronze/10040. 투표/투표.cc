#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> v(N), ans(N);
    for (int& i : v) cin >> i;

    for (int i = 0; i < M; i++) {
        int t; cin >> t;
        for (int j = 0; j < N; j++) {
            if (v[j] <= t) {
                ans[j]++;
                break;
            }
        }
    }
    cout << max_element(ans.begin(), ans.end()) - ans.begin() + 1;
}