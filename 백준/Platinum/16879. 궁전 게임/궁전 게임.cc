#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[3][3] = {{0, 1, 2}, {1, 2, 0}, {2, 0, 1}};

    int N; cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        sum ^= ((x / 3) ^ (y / 3)) * 3 + a[x % 3][y % 3];
    }
    if (sum) cout << "koosaga";
    else cout << "cubelover";
}