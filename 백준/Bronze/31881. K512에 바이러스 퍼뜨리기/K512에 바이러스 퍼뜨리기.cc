#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N, Q; cin >> N >> Q;
    int sum = N;
    vector<int> v(N);
    
    for (int i = 0; i < Q; i++) {
        int a; cin >> a;
        if (a == 1) {
            int x; cin >> x;
            if (!v[x - 1]) sum--;
            v[x - 1] = 1;
        }
        else if (a == 2) {
            int x; cin >> x;
            if (v[x - 1]) sum++;
            v[x - 1] = 0;
        }
        else cout << sum << '\n';
    }
}
