#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifdef LOCAL_DEBUG
    freopen("input.txt", "r", stdin);
#endif

    string s; cin >> s;

    int N; cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string a; cin >> a;
        a += a;
        cnt += (a.find(s) != string::npos);
    }
    cout << cnt;

}
