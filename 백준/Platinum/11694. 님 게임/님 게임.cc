#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, sum = 0; cin >> N;
    vector<int> v(N);
    for (int& i : v) cin >> i, sum ^= i;
    if (count(v.begin(), v.end(), 1) == N) {
        if (N % 2) cout << "cubelover";
        else cout << "koosaga";
    }
    else {
        if (sum) cout << "koosaga";
        else cout << "cubelover";
    }
}