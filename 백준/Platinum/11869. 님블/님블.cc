#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        sum ^= p;
    }
    if (sum) cout << "koosaga";
    else cout << "cubelover";
}