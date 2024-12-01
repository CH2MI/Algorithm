#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X; cin >> N >> X;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        sum += p;
    }
    cout << (sum % X == 0);
}