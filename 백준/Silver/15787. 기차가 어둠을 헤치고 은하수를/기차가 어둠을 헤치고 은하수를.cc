#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;
    vector<array<int, 20>> v(N);

    for (int i = 0; i < M; i++) {
        int q; cin >> q;
        if (q == 1) {
            int a, b; cin >> a >> b;
            v[a - 1][b - 1] = 1;
        }
        else if (q == 2) {
            int a, b; cin >> a >> b;
            v[a - 1][b - 1] = 0;

        }
        else if (q == 3) {
            int a; cin >> a;
            auto itr = v[a - 1].rbegin();
            for (; itr + 1 != v[a - 1].rend(); itr++) {
                *itr = *(itr + 1);
            }
            *itr = 0;
        }
        else {
            int a; cin >> a;
            auto itr = v[a - 1].begin();
            for (; itr + 1 != v[a - 1].end(); itr++) {
                *itr = *(itr + 1);
            }
            *itr = 0;
        }
    }

    set<array<int, 20>> st;
    for (auto& i : v) st.insert(i);
    cout << st.size();
}
