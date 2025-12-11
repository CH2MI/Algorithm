#include <bits/stdc++.h>
using namespace std;

void solve(int idx) {
    int N; cin >> N;

    vector<int> v(N * 2);
    for (int& i : v) cin >> i;

    vector<int> ans;
    for (int& i : v) {
        if (!i) continue;
        auto itr = find(v.begin(), v.end(), i / 4 * 3);
        if (itr != v.end()) {
            ans.push_back(*itr);
            *itr = 0;
            i = 0;
        }
    }

    sort(ans.begin(), ans.end());

    cout << "Case #" << idx << ": ";
    for (int i : ans) cout << i << ' ';
    cout << '\n';

}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int T; cin >> T;
    for (int i = 0; i < T; i++) solve(i + 1);
}
