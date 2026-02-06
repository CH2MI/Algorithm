#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;

    vector<int> w, h;

    int T; cin >> T;

    while (T--) {
        int a, b; cin >> a >> b;
        if (!a) h.push_back(b);
        else w.push_back(b);
    }

    w.push_back(0); h.push_back(0);
    w.push_back(N), h.push_back(M);
    sort(w.begin(), w.end());
    sort(h.begin(), h.end());

    int mx = 0;
    for (int i = 1; i < w.size(); i++) {
        for (int j = 1; j < h.size(); j++) {
            mx = max(mx, (w[i] - w[i - 1]) * (h[j] - h[j - 1]));
        }
    }

    cout << mx;
}
