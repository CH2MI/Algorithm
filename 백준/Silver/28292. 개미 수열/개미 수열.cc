#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    if (N < 3) cout << 1;
    else if (N < 6) cout << 2;
    else cout << 3;
}