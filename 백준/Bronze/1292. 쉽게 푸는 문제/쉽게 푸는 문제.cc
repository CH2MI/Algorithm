#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    vector<int> v;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 0; j < i; j++) v.push_back(i);
    }

    int a, b; cin >> a >> b;
    cout << accumulate(v.begin() + a - 1, v.begin() + b, 0);
}
