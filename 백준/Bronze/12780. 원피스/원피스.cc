#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    #ifdef LOCAL_DEBUG
        freopen("input.txt", "r", stdin);
    #endif

    string a, b; cin >> a >> b;

    int cnt = 0;
    int s = 0;
    while (s = a.find(b, s) + 1) {
        cnt++;
    }

    cout << cnt;
}
