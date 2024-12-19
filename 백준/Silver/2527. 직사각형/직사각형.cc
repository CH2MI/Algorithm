#include <bits/stdc++.h>
using namespace std;

array<int, 4> A, B;

int Solve() {
    if (B[2] < A[0] || A[2] < B[0] || B[3] < A[1] || A[3] < B[1]) return 3;

    if (B[2] == A[0] || B[0] == A[2]) {
        if (A[1] == B[3] || A[3] == B[1]) return 0;
        return 1;
    }
    if (B[3] == A[1] || B[1] == A[3]) {
        return 1;
    }

    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int k = 0; k < 4; k++) {
        for (int& i : A) cin >> i;
        for (int& i : B) cin >> i;

        int ans = Solve();
        if (!ans) cout << 'c';
        else if (ans == 1) cout << 'b';
        else if (ans == 2) cout << 'a';
        else cout << 'd';
        cout << '\n';
    }
}