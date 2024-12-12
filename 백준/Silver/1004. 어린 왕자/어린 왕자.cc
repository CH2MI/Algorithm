#include <bits/stdc++.h>
using namespace std;

bool isIn(array<int, 2>& a, array<int, 2>& b, int r) {
    int dist = (b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]);
    return dist <= r * r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

   int T; cin >> T;
   while (T--) {
       array<int, 2> s, e;
       cin >> s[0] >> s[1] >> e[0] >> e[1];

       int n, cnt = 0; cin >> n;
       for (int i = 0; i < n; i++) {
           array<int, 2> t; int r;
           cin >> t[0] >> t[1] >> r;
           cnt += isIn(s, t, r) != isIn(e, t, r);
       }
       cout << cnt << '\n';
   }
}