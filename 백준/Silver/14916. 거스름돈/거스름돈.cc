#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  
  int n; cin >> n;
  int mn = INT_MAX;
  for (int i = 0; i <= n; i += 5) {
    int j = n - i;
    if (j % 2) continue;
    mn = min(mn, i / 5 + j / 2);
  }
  
  if (mn == INT_MAX) cout << -1;
  else cout << mn;
}