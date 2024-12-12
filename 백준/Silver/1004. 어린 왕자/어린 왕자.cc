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
       unordered_set<int> S, E;

       int n; cin >> n;
       for (int i = 0; i < n; i++) {
           array<int, 2> t; int r;
           cin >> t[0] >> t[1] >> r;
           if (isIn(s, t, r)) S.insert(i);
           if (isIn(e, t, r)) E.insert(i);
       }

       int cnt = 0;
       for (const int& i : S) cnt += E.find(i) == E.end();
       for (const int& i : E) cnt += S.find(i) == S.end();
       cout << cnt << '\n';
   }
}
