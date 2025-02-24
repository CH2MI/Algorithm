#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T, N; cin >> T >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int f; cin >> f;
        sum += f;
    }
    if (sum >= T) cout << "Padaeng_i Happy";
    else cout << "Padaeng_i Cry";
}