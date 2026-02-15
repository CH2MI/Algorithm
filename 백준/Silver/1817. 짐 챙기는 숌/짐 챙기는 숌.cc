#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, M; cin >> N >> M;
    vector<int> v;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;

        if (!v.empty() && v.back() + a <= M) v.back() += a;
        else v.push_back(a);
    }

    cout << v.size();
}
