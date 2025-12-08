#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    string s; cin >> s;
    int cnt = 0;
    for (char i : s) {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') cnt++;
    }
    cout << cnt;
}