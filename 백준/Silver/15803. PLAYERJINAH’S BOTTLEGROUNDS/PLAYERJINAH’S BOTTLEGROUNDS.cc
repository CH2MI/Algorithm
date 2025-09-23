#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<array<int, 2>> v(3);
    for (auto& [a, b] : v) cin >> a >> b;

    int ans = v[0][0] * v[1][1] + v[1][0] * v[2][1] + v[2][0] * v[0][1] - (v[1][0] * v[0][1] + v[2][0] * v[1][1] + v[0][0] * v[2][1]);
    if (ans) cout << "WINNER WINNER CHICKEN DINNER!";
    else cout << "WHERE IS MY CHICKEN?";
}
