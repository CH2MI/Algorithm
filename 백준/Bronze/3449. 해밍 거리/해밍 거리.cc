#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    int T; cin >> T;
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;

        int cnt = 0;
        for (int i = 0; i < s1.size(); i++) cnt += (s1[i] != s2[i]);

        cout << "Hamming distance is " << cnt << ".\n";
    }
}
