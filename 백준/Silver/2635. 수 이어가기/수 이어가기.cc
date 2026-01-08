#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    int N; cin >> N;

    vector<int> mx;
    for (int i = 1; i <= N; i++) {
        vector<int> v;
        v.push_back(N); v.push_back(i);

        while (*(v.rbegin() + 1) - *v.rbegin() >= 0) {
            v.push_back(*(v.rbegin() + 1) - *v.rbegin());
        }

        if (mx.size() < v.size()) mx = move(v);
    }

    cout << mx.size() << '\n';
    for (int i : mx) cout << i << ' ';

}
