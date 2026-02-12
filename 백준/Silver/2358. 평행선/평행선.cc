#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    unordered_map<int, vector<int>> W, H;

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int w, h; cin >> w >> h;
        W[w].push_back(h);
        H[h].push_back(w);
    }

    int cnt = 0;
    for (auto i : W) {
        cnt += i.second.size() > 1;
    }
    for (auto i : H) {
        cnt += i.second.size() > 1;
    }

    cout << cnt;
}
