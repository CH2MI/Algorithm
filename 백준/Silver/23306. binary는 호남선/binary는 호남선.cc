#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    int l, r;
    cout << "? 1" << endl;
    cin >> l;
    cout << "? " << N << endl;
    cin >> r;

    if (l == r) cout << "! 0" << endl;
    else cout << "! " << (l ? -1 : 1) << endl;
}