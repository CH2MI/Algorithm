#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    cout << max({A + B, B + C, A + C});
}