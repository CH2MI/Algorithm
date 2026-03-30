#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    vector<char> v(N);
    for (auto& c : v) cin >> c;

    int m, k; cin >> m >> k;

    unordered_set<char> st;
    for (int i = 0; i < m; i++) {
        bool w = true;
        for (int j = 0; j < k; j++) {
            int idx; cin >> idx;
            if (v[idx - 1] == 'P') w = false;
        }

        if (w) st.insert('W');
        else st.insert('P');
    }
    if (st.find('W') == st.end()) cout << 'P';
    else cout << 'W';

}
