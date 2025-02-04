#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum = 0;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        sum ^= p;
    }
    if (sum) cout << "koosaga";
    else cout << "cubelover";
}