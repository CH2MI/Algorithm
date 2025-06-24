#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N; cin >> N;

    for (int i = 1; i <= N; i += 2) cout << i << ' ';
    for (int i = N - (N % 2); i > 0; i -= 2) cout << i << ' ';
}