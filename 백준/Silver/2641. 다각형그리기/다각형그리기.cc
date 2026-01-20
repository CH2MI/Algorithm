#include <bits/stdc++.h>
using namespace std;

int isEqual(deque<int>& a, deque<int> b) {

    int n = a.size();

    for (int i = 0; i < n; i++) {
        int f = 1;
        for (int j = 0; j < n; j++) {
            if (a[j] != b[j]) f = 0;
        }

        if (f) return 1;
        b.push_back(b.front());
        b.pop_front();
    }

    reverse(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        int f = 1;
        for (int j = 0; j < n; j++) {
            if (a[j] != (b[j] + 1) % 4 + 1) f = 0;
        }

        if (f) return 1;
        b.push_back(b.front());
        b.pop_front();
    }



    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int N; cin >> N;
    deque<int> v(N);
    for (int& i : v) cin >> i;

    vector<deque<int>> ans;

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        deque<int> t(N);
        for (int& j : t) cin >> j;

        if (isEqual(v, t)) ans.push_back(t);

    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) cout << j << ' ';
        cout << '\n';
    }

}
