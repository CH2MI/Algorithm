#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int N; cin >> N;
    string s; cin >> s;

    string ans;
    for (auto c : s) {
        if (c != 'J' && c != 'A' && c != 'V') ans += c;
    }

    if (ans.empty()) cout << "nojava";
    else cout << ans;
}

