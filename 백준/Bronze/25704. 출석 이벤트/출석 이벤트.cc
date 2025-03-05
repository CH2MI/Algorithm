#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, P; cin >> N >> P;
    float mx = 0;
    if (N >= 20) mx = max(mx, P * 0.25f);
    if (N >= 15) mx = max(mx, 2000.0f);
    if (N >= 10) mx = max(mx, P * 0.1f);
    if (N >= 5) mx = max(mx, 500.0f);

    cout << max(0, P - (int)mx);
}