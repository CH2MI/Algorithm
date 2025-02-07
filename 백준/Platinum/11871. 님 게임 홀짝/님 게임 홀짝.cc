#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        if (p % 2) sum ^= p / 2 + 1;
        else sum ^= p / 2 - 1;
    }
    if (sum) cout << "koosaga";
    else cout << "cubelover";
}