#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    if (N == 1) cout << 0;
    else cout << N * N / 2 + N % 2;
}